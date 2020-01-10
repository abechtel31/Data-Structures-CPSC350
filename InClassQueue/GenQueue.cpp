#include <iostream>
#include "GenQueue.h"

using namespace std;

GenQueue::GenQueue(int maxSize){
  myQueue  = new char[maxSize];
  size  = maxSize;
  numElements = 0;
  head = 0;
  tail = -1;
}

GenQueue::~GenQueue(){
  delete myQueue;
}

void GenQueue::insert(char data){
  if(!isFull()){
    if(tail==size-1){
      tail=-1;
    }
  }else{
    char* newArr= new char[2*size];
    for(int i=0; i<size; ++i){
      newArr[i]=myQueue[i];
    }
    size*=2;
    delete myQueue;
    myQueue = newArr;
  }
  myQueue[++tail]=data;
  numElements++;
}

char GenQueue::remove(){
  char c = myQueue[head++];
  if(head==size){
    head=0;
  }
  --numElements;
  return c;
}

char GenQueue::peek(){
  return myQueue[head];
}

bool GenQueue::isFull(){
  return(numElements == size);
}

bool GenQueue::isEmpty(){
  return(numElements==0);
}

int GenQueue::getSize(){
  return numElements;
}
