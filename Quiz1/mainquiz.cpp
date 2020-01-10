#include "Quiz.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  // if(argc>1){
    //string test ="reneesdkjasdfalskdf";
    //string test= argv[1];
    string test = "";
    Quiz q; //stored on the stack

    cout << "please enter a string" <<endl;
    cin >>test;

    cout << "number of command line arguments: " << argc << endl;
    cout << "the number of vowels in " << test << "is: " << q.countVowels(test) << endl;
  // }
  // else
  // {
  //   cout<< "please provide an input stream" << endl;
  //   cout<< "USAGE: /foobar.out [input stream]" << endl;
  // }

  cout<< "program exited successfully" << endl;

  return 0;
}
