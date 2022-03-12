#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here

TEST_CASE( "Test Bag add", "[XMLParser]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack", "[XMLParser]" )
{
	   Stack<int> testStack;

	   //test that default stack is empty 
	   REQUIRE(testStack.isEmpty());
	   
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
			REQUIRE(intStack.peek()==i);
		}

		//Testing pop
		REQUIRE(intStack.pop());
		REQUIRE(intStack.peek()==1);
		REQUIRE(intStack.size()==2);

		//Testing Clear
		intStack.clear();
		REQUIRE(intStack.isEmpty());
}

TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);

		//test invalid cases, and cases with whitespace
		XMLParser parserTwo;
		testString = "thisIsAnInvalidString";
		REQUIRE(parserTwo.tokenizeInputString(testString)==false);

		XMLParser parserThree;
		testString = "<<test>";
		REQUIRE(parserThree.tokenizeInputString(testString)==false);

		XMLParser parserFour;
		testString = "         <test>   d  <test>    ";
		REQUIRE(parserFour.tokenizeInputString(testString)==true);

		XMLParser parserFive;
		testString = "<test> d ";
		REQUIRE(parserFive.tokenizeInputString(testString)==false);

		XMLParser parserSix;
		testString = "<test><";
		REQUIRE(parserSix.tokenizeInputString(testString)==false);

		XMLParser parserSeven;
		testString = "<test/>";
		REQUIRE(parserSeven.tokenizeInputString(testString)==true);

		XMLParser parserEight;
		testString = "<?test?>";
		REQUIRE(parserEight.tokenizeInputString(testString)==true);

		//Test parser
		XMLParser parserNine;
		testString = "<test attributes here> </test>";
		REQUIRE(parserNine.tokenizeInputString(testString)==true);
		REQUIRE(parserNine.parseTokenizedInput()==true);

		XMLParser parserTen;
		testString = "<test!@#$%^&*>";
		REQUIRE(parserTen.tokenizeInputString(testString)==true);
		REQUIRE(parserTen.parseTokenizedInput()==false);
		
		XMLParser parserEleven;
		testString = "<?tagNameTest attributesListedHere:?><tagNameTest/><tagNameTest/>";
		REQUIRE(parserEleven.tokenizeInputString(testString)==true);
		REQUIRE(parserEleven.parseTokenizedInput()==true);
		REQUIRE(parserEleven.containsElementName("tagNameTest")==true);
		REQUIRE(parserEleven.frequencyElementName("tagNameTest")==3);

		//Testing input file
		XMLParser parserTwelve;
		ifstream infile("TestFile.txt");
		string inString, fullString;

		ofstream outfile("Test_Output_File.txt");

		//Get input string
		while(!infile.eof())
		{
			getline(infile, inString);
			fullString.append(inString);
		}

		// Output file created to ensure file read in correctly
		outfile << fullString;	

		//Test input string
		REQUIRE(parserTwelve.tokenizeInputString(fullString)==true);
		REQUIRE(parserTwelve.parseTokenizedInput()==true);
		
}

