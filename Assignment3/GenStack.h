/*
Abby Bechtel
2312284
abechtel@chapman.edu
CPSC 350-03
Assignment 3 - Syntax Checker
*/

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
    T& peek(); //AKA top

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
  size = 128;
  top = -1;
}

//overloaded constructor
template<class T> GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize]; //dynamically allocating memory on the heap
  size = maxSize;
  top = -1;
}

//destructor
template<class T> GenStack<T>::~GenStack()
{
  delete myArray;
}

//push method to add a value to the stack
template<class T>
void GenStack<T>::push(const T &t)
{
  if(!isFull()) //if the array isn't full add t to the stack
  {
    myArray[++top] = t;
  }
  else //if the array is full, double it's size and copy the old contents over
  {
    T *temp = new T[size];

    for (int i = 0; i < size; ++size)
    {
      temp[i] = myArray[i];
    }

    myArray = new T[size * 2];

    for(int i = 0; i < size; ++i)
    {
      myArray[i] = temp[i];
    }

    size *= 2;
  }
}

//pop method removes the top value from the stack
template<class T>
T GenStack<T>::pop()
{
  if(!isEmpty()) //if the stack isn't empty remove the top
  {
    return myArray[top--];
  }
  else //if the stack is empty throw an exception
  {
    throw StackException("Empty Stack");
  }
}

//peek method returns the top value of the stack
template<class T>
T& GenStack<T>::peek()
{
  if(!isEmpty()) //if the stack isn't empty return the top
  {
    return myArray[top];
  }
  else //if the stack is empty throw an exception
  {
    throw StackException("Empty Stack");
  }
}

//the isFull method returns true if full and false if not
template<class T>
bool GenStack<T>::isFull()
{
  return(top ==size -1);
}

//the isEmpty method returns true if empty and false if not
template<class T>
bool GenStack<T>::isEmpty()
{
  return(top == -1);
}

#endif
