#include "Quiz.h" //user defined header file
#include <iostream> //identifying system library part of C++

using namespace std;

Quiz::Quiz()
{

}

Quiz::~Quiz()
{
  cout<< "object deleted"<<endl; //console out
}

int Quiz::countVowels(string input)
{
  int count = 0;
  for(int i=0; i,input.size();++i)
  {
    char strInput = tolower(input[i]);
    if(strInput == 'a') //if you have only one line without spacing you don't need curly brakets
      count++;
    else if(strInput == 'e')
      count++;
    else if(strInput == 'i')
      count++;
    else if(strInput == 'o')
      count++;
    else if(strInput == 'u')
      count++;
  }
  return count;
}
