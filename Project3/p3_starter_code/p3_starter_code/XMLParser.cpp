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
	//stringStart will hold index of first non-whitespace character
	//currentChar holds the character of the string during each loop iteration
	int stringStart=0;
	char currentChar=inputString[stringStart];
	int vectorCount=0; //used to index the token vector
	char firstChar; //firstChar holds char after first '<' to find "</" end tag or "<?" declaration
	char lastChar; //lastChar holds char before '>' to find "/>" empty tag or "?>" declaration

	//Check first non-whitespace character
	while(currentChar==' ' && currentChar!='<')
	{
		stringStart++;
		currentChar=inputString[stringStart];
	}
	
	//if first char isn't '<', return false
	if (currentChar!='<')
	{
		tokenizedInputVector.clear();
		return false;
	}
	
	//Read entire string
	for (int i=stringStart; i<=inputString.length()-1; i++)
	{
		//store char from input
		currentChar=inputString[i];
		//^^^store char from input string^^^

		//if currentChar!='<', token is content
		if (currentChar!='<')
		{
			//create a new TokenStruct
			TokenStruct* currentTokenStruct=new TokenStruct;
			tokenizedInputVector.push_back(*currentTokenStruct); //push back new TokenStruct to the tokenVector
			tokenizedInputVector[vectorCount].tokenType=DECLARATION; //set token type to declaration

			//Loop through until end of content is reached (when new tag starts with '<')
			while(currentChar!='<')
			{
				//check for missing end tag at end of string, or whitespace
				if (i>=inputString.length())
				{
					//loop through tokenString for content, check for non whitespace
					for (int k=0; k<=tokenizedInputVector[vectorCount].tokenString.length()-1; k++)
					{
						currentChar=tokenizedInputVector[vectorCount].tokenString[k];
						
						if(currentChar!=' ')
						{
							tokenizedInputVector.clear();
							return false;
						}
					}
					return true;
				}
				
				tokenizedInputVector[vectorCount].tokenString.push_back(currentChar); //push char onto content tokenString
				i++; //increment i
				currentChar=inputString[i]; //currentChar=next char in inputString
			}

			//increase vectorCount
			vectorCount++;
		}

		//check if the currentChar is the beginning of a tag
		if (currentChar=='<')
		{
			//create a new TokenStruct
			TokenStruct* currentTokenStruct=new TokenStruct;
			tokenizedInputVector.push_back(*currentTokenStruct); //push back new TokenStruct to the tokenVector
			tokenizedInputVector[vectorCount].tokenType=START_TAG; //Set tag type to start
			i++; //increment i to exclude '<' from the token
			currentChar=inputString[i];
			firstChar=inputString[i]; //store first char after '<'

			//check for end tag "</"
			if(firstChar=='/')
			{
				tokenizedInputVector[vectorCount].tokenType=END_TAG; 
				i++; //increment i to exclude '/' from token
				currentChar=inputString[i];
			}

			//Loop through the rest of the tag until '>' is reached
			while(currentChar!='>')
			{
				//check for invalid nested '<'
				if (currentChar=='<')
				{
					tokenizedInputVector.clear();
					return false;
				}
				
				tokenizedInputVector[vectorCount].tokenString.push_back(currentChar); //push currentChar onto the tokenString
				lastChar=currentChar; //previousChar will hold char before '>' at end of loop
				i++; //increment i
				currentChar=inputString[i]; //set currentChar to the next char in the string

				//check for missing end tag at end of string
				if (i>=inputString.length()-1 && currentChar!='>')
				{
					tokenizedInputVector.clear();
					return false;
				}
			}

			//Check for empty tag "/>"
			if(lastChar=='/')
			{
				tokenizedInputVector[vectorCount].tokenType=EMPTY_TAG;
				tokenizedInputVector[vectorCount].tokenString.pop_back(); //remove '/' from tag
			}

			//Check for declaration
			if(firstChar=='?' && lastChar=='?')
			{
				tokenizedInputVector[vectorCount].tokenType=DECLARATION;
				tokenizedInputVector[vectorCount].tokenString.pop_back(); //remove first '?' from tag
				tokenizedInputVector[vectorCount].tokenString.erase(0, 1); //remove last '?' from tag
			}

			//Increment vectorCount, (end of current token reached)
			vectorCount++;		
		}
	}

	return true;
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

