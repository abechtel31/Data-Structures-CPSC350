#include <iostream>
#include "GenQueue.h"
using namespace std;

int main(){
  // GenQueue(10); //stack
  GenQueue* myQ = new GenQueue(10); //heap - need tp delete at the end
  //if you want it to persist in memory
  //use the dereferencing opperator -> instead of .

  myQ->insert('a');
  myQ->insert('b');
  myQ->insert('c');

  while(!myQ->isEmpty()){
    char c =myQ->remove();
    cout << c <<endl;
  }

  delete myQ;
  return 0;
}
