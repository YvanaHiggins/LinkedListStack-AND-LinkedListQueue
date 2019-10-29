#ifndef LinkedStack_H
#define LinkedStack_H
#include <iostream>
using namespace std;

template <class ItemType>
class LinkedStack{

  friend ostream& operator<<(ostream &out, const LinkedStack<ItemType> &ll)
  {
    LinkedStack<ItemType>::Node* current;

    current = ll.head;
    while(current != NULL)
    {
        out << *(current->data);
        current = current->next;
    }

    return out;
  }

public:

  LinkedStack();
  LinkedStack(const LinkedStack<ItemType>& list1);
  ~LinkedStack();

  //Operator overloading
  LinkedStack<ItemType>& operator=(const LinkedStack<ItemType> &list1);
  bool operator==(const LinkedStack<ItemType> &list1) const;
  bool operator!=(const LinkedStack<ItemType> &list1) const;

  bool BuildStack(string fileName);
  void Push(ItemType *obj);
  bool Pop(ItemType &result);
  bool Peek(ItemType &result) const;
  bool isEmpty() const;
  int Size() const;
  bool isPalindrome() const;
  void DeleteStack();

private:

  struct Node
  {
    ItemType *data;
    Node *next;
  };

  Node* head;


};

#include "LinkedStack.cpp"

#endif
