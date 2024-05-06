/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
	ASSERT_TRUE(1 == 1);
}


TEST(PasswordTest, pass_length)
{
	Password my_password;
	// int actual = my_password.count_leading_characters("Z");
	bool actual = my_password.pass_length();
	my_password.pass_length();
	ASSERT_EQ(1, actual);
}
#if 1 == 2
TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}
#endif

TEST(PasswordTest, leading_char)
{
	Password my_password;
	// int actual = my_password.count_leading_characters("Z");
	bool actual = my_password.count_leading_characters();
	ASSERT_EQ(1, actual);
}
#if 1==2
TEST(PasswordTest, short_mixed_case_1)
{
	Password pass;
	ASSERT_TRUE(pass.has_mixed_case("zH")); // Lower, Upper
}
#endif

TEST(PasswordTest, short_mixed_case_2)
{
	Password pass;
	ASSERT_TRUE(pass.has_mixed_case()); // Upper, Lower
}