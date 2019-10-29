#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
using namespace std;

template <class ItemType>
class LinkedQueue{

  //template <class U>
  friend ostream& operator<<(ostream &out, const LinkedQueue<ItemType> &ll)
  {
    LinkedQueue<ItemType>::Node* current;

    current = ll.head;
    while(current != NULL)
    {
        out << *(current->data);
        current = current->next;
    }

    return out;
  }

public:

  LinkedQueue();
  LinkedQueue(const LinkedQueue<ItemType>& list1);
  ~LinkedQueue();

  //Operator overloading
  LinkedQueue<ItemType>& operator=(const LinkedQueue<ItemType> &list1);
  bool operator==(const LinkedQueue<ItemType> &list1) const;
  bool operator!=(const LinkedQueue<ItemType> &list1) const;

  bool BuildQueue(string fileName);
  void Enqueue(ItemType *obj);
  bool Dequeue(ItemType &result);
  bool Peek(ItemType &result) const;
  bool isEmpty() const;
  int Size() const;
  void Reverse();
  void DeleteQueue();

private:

  struct Node
  {
    ItemType *data;
    Node *next;
  };

  Node* head;


};

#include "LinkedQueue.cpp"

#endif
