#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE("Constructor, number, and add Test", "[FindPalindrome]" )
{
	/*//create Palindrome object
	FindPalindrome set1;
	set1.clear();

	//Require that the number of palindromes is zero
	REQUIRE(set1.number()==0);

	//Add string to set1
		set1.add("test");

	//Require that adding unallowable strings returns false
	REQUIRE(set1.add("1")==false);
	REQUIRE(set1.add("$")==false);
	REQUIRE(set1.add("Test")==false);

	//Create new vector
	std::vector<std::string> stringVector1={"stringOne", "stringTwo"};

	//Require that adding vectors works properly
	REQUIRE(set1.add(stringVector1)==true);

	//Create new vector with repeated element
	stringVector1={"stringTwo", "stringThree"};

	//Require that adding repeated vector returns false
	REQUIRE(set1.add(stringVector1)==false);

	//Test other unallowable vectors
	stringVector1={"$", "aaa"};
	REQUIRE(set1.add(stringVector1)==false);
	stringVector1={"aaa", "bbb", "123"};
	REQUIRE(set1.add(stringVector1)==false);*/
}

TEST_CASE( "Test recursiveFindPalindrome with add", "[FindPalindrome]" )
{
	//create FindPalindrome object
	FindPalindrome set1;

	//create vector 
	std::vector<std::string> vect1={"aaa", "aaa", "aaa"};

	//Test recursive call
	set1.add(vect1);

	//Require that number of palindromes is zero, and that palindromeVector is empty
	REQUIRE(set1.number()==2);
	//REQUIRE()
}

