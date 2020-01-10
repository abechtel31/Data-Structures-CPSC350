#ifndef GENNODE_H
#define GENNODE_H

template <class T>
class GenNode{
  public:
    T data;
    GenNode *next;

    //constructor
    GenNode();

    GenNode(const T &d);
    ~GenNode;
};

template<class T> GenNode<T>::GenNode(){}

template<class T> GenNode<T>::GenNode(const T &d)
{
  data = d;
  next = nullptr;
}

template<class T> GenNode<T>::~GenNode()
{
  if(next == nullptr)
    delete next;
}

#endif
