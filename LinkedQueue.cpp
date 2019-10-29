#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
  head = NULL;
}

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& list1)
{
  this->head = NULL;

  if (list1.head == NULL)
  {
    return;
  }
  else
  {
    head = new LinkedQueue<ItemType>::Node();
    ItemType *pItemData = new ItemType;
    *pItemData = *(list1.head -> data);
    head -> data = pItemData;
    head -> next = list1.head -> next;

    LinkedQueue<ItemType>::Node* nodeOne = head;
    LinkedQueue<ItemType>::Node* nodeTwo = head -> next;

    while (nodeTwo != NULL)
    {
      nodeOne -> next = new LinkedQueue<ItemType>::Node();
      nodeOne = nodeOne -> next;
      nodeOne -> data = new ItemType(*(nodeTwo -> data));

      nodeTwo = nodeTwo -> next;
    }

    nodeOne -> next = NULL;
  }
}

template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
  DeleteQueue();
}

//Operator overloading
template <class ItemType>
LinkedQueue<ItemType>& LinkedQueue<ItemType>::operator=(const LinkedQueue<ItemType> &list1)
{
  if( *(this) == list1)
  {
    return *(this);
  }
  else
  {
    this->DeleteQueue();

    if (list1.head == NULL)
    {
      return *(this);
    }
    else
    {
      LinkedQueue<ItemType> temp(list1);
      this->head = temp.head;
      temp.head = NULL;
      return *(this);
    }
  }
}

template <class ItemType>
bool LinkedQueue<ItemType>::operator==(const LinkedQueue<ItemType> &list1) const
{

  if (this -> head == NULL && list1.head == NULL)
  {
    return true;
  }
  else if (this -> head == NULL || list1.head == NULL)
  {
    return false;
  }

  LinkedQueue<ItemType>::Node* nodeThis = this -> head;
  LinkedQueue<ItemType>::Node* nodeOther = list1.head;

  while (nodeThis != NULL || nodeOther != NULL)
  {
    if (nodeThis -> next == NULL && nodeOther -> next != NULL)
    {
      return false;
    }
    if (nodeThis -> next != NULL && nodeOther -> next == NULL)
    {
      return false;
    }
    if (*(nodeThis -> data) != *(nodeOther -> data))
    {
      return false;
    }
    nodeThis = nodeThis -> next;
    nodeOther = nodeOther -> next;
  }

  return true;
}

template <class ItemType>
bool LinkedQueue<ItemType>::operator!=(const LinkedQueue<ItemType> &list1) const
{
  if(this -> head == NULL && list1.head == NULL)
  {
    return false;
  }

  LinkedQueue<ItemType>::Node* nodeThis = this -> head;
  LinkedQueue<ItemType>::Node* nodeOther = list1.head;

  while (nodeThis != NULL || nodeOther != NULL)
  {
    if (nodeThis == NULL && nodeOther != NULL)
    {
      return true;
    }
    if (nodeThis != NULL && nodeOther == NULL)
    {
      return true;
    }
    if (*(nodeThis -> data) != *(nodeOther -> data))
    {
      return true;
    }
    nodeThis = nodeThis -> next;
    nodeOther = nodeOther -> next;
  }

  return false;
}

template <class ItemType>
bool LinkedQueue<ItemType>::BuildQueue(string fileName)
{
  string line;
  ItemType x;
  ifstream theFile;
  theFile.open(fileName);

  if (theFile.is_open())
  {
    while(theFile >> x)
    {
      this->Enqueue(&x);
    }

    theFile.close();
    return true;
  }
  else
  {
    cout << "Unable to open file";
    return false;
  }
}

template <class ItemType>
void LinkedQueue<ItemType>::Enqueue(ItemType *obj)
{
  if(obj == NULL)
  {
    return;
  }
  LinkedQueue<ItemType>::Node* copy = head;

  if (copy == NULL)
  {
    LinkedQueue<ItemType>:: Node* newNode = new Node();
    ItemType *pItemData = new ItemType;
    *pItemData = *obj;
    newNode->data = pItemData;

    head = newNode;
    return;
  }
  else
  {
    while(copy->next != NULL)
    {
      copy = copy->next;
    }

    LinkedQueue<ItemType>:: Node* newNode = new Node();
    ItemType *pItemData = new ItemType;
    *pItemData = *obj;
    newNode->data = pItemData;

    copy->next = newNode;
  }
}

template <class ItemType>
bool LinkedQueue<ItemType>::Dequeue(ItemType &result)
{
  if(isEmpty() == true)
  {
    return false;
  }
  else
  {
    LinkedQueue<ItemType>::Node* temp = head;

    result = *(head->data);
    head = head->next;

    delete temp->data;
    delete temp;

    return true;
  }
}

template <class ItemType>
bool LinkedQueue<ItemType>::Peek(ItemType &result) const
{
  if(this->isEmpty() == true)
  {
    return false;
  }
  else
  {
    result = *(this->head->data);
    return true;
  }
}

template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
  if (head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class ItemType>
int LinkedQueue<ItemType>::Size() const
{
  LinkedQueue<ItemType>::Node* copy = head;
  int size = 0;

  while( copy != NULL)
  {
    copy = copy->next;
    size++;
  }

  return size;
}

template <class ItemType>
void LinkedQueue<ItemType>::Reverse()
{
  ItemType x;

  LinkedStack<ItemType> tempStack;

  int count = this->Size();

  while (count > 0)
  {
    this->Dequeue(x);
    tempStack.Push(&x);
    count--;
  }

  int countStack = tempStack.Size();

  while(countStack > 0)
  {
    tempStack.Pop(x);
    this->Enqueue(&x);
    countStack--;
  }

}

template <class ItemType>
void LinkedQueue<ItemType>::DeleteQueue()
{
  if(head == NULL)
  {
    return;
  }

  while(head != nullptr)
  {
    LinkedQueue<ItemType>::Node* temp = head;
    head = head->next;
    delete temp->data;
    delete temp;
    temp = head;
  }
}
#endif
