#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "StackException.h"

using namespace std;

template<class T>
class GenStack
{
  public:
    GenStack();//constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    void push(const T &t);
    T pop();
    T& peek();//AKA top

    bool isFull();
    bool isEmpty();

  private:
    int size;
    int top;

    T *myArray;
};

//default constructor
template<class T> GenStack<T>::GenStack(){
  //initialization of default values
  myArray =  new T[128];
  size =128;
  top = -1;
}

//overloaded constructor
template<class T> GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize]; //dynamically allocating memory on the heap
  size = maxSize;
  top = -1;
}

template<class T> GenStack<T>::~GenStack()
{
  delete myArray;
}

template<class T>
void GenStack<T>::push(const T &t)
{
  if(!isFull()){
    myArray[++top]=t;
  }else{
    throw StackException("Stack Overflow");
  }
}

template<class T>
T GenStack<T>::pop()
{
  if(!isEmpty()){
    return myArray[top--];
  }else{
    throw StackException("Empty Stack");
  }
}

template<class T>
T& GenStack<T>::peek()
{
  if(!isEmpty()){
    return myArray[top];
  }else{
    throw StackException("Empty Stack");
  }
}

template<class T>
bool GenStack<T>::isFull(){
  return(top ==size -1);
}

template<class T>
bool GenStack<T>::isEmpty(){
  return(top == -1);
}

#endif
