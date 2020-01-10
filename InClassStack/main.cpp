#include <iostream>
#include "GenStack.h"
#include "Exception.h"

using namespace std;

int main(int argc, char **argv)
{
  GenStack <char> myStack(10);
  try{

    myStack.push('R');
    myStack.push('e');
    myStack.push('n');
    myStack.push('e');

    cout << "poping :" << myStack.pop() << endl;
    cout << "peek-a-boo :" << myStack.peek() <<endl;

    myStack.push('F');
    cout << "peek-a-boo :" << myStack.peek() <<endl;

    while(!myStack.isEmpty())
    {
      cout << "poping :" << myStack.pop() << endl;
    }

    cout << "is stack empty? " << myStack.isEmpty() << endl;

  }catch(StackException& e){
    e.what();
  }

  return 0;
}
