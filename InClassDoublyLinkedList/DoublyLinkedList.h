#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdexcept>
#include "ListNode.h"

using namespace std;

template<class T>
class DoublyLinkedList{
  private:
    ListNode *front;
    ListNode *back;
    unsigned int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(const T &d);
    void insertBack (const T &d);
    T removeFront() throw(runtime_error);
    T removeBack() throw(runtime_error);
    T deletePos(int pos) throw(runtime_error);
    T find(const T &d) throw(runtime_error);

    bool isEmpty() const;
    void printList();
    unsigned int getSize() const;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = nullptr;
  back = nullptr;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  // while(!isEmpty()){
  //   removeFront();
  // }
  //you will have to iterate throught the ListNode
  //research it
}

template<class T>
unsigned int DoublyLinkedList<T>::getSize() const
{
  return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() const
{
  return(front==nullptr && back==nullptr);
}

template<class T>
void DoublyLinkedList<T>::printList(){
  ListNode *curr =  front;

  while(curr != nullptr){
    cout << curr->data <<endl;
    curr = curr->next;
  }
}

template<class T>
void DoublyLinkedList<T>::insertFront(const T &d)
{
  ListNode* = new ListNode(d);
  if(!isEmpty())
  {
    //empty list
    back = node;
  }else
  {
    //not an empty list
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template<class T>
T DoublyLinkedList<T>::removeFront() throw(runtime_error)
{
  if(!isEmpty()){
    ListNode *old = front;

    if(front->==nullptr){
      //one node in the list
      back = nullptr;
    }else
    {
      //list has more then one node in the list
      front -> next -> prev = nullptr;

    }

    front = front ->next;
    old->next = nullptr;
    T temp = old-> data;

    delete old;
    size--;

    return temp;

  }else{
    throw runtime_error("There are no elements in the list to remove");
  }
}

template<class T>
T DoublyLinkedList<T>::deletePos(int pos) throw(runtime_error)
{
  if(!isEmpty()){
    int idx = 0;
    ListNode *curr = front;
    ListNode *prev = front;

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
T DoublyLinkedList<T>::find(const T &d) throw(runtime_error)
{
  if(!isEmpty){
    int pos = 0;
    ListNode *curr = front;

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

template <class T>
DoublyLinkedList<T>::insertBack(T d)
{
  ListNode* = new ListNode(d);
  if(!isEmpty())
  {
    //empty list
    front = node;
  }else
  {
    //not an empty list
    back -> next = node;
    node -> prev = back;

  }
  back = node;
  size++;
}

template<class T>
T DoublyLinkedList<T>::removeBack() throw(runtime_error)
{
  if(!isEmpty()){
    ListNode *old = front;

    if(front->==nullptr){
      //one node in the list
      back = nullptr;
    }else
    {
      //list has more then one node in the list
      front -> next -> prev = nullptr;

    }

    front = front ->next;
    old->next = nullptr;
    T temp = old-> data;

    delete old;
    size--;

    return temp;

  }else{
    throw runtime_error("There are no elements in the list to remove");
  }
}

template <class T>
ListNode* DoublyLinkedList<T>::remove(T d) //aka int key
{
  //check if empty before attempting to remove
  ListNode *curr = front;

  while(curr->data != d){
    //let's look for the key value to be removed
    curr = curr->next;

    if(curr == nullptr) //means value we are looking for does not exist in the list
      return nullptr;
  }

  //we found the node/value to be removed
  if(curr ==  front)
  {
    //node to be removed is the front
    front = curr ->next;
  }else
  {
    //it's not the front
    curr -> prev -> next = curr -> next;
  }

  if(curr == back)
  {
    //node to be removed is the back
    back = curr->prev;
  }else
  {
    //else is not the back
    curr->next->prev = curr->prev;
  }

  curr->next = nullptr;
  curr->prev = nullptr;

  size--;

  return curr;
}

//insert anywhere function use from single linked list


#endif
