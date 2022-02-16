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
	//if false is returned, cutTest2 failed, exit branch
	if(cutTest2(currentStringVector, candidateStringVector)==false)
		return;
	
	// base case
	if (candidateStringVector.size()==0)
	{ 					//for (int i=0; i<=currentStringVector.size()-1; i++) {cout << currentStringVector[i] << " ";} cout << endl;
		//string to hold full vector as a string, and string to hold each value from vector
		string fullSentence;
		string fromVector;

		//copy strings to fullSentence
		for(int i=0; i<=currentStringVector.size()-1; i++)
		{
			//create variable to hold vector strings and convert each string to lowercase
			fromVector=currentStringVector[i];
			convertToLowerCase(fromVector);

			//add strings from vector
			fullSentence.append(fromVector);
		}
		
		//test for palindrome, increase palindrome count, add palindrome to palindromeVector
		if(isPalindrome(fullSentence))
		{
			palindromeCount++;
			palindromeVector.push_back(currentStringVector);
		}

		//exit function
		return;
	}

	else{
		//vector used to hold strings after popback
		vector<string> secondCandidate=candidateStringVector;

		//Recursive calls
		for (int i=0; i<=candidateStringVector.size()-1; i++)
		{
			//
			currentStringVector.push_back(candidateStringVector[i]); 
			secondCandidate.erase(secondCandidate.begin()+i);
			recursiveFindPalindromes(secondCandidate, currentStringVector); 
			currentStringVector.pop_back();
			secondCandidate.insert(secondCandidate.begin()+i, candidateStringVector[i]);
		}
	}

	
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
	// count number of char occurrences
	int count=0;
	int oddCount=0;
	int j=0;
	char c;

	//string to hold full vector as a string, and string to hold each value from vector
	string fullSentence;
	string fromVector;

	//copy strings to fullSentence
	for(int i=0; i<=stringVector.size()-1; i++)
	{
		//create variable to hold vector strings and convert each string to lowercase
		fromVector=stringVector[i];
		convertToLowerCase(fromVector);
		
		//add strings from vector
		fullSentence.append(fromVector);
	}

	//Find number of occurrences
	while(fullSentence.length()>0)
	{ 
		//c=first element of full string
		c=fullSentence[0];

		//reset count
		count=0;

		//loop through fullSentence checking frequency of each character
		for (int k=0; k<=fullSentence.length()-1; k++)
		{
			//check if fullSentence is empty, break out if true
			if (fullSentence.empty())
				break;
			
			//compare each element to c
			if (fullSentence[k]==c)
			{
				//delete and increase count
				fullSentence.erase(k, 1); 
				count++;
				k--;
			}
		} 

		//check for odd count
			if (count%2!=0)
				oddCount++;	

		//	if oddCount is higher than one return false
		if (oddCount>1)
			return false;
	}
	
	//return true (oddCount <=1)
	return true;
}

// holds fullSentence2 size
	int size2=0;


// stringVector1 is smaller substring
bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{	
	//Return true if second vector is smaller than first, or if either vector is empty
	if (stringVector2.size()<=stringVector1.size() || stringVector1.size()==0 || stringVector2.size()==0)
		return true;
	
	//strings to hold full vector as a string, and strings to hold each value from vector
	string fullSentence1, fullSentence2;
	string fromVector1, fromVector2;

	//copy strings to fullSentence1
	for(int i=0; i<=stringVector1.size()-1; i++)
	{
		//create variable to hold vector strings and convert each string to lowercase
		fromVector1=stringVector1[i];
		convertToLowerCase(fromVector1);
		
		//add strings from vector
		fullSentence1.append(fromVector1); 
	}

	//copy strings to fullSentence2
	for(int i=0; i<=stringVector2.size()-1; i++)
	{
		//create variable to hold vector strings and convert each string to lowercase
		fromVector2=stringVector2[i];
		convertToLowerCase(fromVector2);
		
		//add strings from vector
		fullSentence2.append(fromVector2);
	}
	
	while(fullSentence1.length()>0)
	{
		//check if size of fullSentence2 changed, if not, element couldn't be removed
		// then theres an element in smaller half of the vector not in larger half, fails test
		if (fullSentence2.size()==size2)
			return false;
		
		//Check size of fullSentence2
		size2=fullSentence2.size();
		
		//loop through second string for same char in first string
		for (int i=0; i<=fullSentence2.length()-1; i++)
		{ 
			if (fullSentence2[i]==fullSentence1[0])
			{
				fullSentence1.erase(0, 1);
				fullSentence2.erase(i, 1);

				//check if fullSentence1 ran out of elements
				if (fullSentence1.size()==0)
					return true;
			}
		}
	}

	//return true if loop ran until sentence1 ran out of elements
	return true;
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
		if(ispunct(value[i]) || isdigit(value[i]) || isspace(value[i]))
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

	//Reset palindromeCount
	palindromeCount=0;
	
	//Call recursiveFindPalindrome if cutTest1 passes
	//cutTest1, if false is returned, more than one character in candidateStringVector with odd frequency, fails test
	if(cutTest1(currentCandidateVector)==true)
		recursiveFindPalindromes(currentCandidateVector, currentStringVector);

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
			if(ispunct(value[i]) || isdigit(value[i]) || isspace(value[i]))
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

	//Reset palindromeCount
	palindromeCount=0;

	//Call recursiveFindPalindrome if cutTest1 passes
	//cutTest1, if false is returned, more than one character in candidateStringVector with odd frequency, fails test
	if(cutTest1(currentCandidateVector)==true)
		recursiveFindPalindromes(currentCandidateVector, currentStringVector);
	
	//return true
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	//return palindromeVector
	return palindromeVector;
}

