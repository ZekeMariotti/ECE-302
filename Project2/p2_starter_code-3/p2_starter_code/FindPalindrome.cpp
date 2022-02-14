#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// TODO need to implement this recursive function!
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

//Constructor
FindPalindrome::FindPalindrome()
{
	//set default values
	palindromeCount=0;
}

//Destructor
FindPalindrome::~FindPalindrome()
{
	// Nothing created dynamically, vectors handle their own memory management
}

//Returns the number of sentence palindromes in the FindPalindrome instance
int FindPalindrome::number() const
{
	//Returns palindromeCount variable
	return palindromeCount;
}

/* Removes all words from this instance. The internal list
of sentence palindromes is cleared and any internal data structures are reset.*/
void FindPalindrome::clear()
{
	// Clear all vectors
	currentCandidateVector.clear();
	currentStringVector.clear();
	palindromeVector.clear();

	//Reset palindromeCount
	palindromeCount=0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

/** Adds a new string to this FindPalindrome instance and computes the
	   number of palindrome sentences possible. Note that the new string must
	   be unique per the definition in the project description.
	   @post  If successful, the string has been added to the FindPalindrome
	    and instance, and the sentence palindromes in the instance 
	    have been recomputed.
	   @param value  The string to add to the instance of FindPalindrome.
	   @return  True if addition was successful, or false if not. */
bool FindPalindrome::add(const string & value)
{
	// Check for punctuation and numbers
	for (int i=0; i<=value.length()-1; i++)
	{
		//using cctype library function ispunct
		if(ispunct(value[i]) || isdigit(value[i]))
			return false;
	}

	//check for repeated string
	//Holds values for string parameter and for vector string, convert value to lower
	string valueString=value; 
	convertToLowerCase(valueString);
	string vectorString; 

	//check if candidate vector is empty
	if (currentCandidateVector.size()>0)
	{
		//Check for repeated string
		for (int i=0; i<=currentCandidateVector.size()-1; i++)
		{
			//Update vectorString
			vectorString=currentCandidateVector[i]; 
			convertToLowerCase(vectorString);

			if (valueString==vectorString)
				return false;
		}
	}

	//Add word to instance
	currentCandidateVector.push_back(value);

	//return true
	return true;
}

/** Adds a new vector of strings to this FindPalindrome instance and
	   computes the number of palindrome sentences possible. Note: You may
	   not implement this method by repeatedly calling the add(string) method
	   as this would be very inefficient. Implementing this method by repeatedly
	   calling add(string) will result in a grade of zero for the project. Again,
	   note that the strings added must be unique per the project description.
	   @post  If successful, the vector of strings has been added to the 
	    FindPalindrome instance, and the sentence palindromes for the instance 
	    have been recomputed.
	   @param stringVector  The vector of strings to add to the instance of
	    FindPalindrome.
	   @return  True if addition was successful, or false if not. */
bool FindPalindrome::add(const vector<string> & stringVector)
{
	// Check for punctuation and numbers
	for(int j=0; j<=stringVector.size()-1; j++)
	{
		//Get string at position j
		string value=stringVector[j];
		
		for (int i=0; i<=value.length()-1; i++)
		{
			//using cctype library function ispunct
			if(ispunct(value[i]) || isdigit(value[i]))
				return false;
		}
	}

	//check if candidate vector is empty
	if (currentCandidateVector.size()>0)
	{
		//loop through vector checking for repeated strings
		for (int j=0; j<=stringVector.size()-1; j++)
		{
			//get string value
			string value=stringVector[j];
			
			//check for repeated string
			//Holds values for string parameter and for vector string, convert value to lower
			string valueString=value; 
			convertToLowerCase(valueString);
			string vectorString; 

			
			//Check for repeated string
			for (int i=0; i<=currentCandidateVector.size()-1; i++)
			{
				//Update vectorString
				vectorString=currentCandidateVector[i]; 
				convertToLowerCase(vectorString);

				if (valueString==vectorString)
					return false;
			}
		}
	}

	//Add vector
	for (int j=0; j<=stringVector.size()-1; j++)
	{
		currentCandidateVector.push_back(stringVector[j]);
	}
	
	//return true
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}

