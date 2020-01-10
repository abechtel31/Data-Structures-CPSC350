/*
Abby Bechtel
2312284
abechtel@chapman.edu
CPSC 350-03
Assignment 3 - Delimiter Checker
*/

//checks for delimiters in a file

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "delimitercheck.h"
#include "GenStack.h"

using namespace std;

//creating stacks to track the delimiters
GenStack<char> bracketS(10);
GenStack<char> curlyS(10);
GenStack<char> parenthesisS(10);
//creating stacks to track the line numbers
GenStack<int> bracketLine(10);
GenStack<int> curlyLine(10);
GenStack<int> parenthesisLine(10);

DelimiterCheck::DelimiterCheck() //constructor
{}

DelimiterCheck::~DelimiterCheck() //deconstructor
{}

bool DelimiterCheck::testFile(string name) //seperating file testing
{
  ifstream test;
	test.open(name.c_str());

	if (test.is_open())
	{
		test.close();
		file = name;

		return true;
	}

	else
	{
		return false;
	}
}

void DelimiterCheck::delimiterTracking() //implementation for tracking delimiters
{
  ifstream inputFile;
  inputFile.open(file.c_str());

  string line;
  int lenLine;
  int lineCount = 1;
  bool errors = false;

  if (inputFile.is_open()) //if the file is open
  {
    //while there exists another line in the file and an error has not been found yet
    while(getline(inputFile,line) || errors){
      lenLine = line.length();

      for(int i = 0; i <lenLine; ++i)
      {
        //check if a closing delimiter is missing

        if(line[i] == '(') //adding ( to the stack
        {
          parenthesisS.push(line[i]);
          parenthesisLine.push(lineCount);
        }

        if(line[i] == ')') //checking for (
        {
          if(parenthesisS.isEmpty())
          {
            cout << "\nLine: "<< lineCount << " ) found without (" << endl;
            errors = true;
          }
          else
          {
            parenthesisS.pop();
            parenthesisLine.pop();
          }
        }

        if(line[i] == '[')//adding [ to the stack
        {
          bracketS.push(line[i]);
          bracketLine.push(lineCount);
        }

        if(line[i] == ']')// checking for ] on the stack
        {
          if(bracketS.isEmpty())
          {
            cout << "\nLine: " << lineCount << " ] found without ["<< endl;
          }
          else
          {
            bracketS.pop();
            bracketLine.pop();
          }
        }

        if(line[i] == '{') //adding { to the stack
        {
          curlyS.push(line[i]);
          curlyLine.push(lineCount);
        }

        if(line[i] == '}') //checking for { on the stack
        {
          if(curlyS.isEmpty())
          {
            cout << "\nLine: " << lineCount << " } found without {"  << endl;
          }
          else
          {
            curlyS.pop();
            curlyLine.pop();
          }
        }
      }
      ++lineCount; //increment line count
    }

    if (!errors) //if there aren't errors test for opening delimiters without closing delimiters
    {
      if(!parenthesisLine.isEmpty())
      {
        cout << "\nLine: " << parenthesisLine.pop() << " ( found without )" << endl;
      }
      else if (!bracketLine.isEmpty())
      {
        cout << "\nLine: " << bracketLine.pop() << " [ found without ]" << endl;
      }
      else if (!curlyLine.isEmpty())
      {
        cout << "\nLine: " << curlyLine.pop() << " { found without }" << endl;
      }
    }

    if(parenthesisS.isEmpty() && bracketS.isEmpty() && curlyS.isEmpty() || errors)
    {
      cout << "\nThere were no delimiter errors found in the file" << endl;
    }
  }
  inputFile.close();
}

//function to clear out all the stacks for if a next file is chosen
void DelimiterCheck::emptyAllStacks()
{
  while(!bracketS.isEmpty())
  {
    bracketS.pop();
  }
  while(!bracketLine.isEmpty())
  {
    bracketLine.pop();
  }
  while(!curlyS.isEmpty())
  {
    curlyS.pop();
  }
  while(!curlyLine.isEmpty())
  {
    curlyLine.pop();
  }
  while(!parenthesisS.isEmpty())
  {
    parenthesisS.pop();
  }
  while(!parenthesisLine.isEmpty())
  {
    parenthesisLine.pop();
  }
}
