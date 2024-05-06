#include "Guesser.h"
#include <string>

#include <iostream>

using std::string;

/*
  Returns an whole number representing the distance between the guess,
  provided as an argument, and the secret. The distance represents the number
  of characters that would have to be changed at the same location to match
  the other string. When the two strings are identical, the distance is 0,
  but for each letter different, the distance increases by 1. When the
  strings are different lengths, each of the extra characters in the longer
  string also counts as an increase in 1 to the distance, up to the length of
  the secret; in other words, if m_secret has a 10 characters and the guess
  has 100, the distance is 10.
*/

// PRIVATE
unsigned int Guesser::distance(string guess)
{
  // Checks difference in length
  int counter{0};
  size_t l_guess = guess.length();
  size_t l_secret = m_secret.length();
  counter = abs(l_guess - l_secret);
  if (l_guess > l_secret)
  {
    guess = guess.substr(0, l_secret);
  }
  // Checks difference in character
  // The check for both makes it so if the guess is shorter not double penalized for diff letters
  for (size_t k = 0; k < l_guess && k < l_secret; k++)
  {
    if (m_secret[k] == guess[k])
    {
      continue;
    }
    ++counter;
  }
  if(counter > l_secret) {
    counter = l_secret;
  }
  return counter;
}

/*
  Constructor requires that the secret phrase is provided its value as
  an argument. This secret will not change for the lifespan of an instance
  of any Guesser object and must have a length of 32 characters or less,
  otherwise, it will be truncated at that length.
*/

Guesser::Guesser(string secret){
  m_remaining = 0;
  m_secret = secret;
  // m_secret = "AabB1234!@#keazZ\naa";
}

/*
  Determines and returns whether the provided guess matches the secret
  phrase. However, the function also returns false if the secret is locked,
  which happens if either (or both): 
    (A) there are no remaining guesses allowed
    (B) the function detects brute force, as indicated by a guess that has a
        distance greater than 2 from the secret
  See the remaining() and distance() functions for specifications regarding
  determining how many guesses are remaining and the distance between a guess
  and the secret.
*/
bool Guesser::match(string guess){
  // We don't want a count down because m_remaining is an unsigned, so you could have an overflow
  // Which would give you a lot of guesses

  if (remaining() >= 3)
  {
    return false;
  }
  else if (guess == m_secret)
  {
    m_remaining = 0;
    return true;
  }
  // This is the null check and the overflow check
  int temp = remaining();
  m_remaining += distance(guess);
  if (temp >= m_remaining || temp < 0)
  {
    m_remaining = 5;
    // std::cerr<<"Something went wrong\n";
  }
  return false;
}

/*
  Returns the number of guesses remaining. A Guesser object allows up to
  three (3) consecutive guesses without a match. If three guesses are made
  without any being a true match, the secret is locked. However, whenever
  an unlocked secret is guessed with a true match, the guesses remaining
  reset to three (3).
*/
unsigned int Guesser::remaining(){
  return m_remaining;
}

