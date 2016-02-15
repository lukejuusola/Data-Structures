#include <iostream>
#include "linkedlist.h"
#include <random>

#define NUMTESTS 1000

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

int main()
{
  LinkedList<test_data>* list = new LinkedList<test_data>();
  
  delete list;
}
