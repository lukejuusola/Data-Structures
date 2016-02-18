#ifndef _LINKEDLISTCPP
#define _LINKEDLISTCPP

#include "linkedlist.h"
#include "dsexceptions.h"
#include <iostream>

/**
 *@brief constructs an LLNode with data = val, passed by reference;
 *@param T* val -- the data for the node.
 **/
template <class T>
LLNode<T>::LLNode(T* val)
{
  this->data = val;
  this->next = nullptr;
}

/**
 *@brief constructs an LLNode with data = val;
 *@param T* val -- the data for the node.
 *@param LLNode* next -- the node that this one should point to.
 **/
template <class T>
LLNode<T>::LLNode(T* val, LLNode* next)
{
  this->data = val;
  this->next = next;
}

/**
 *@brief Destructs an LLNode; Does not delete the data from the node.
 **/
template <class T>
LLNode<T>::~LLNode(){}

/**
 *@brief Inserts a new node with data val, after the current node.
 *@param T* val -- the value of the new node.
 **/
template <class T>
void LLNode<T>::insert(T* val)
{
  /// Might fail if null. I don't think so.
  LLNode* newNode = new LLNode(val, this->next);
  this->next = newNode;
}
/**
 *@brief Deletes the node after this node
 *  links this to the new next.
 **/
template <class T>
void LLNode<T>::delete_next()
{
  if(!this->next) return;
  LLNode<T>* temp;
  temp = this->next;
  if(this->next->next) this->next = this->next->next;
  else this->next = nullptr;
  delete temp;
}
/**
 *@brief Returns the data in this node.
 **/
template <class T>
T* LLNode<T>::peek()
{
  return data;
}


/**
 *@brief Initialize the LinkedList to empty
 **/
template <class T>
LinkedList<T>::LinkedList()
{
  root = nullptr;
}
/**
 *@brief Deconstruct the LinkedList
 **/
template <class T>
LinkedList<T>::~LinkedList()
{
  while(!this->is_empty())
    {
      this->pop_front();
    }
}

/**
 *@brief Adds a new value at the front of the LinkedList.
 *@param T* val -- The data to be pushed to the front of the LinkedList.
 **/
template <class T>
void LinkedList<T>::push_front(T* val)
{
  LLNode<T>* newNode = new LLNode<T>(val, this->root);
  this->root = newNode;
}
/**
 *@brief Adds a new value at the end of the LinkedList
 *  O(n), end unknown
 *  Design decision, could revise.
 *@param T* val -- the value to be pushed to the back of the LinkedList. 
 **/
template <class T>
void LinkedList<T>::push_back(T* val)
{
  LLNode<T>* cur = this->root, *newNode = new LLNode<T>(val);
  if(!cur) 
    {
      this->root = newNode;
      return;
    }
  while(cur->next)
    {
      cur = cur->next;
    }
  cur->next = newNode;
}
/**
 *@brief Pops a value from the front, returning the data.
 *@return the popped data.
 **/
template <class T>
T* LinkedList<T>::pop_front()
{
  if(!this->root) throw EmptyPopException();
  LLNode<T>* temp = this->root;
  this->root = temp->next;
  T* ret_data = temp->data;
  delete temp;
  return ret_data;
}
/**
 *@brief Pops a value from the back, returning the data.
 * O(n), back unknown. Design decision, could be revised.
 *@return the popped data.
 **/
template <class T>
T* LinkedList<T>::pop_back()
{
  if(!this->root) throw EmptyPopException();
  LLNode<T>* lead = this->root, *follow = nullptr;
  T* ret_data; 
  while(lead->next)
    {
      follow = lead;
      lead = lead->next;
    }
  ret_data = lead->data;
  delete lead;
  follow->next = nullptr;
  return ret_data;
}
/**
 *@brief Delete node with data val
 *@param T* val -- the value to be searched for
 *@return Void
 **/
//

/**
 *@brief Delete node with index val
 *@param int index -- the index to be deleted
 *@return the data from that node
 **/
//

/**
 *@brief Find the node with index i
 *  if not found, throws NotFoundException;
 *@param T* val, the value to be found
 *@return the index of that entry
 **/
template <class T>
int LinkedList<T>::find(T* val)
{
  int ret_index = -1;
  LLNode<T>* cur = this->root;
  while(cur)
    {
      ret_index++;
      if(cur->data == val) return ret_index;
      cur = cur->next;
    }
  throw NotFoundException();
}

/**
 *@brief tests if the LinkedList is empty
 *@return bool for truth
 **/
template <class T>
bool LinkedList<T>::is_empty()
{
  return this->root == nullptr;
}

/**
 *@brief Provides access to elements of the LinkedList by index
 *@return Returns the data from that node.
 **/
template <class T>
T* LinkedList<T>::operator[](int index)
{
  if(index < 0) throw OutOfBoundsException();
  if(!this->root) throw OutOfBoundsException();

  LLNode<T>* cur = this->root;
  while(index != 0)
    {
      if(!cur) throw OutOfBoundsException();
      cur = cur->next;
      index--;
    }
  return cur->data;
}

#endif
