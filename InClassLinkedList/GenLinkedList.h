#ifndef GENLINKEDLIST_H
#define GENLINKEDLIST_H

#include <stdexcept>
#include "GenNode.h"

using namespace std;

template<class T>
class GenLinkedList{
  private:
    GenNode *front;
    unsigned int size;

  public:
    GenLinkedList();
    ~GenLinkedList();

    void insertFront(const T &d);
    T removeFront() throw(runtime_error);
    T deletePos(int pos) throw(runtime_error);
    T find(const T &d) throw(runtime_error);

    bool isEmpty() const;
    void printList();
    unsigned int getSize() const;
};

template<class T>
GenLinkedList<T>::GenLinkedList(){
  size = 0;
  front = nullptr;
}

template<class T>
GenLinkedList<T>::~GenLinkedList(){
  while(!isEmpty()){
    removeFront();
  }
}

template<class T>
unsigned int GenLinkedList<T>::getSize() const
{
  return size;
}

template<class T>
bool GenLinkedList<T>::isEmpty() const
{
  return front==nullptr;
}

template<class T>
void GenLinkedList<T>::printList(){
  GenNode *curr =  front;

  while(curr != nullptr){
    cout << curr->data <<endl;
    curr = curr->next;
  }
}

template<class T>
void GenLinkedList<T>::insertFront(const T &d)
{
  GenNode* = new GenNode(d);
  node->next=front;
  front = node;
  size++;
}

template<class T>
T GenLinkedList<T>::removeFront() throw(runtime_error)
{
  if(!isEmpty()){
      GenNode *old = front;
    T temp = front -> next;
    front =  front->next;
    old->next =  nullptr; //null out a pointer to null before deleting
    delete old;
    size--;

    return temp;
  }else{
    throw runtime_error("There are no elements in the list to remove");
  }
}

template<class T>
T GenLinkedList<T>::deletePos(int pos) throw(runtime_error)
{
  if(!isEmpty()){
    int idx = 0;
    GenNode *curr = front;
    GenNode *prev = front;

    while(idx !=pos)
    {
      prev = curr;
      curr = curr->next;
      idx++;
    }
    //make sure you've found it curr!=nullptr

    prev->next = curr->next;
    curr ->next = nullptr;
    T temp - curr->data;
    delete curr;
    size--;
    return temp;
  }

  else
  {
    throw runtime_error("There are no elements in the list to remove");
  }
}

template<class T>
T GenLinkedList<T>::find(const T &d) throw(runtime_error)
{
  if(!isEmpty){
    int pos = 0;
    GenNode *curr = front;

    while(curr != nullptr)
    {
      if(curr->data == d)
      {
        //break;
        return idx;
      }

      idx++;
      curr = curr->next;
    }
    //if(curr == nullptr)
      //idx=-1;
    //return idx;

    return -1;
  }

  else{
    throw runtime_error("There are no elements in the list to remove");
  }
}

#endif
