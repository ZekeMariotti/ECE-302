#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE("Constructor, number, and add Test", "[FindPalindrome]" )
{
	//create Palindrome object
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
	REQUIRE(set1.add("one two")==false);

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
	REQUIRE(set1.add(stringVector1)==false);
	stringVector1={"aaa", "bbb", "one two"};
	REQUIRE(set1.add(stringVector1)==false);
}

TEST_CASE( "Test cutTests, clear, recursiveFindPalindrome with add, and toVector", "[FindPalindrome]" )
{
	//create FindPalindrome object
	FindPalindrome set1;

	//create vector 
	std::vector<std::string> vect1={"aab", "A", "Baa"};

	//Test recursive call
	set1.add(vect1); 

	//Require that number of palindromes is two, and test palindrome output vector
	REQUIRE(set1.number()==2);
	std::vector< std::vector<std::string>> pVect=set1.toVector();
	std::vector<std::string> vect2={"Baa", "A", "aab"};
	REQUIRE(pVect[0]==vect1);
	REQUIRE(pVect[1]==vect2);

	//Test palindromes with different number of words
	FindPalindrome set2;
	set2.add("a");
	REQUIRE(set2.number()==1);
	set2.add("aa");
	REQUIRE(set2.number()==2);
	set2.add("aaa");
	REQUIRE(set2.number()==6);

	//Test clear
	set2.clear();
	REQUIRE(set2.number()==0);

	//Cut1 Test
	FindPalindrome set3;

	//cutTest has odd number of 'b's and 'c's
	std::vector<std::string> cutTest={"aba", "aca"};
	REQUIRE(set3.cutTest1(cutTest)==false);

	//cutTest has only one character with an odd frequency
	cutTest={"aabbcc", "deeff"};
	REQUIRE(set3.cutTest1(cutTest)==true);

	//Cut2 test, cutTestTwo holds same number of identical elements as cutTest, should pass cutTest2
	cutTest={"aba", "aca"};
	std::vector<std::string> cutTestTwo={"aab", "caa"};
	REQUIRE(set3.cutTest2(cutTest, cutTestTwo)==true);

	//cutTestTwo doesn't hold all elements of cutTest, should fail cutTeset2
	cutTestTwo={"zyx", "f", "ghi"};
	REQUIRE(set3.cutTest2(cutTest, cutTestTwo)==false);
}

