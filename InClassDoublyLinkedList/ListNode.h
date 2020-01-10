#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode{
  public:
    T data;
    ListNode *next;
    ListNode *prev;

    //constructor
    ListNode();

    ListNode(const T &d);
    ~ListNode;
};

template<class T> ListNode<T>::ListNode(){}

template<class T> ListNode<T>::ListNode(const T &d)
{
  data = d;
  next = nullptr;
  prev = nullptr;
}

template<class T> ListNode<T>::~ListNode()
{
  next = nullptr;
  prev = nullptr;
}

#endif
