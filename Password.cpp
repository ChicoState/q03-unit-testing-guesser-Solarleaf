#include "Password.h"
#include <string>
#include <cctype>

using std::string;


// Length
bool Password::pass_length() {
  string phrase = pass_history.back();
  return (phrase.length() >= 8 && phrase.length() <= 20);
}

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(){
  string phrase = pass_history.back();
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return (repetition<=2);
}

Password::Password() {
  pass_history.push_back("ChicoCA-95929");
}

void Password::set(string input) {
  int check{0};
  check+=Password::has_mixed_case();
}

bool Password::authenticate(string input) {
  int check[0];
  return true;
}

// Implementation A
#if 1==1
bool Password::has_mixed_case()
{
  string phrase = pass_history.back();
  string str = phrase;
  bool has_lower = false;
  bool has_upper = false;
  for (char ch : str)
  {
    if (std::islower(ch))
    {
      has_lower = true;
    }
    else if (std::isupper(ch))
    {
      has_upper = true;
    }
  }
  return has_lower && has_upper;
}

#endif

// Implementation B
#if 1==2
bool Password::has_mixed_case(string str)
{
  int count_lower = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      count_lower++;
    }
  }
  return count_lower > 0 && count_lower < str.length();
}

#endif

// Implementation C
#if 1==2
bool Password::has_mixed_case(string str)
{
  bool lower = false;
  bool upper = false;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      lower = true;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      upper = true;
    }
  }
  return upper && lower;
}
#endif

// Implementation D
#if 1==2
bool Password::has_mixed_case(string str)
{
  bool is_lower = false;
  bool is_upper = false;
  for (char c : str)
  {
    if (std::islower(c))
    {
      is_lower = true;
    }
    else
    {
      is_upper = true;
    }
  }
  return is_lower && is_upper;
}
#endif
// Implementation E
#if 1==2
// Implementation E
bool Password::has_mixed_case(string str)
{
  bool found = false;
  for (char c : str)
  {
    if (!found && c >= 'A' && c <= 'Z')
    {
      found = true;
    }
    else if (found && c >= 'a' && c <= 'z')
    {
      return true;
    }
  }
  return false;
}
#endif