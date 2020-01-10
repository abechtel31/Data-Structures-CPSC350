/*
Abby Bechtel
2312284
abechtel@chapman.edu
CPSC 350-03
Assignment 3 - Delimiter Checker
*/

#include <iostream>
#include "delimitercheck.h"
#include "GenStack.h"

using namespace std;

int main(int argc, char** argv)
{
  DelimiterCheck d; //creating an instance of the delimiter checker
  bool keepGoing = true; //variable to control if the user wants to check a new file

  if(argc == 2) //checking if the appropriate number of arguments have been entered
  {
    if(d.testFile(argv[1]))
    {
      d.delimiterTracking(); //check the delimiters in the file

      //begin getting user input
      while(keepGoing)
      {
        string choice;
        cout <<"\nWould you like to process another fie?\ny - yes\nn - no" << endl;
        cin >> choice;
        while ((choice != "y") && (choice != "n"))
        {
          cout << "Invalid input! Try again." << endl;
          cout <<"\nWould you like to process another file?\ny - yes\nn - no" << endl;
          cin >> choice;
        }

        if (choice == "y")
        {
          cout << "\nEnter a file name: " << endl;

          string fileNameString;
          cin >> fileNameString;

          d.emptyAllStacks(); //ensure all stacks are empty

          if(d.testFile(fileNameString))
          {
            d.delimiterTracking();
          }
          else
          {
            cout << "\nFile was not found" << endl;
          }

          break;
        }
        else if (choice == "n")
        {
          cout << "The program is ending" << endl;
          keepGoing = false;
        }
        else
        {
          cout << "Invalid input" << endl;
        }
      }
    }
    else
    {
      cout << "\nThe file could not be opened" << endl;
    }
  }
  else
  {
    cout << "\nYou did not enter the correct amount of arguments" << endl;
  }

  return 0;
}
