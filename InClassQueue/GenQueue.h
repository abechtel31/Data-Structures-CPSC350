#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
using namespace std;

//extremely naive queue of chars
class GenQueue{
  public:
    GenQueue(int Maxsize);
    ~GenQueue();
    void insert(char data);
    char remove();
    char peek();
    bool isFull();
    bool isEmpty();
    int getSize();

  private:
    int head;
    int tail;
    int size;
    int numElements;

    char* myQueue;
};

#endif
