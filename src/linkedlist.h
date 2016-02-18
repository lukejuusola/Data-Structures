#ifndef _LINKEDLIST
#define _LINKEDLIST

/**
 *@brief a node of a singly-linked list containing data of type T
 **/
template <class T>
class LLNode
{
 public:
  LLNode(T* val);
  LLNode(T* val, LLNode* next);
  ~LLNode();
  void insert(T* val);
  void delete_next();
  T* peek();
  
  T* data;
  LLNode<T>* next;
};

/**
 *@brief a linked list with data type T
 *  This linked list works with the data directly and
 *  is not responsible for its cleanup.
 **/
template <class T> 
class LinkedList
{
 public:
  LinkedList();
  ~LinkedList();
  void push_front(T* val);
  void push_back(T* val);
  T* pop_front();
  T* pop_back();
  //delete by value
  //void delete(T val);
  //delete by index
  //T* delete(int index);
  int find(T* val);
  bool is_empty();
  T* operator[](int index);

  LLNode<T>* root;
};

#include "linkedlist.cpp"
#endif
