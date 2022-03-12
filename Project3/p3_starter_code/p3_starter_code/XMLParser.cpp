// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include <cctype>
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
	
	//Read entire input string
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
			tokenizedInputVector[vectorCount].tokenType=CONTENT; //set token type to declaration

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

			//Check for invalid tag type of </element/> not empty, not end tag
			if (firstChar=='/' && lastChar=='/')
			{
				//This error should be handled in the parser, not when it is tokenized (/ will be part of an invalid tag name)
				tokenizedInputVector[vectorCount].tokenString.push_back(lastChar); //add '/' back to string
			}

			//Increment vectorCount, (end of current token reached)
			vectorCount++;		
		}
	}

	return true;
}  // end tokenizeInputString

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
// This function deletes attributes(all contents after first whitespace)
static std::string deleteAttributes(std::string input)
{
	//loop through entire string
	for (int i=0; i<=input.length()-1; i++)
	{
		if(input[i]==' ')
		{
			input.erase(i, input.length()-i); //if input[i] is a ' ' space character, erase everything after it, including the space
			return input;
		}
	}
	
	return input;
}

// parseTokenizedInput checks the tokenizedInputVector for correct XML grammar
bool XMLParser::parseTokenizedInput()
{
	//check if a tokenizedInputVector was sucessfully created
	if (tokenizedInputVector.empty())
		return false; //return false if vector size is zero (no elements, nothing to parse)
	
	//variable to hold tag type of each vector element / token
	int tagType;

	//variable to hold tag name from each token
	string tagName;

	//list of invalid characters
	string invalidCharacters=" !\"#$%&'()*+,/;<=>?@[\\]^`{|}~.";
	
	//loop through entire tokenized vector
	for (int i=0; i<=tokenizedInputVector.size()-1; i++)
	{
		//get tag type
		tagType=tokenizedInputVector[i].tokenType;
		tagName=tokenizedInputVector[i].tokenString; 
cout << tagType << endl;
		//Switch statement to check the token type
		switch (tagType)
		{
			case START_TAG:
				//Start tag
				//get rid of attributes for the start tag
				tagName=deleteAttributes(tagName); 

				//check for '-' at beginning of tag, ',' and '.' will be handled afterwards
				if (tagName[0]=='-')
					return false;

				//loop through entire tagName
				for (int j=0; j<=tagName.length()-1; j++)
				{
					//if there's a char in tagName that is punctuation, other than '-' or '_', return false (invalid XML grammar)
					if (ispunct(tagName[j]) && tagName[j]!='-' && tagName[j]!='_') 
						return false; 
				}

				//Push start tag name onto the stack
				parseStack.push(tagName);

				break;

			case END_TAG:
				//End tag

				//check for '-' at beginning of tag, ',' and '.' will be handled afterwards
				if (tagName[0]=='-')
					return false;
					
				//loop through entire tagName
				for (int j=0; j<=tagName.length()-1; j++)
				{
					//if there's a char in tagName that is punctuation, other than '-' or '_', return false (invalid XML grammar)
					if (ispunct(tagName[j]) && tagName[j]!='-' && tagName[j]!='_') 
						return false;
				}

				//Check if end tag matches the most recent start tag from the stack
				if (tagName==parseStack.peek())
				{
					parseStack.pop();
				}

				break;

			case EMPTY_TAG:
				//Empty tag

				//get rid of attributes for the empty tag
				tagName=deleteAttributes(tagName);

				//check for '-' at beginning of tag, ',' and '.' will be handled afterwards
				if (tagName[0]=='-')
					return false;

				//loop through entire tagName
				for (int j=0; j<=tagName.length()-1; j++)
				{
					//if there's a char in tagName that is punctuation, other than '-' or '_', return false (invalid XML grammar)
					if (ispunct(tagName[j]) && tagName[j]!='-' && tagName[j]!='_') 
						return false;
				}

				//Empty tags do not follow parenthesis grammar
				break;

			case CONTENT:
				//Content
				//All characters in content are valid, only checks are for valid nesting grammar for the tags the content is between

				break;

			case DECLARATION:
				//Declaration

				//get rid of attributes for the declaration tag
				tagName=deleteAttributes(tagName);

				//check for '-' at beginning of tag, ',' and '.' will be handled afterwards
				if (tagName[0]=='-')
					return false;

				//loop through entire tagName
				for (int j=0; j<=tagName.length()-1; j++)
				{
					//if there's a char in tagName that is punctuation, other than '-' or '_', return false (invalid XML grammar)
					if (ispunct(tagName[j]) && tagName[j]!='-' && tagName[j]!='_') 
						return false;
				}
cout << "test";
				//Declarations do not follow parethesis grammar
				break;
		}
	}

	//Testing parenthesis grammar
		if (!parseStack.isEmpty())
			return false; // If the parseStack isn't empty, then there was some start tag that didn't have a matching end tag
	
	return true;
}

// Clears the internal data structures for a instance of the class.
void XMLParser::clear()
{
	tokenizedInputVector.clear(); //clear tokenizedInputVector
	parseStack.clear(); //clear parseStack
	elementNameBag->clear(); //clear elementNameBag
}

// Returns the tokenized input vector
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

