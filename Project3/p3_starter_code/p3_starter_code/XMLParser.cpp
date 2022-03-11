// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
}  // end destructor

// Reads in an input string, stores entire string as tokens, returns true if all the markup/tag
// tokens are valid (markup/tag = characters inside <> delimiters)
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	//stringStart is index of first non-whitespace character
	//currentChar holds the character of the string during each loop iteration
	int stringStart=0;
	char currentChar=inputString[stringStart];

	//Check first non-whitespace character
	while(currentChar==' ' && currentChar!='<')
	{
		stringStart++;
		currentChar=inputString[stringStart];
	}
	
	//if first char isn't '<', return false
	if (currentChar!='<')
		return false;
	
	//Read entire string
	for (int i=0; i<=inputString.length(); i++)
	{
		//Read each character, assign token type, store it, check if its valid
	}
	
	return false;
}  // end tokenizeInputString

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}

