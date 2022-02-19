#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) 
  {
    return last;
  } 

  else 
  {
    if (isoperator(ch)) 
    {
      int lastEnd = endPost(s, last - 1);

      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } 
      else 
      {
        return -1;
      }
    } 

    else 
    {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {

  //strings to hold data
  char ch1, ch2;
  
  // check if postfix string is valid
  if (isPost(postfix)==false)
    return;

  //loop through postfix string
  for (int i=0; i<=postfix.size()-1; i++)
  {
      //if character is an operator
      if (isoperator(postfix[i]))
      {
        //pop back two operands
        if (prefix.size()>=2) //check that prefix isn't empty (has operands)
        {
          ch1=prefix.back();
          prefix.pop_back();       
          ch2=prefix.back();
          prefix.pop_back();
        }

        //add operator
        prefix.push_back(postfix[i]);
        prefix.push_back(ch2);
        prefix.push_back(ch1);
      }
      
      //if character is an operand
      else
      {
        prefix.push_back(postfix[i]);
      }
  }
  
}
