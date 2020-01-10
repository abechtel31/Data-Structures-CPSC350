/*
Abby Bechtel
2312284
abechtel@chapman.edu
CPSC 350-03
Assignment 3 - Delimiter Checker
*/

#ifndef DELIMITERCHECK_H
#define DELIMITERCHECK_H

#include <string>

using namespace std;

class DelimiterCheck{
  public:
    DelimiterCheck(); //constructor
    ~DelimiterCheck(); //deconstructor

    bool testFile(string name); //test if the file can be opened and located
    void delimiterTracking(); //track the delimiters in a file
    void emptyAllStacks(); //empty the stacks

    string file;
};

#endif
