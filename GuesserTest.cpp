/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

#include <iostream>

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


// This should pass. Password should pass if it's the right password
TEST(GuesserTest, pass_same)
{
	Guesser guess_test("AabB1234 !@ #keazZnaa");
	std::string over_32 = "AabB1234 !@ #keazZnaa";
	bool b_test = guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	ASSERT_TRUE(b_test);
}

// This should fail - Length test too high
TEST(GuesserTest, pass_long)
{
	Guesser guess_test("AabB1234 !@ #keazZnaa");
	std::string over_32 = "AabB1234 !@ #keazZnaa6789123456789123456789";
	bool b_test = guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	ASSERT_FALSE(b_test);
}
// This should fail - Length test too low
TEST(GuesserTest, pass_short)
{
	Guesser guess_test("AabB1234 !@ #keazZnaa");
	std::string over_32 = "AabB1";
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	bool b_test = guess_test.match(over_32);
	ASSERT_FALSE(b_test);
}

// This should pass - Testing not double counting on too low
TEST(GuesserTest, pass_short_diff)
{
	Guesser guess_test("Aab");
	std::string over_32 = "bb";
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	guess_test.match(over_32);
	ASSERT_EQ(3, guess_test.remaining());
}

// Three Wrong Tests
TEST(GuesserTest, pass_four_tests)
{
	std::string pass = "Aa";
	Guesser guess_test(pass);
	std::string over_32 = "Aab";
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	// Expects three wrong, as once 3 it stops adding to the wrong
	ASSERT_EQ(3, guess_test.remaining());
}

// Two wrong, one right, two wrong
TEST(GuesserTest, pass_twofail)
{
	std::string pass = "Aa";
	Guesser guess_test(pass);
	std::string over_32 = "Aab";
	// Two wrong
	guess_test.match(over_32);
	guess_test.match(over_32);
	// One Right
	guess_test.match(pass);
	// Two wrong
	guess_test.match(over_32);
	guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';

	ASSERT_EQ(2, guess_test.remaining());
}

// Three Wrong, One Right, Should Fail
TEST(GuesserTest, pass_lockedout)
{
	std::string pass = "Aa";
	Guesser guess_test(pass);
	std::string over_32 = "Aab";
	// Three wrong, should lock
	guess_test.match(over_32);
	guess_test.match(over_32);
	guess_test.match(over_32);
	// One Right
	bool check = guess_test.match(pass);
	ASSERT_FALSE(check);
}
// With a zero input, things get weird. Null check will fail, in part because of the overflow check
// This also helps with 100% test coverage
TEST(GuesserTest, pass_null)
{
	std::string pass = "";
	Guesser guess_test(pass);
	std::string over_32 = "5";
	// Three wrong, should lock but won't
	guess_test.match(over_32);
	guess_test.match(over_32);
	guess_test.match(over_32);
	// std::cout << "Remaining chances: " << guess_test.remaining() << '\n';
	// One Right
	bool check = guess_test.match(pass);
	ASSERT_FALSE(check);
}