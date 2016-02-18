#include <iostream>
#include "linkedlist.h"
#include <random>

#define NUMTESTS 10

class test_data
{
public:
  int i;
  test_data(int j)
  {
    this->i = j;
  }
};

void linkedlist_test_push_front(LinkedList<test_data>* list)
{
  for(int i = 0; i < NUMTESTS; i++)
    {
      test_data *newData = new test_data(i);
      list->push_front(newData);
    }
}
void linkedlist_test_push_back(LinkedList<test_data>* list)
{
  for(int i = 0; i < NUMTESTS; i++)
    {
      test_data *newData = new test_data(i);
      list->push_back(newData);
    }
}
void print(LinkedList<test_data>* list)
{
  if(!list->root) return;
  LLNode<test_data>* cur = list->root;
  while(cur)
    {
      std::cout << cur->data->i << std::endl;
      cur = cur->next;
    }
  std::cout << "-----------------------" << std::endl;
}
void clear(LinkedList<test_data>* list)
{
  if(!list->root) return;
  LLNode<test_data>* cur = list->root;
  while(cur)
    {
      delete cur->data;
      cur = cur->next;
    }
}

int main()
{
  LinkedList<test_data>* list = new LinkedList<test_data>();
  linkedlist_test_push_back(list);
  print(list);
  linkedlist_test_push_front(list);
  print(list);
  
  std::cout << list[2]->i << list[1]->i << std::endl;

  clear(list);
  while(!list->is_empty())
    {
      list->pop_front();
    }
  std::cout << std::endl;  
  delete list;

  return 0;
}

