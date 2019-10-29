#include "LinkedStack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class ItemType>
LinkedStack<ItemType>::LinkedStack()
{
  head = NULL;
}

template <class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& list1)
{
  this->head = NULL;

  if (list1.head == NULL)
  {
    return;
  }
  else
  {
    head = new LinkedStack<ItemType>::Node();
    ItemType *pItemData = new ItemType;
    *pItemData = *(list1.head -> data);
    head -> data = pItemData;
    head -> next = list1.head -> next;

    LinkedStack<ItemType>::Node* nodeOne = head;
    LinkedStack<ItemType>::Node* nodeTwo = head -> next;

    while (nodeTwo != NULL)
    {
      nodeOne -> next = new LinkedStack<ItemType>::Node();
      nodeOne = nodeOne -> next;
      nodeOne -> data = new ItemType(*(nodeTwo -> data));

      nodeTwo = nodeTwo -> next;
    }

    nodeOne -> next = NULL;
  }
}

template <class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
  DeleteStack();
}

//Operator overloading
template <class ItemType>
LinkedStack<ItemType>& LinkedStack<ItemType>::operator=(const LinkedStack<ItemType> &list1)
{
  if( *(this) == list1)
  {
    return *(this);
  }
  else
  {
    this->DeleteStack();

    if (list1.head == NULL)
    {
      return *(this);
    }
    else
    {
      LinkedStack<ItemType> temp(list1);
      this->head = temp.head;
      temp.head = nullptr;
      return *(this);
    }
  }
}

template <class ItemType>
bool LinkedStack<ItemType>::operator==(const LinkedStack<ItemType> &list1) const
{

  if (this -> head == NULL && list1.head == NULL)
  {
    return true;
  }
  else if (this -> head == NULL || list1.head == NULL)
  {
    return false;
  }

  LinkedStack<ItemType>::Node* nodeThis = this -> head;
  LinkedStack<ItemType>::Node* nodeOther = list1.head;

  while (nodeThis != NULL || nodeOther != NULL)
  {
    if (nodeThis == NULL && nodeOther != NULL)
    {
      return false;
    }
    if (nodeThis != NULL && nodeOther == NULL)
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
bool LinkedStack<ItemType>::operator!=(const LinkedStack<ItemType> &list1) const
{
  if(this -> head == NULL && list1.head == NULL)
  {
    return false;
  }

  LinkedStack<ItemType>::Node* nodeThis = this -> head;
  LinkedStack<ItemType>::Node* nodeOther = list1.head;

  while (nodeThis != NULL || nodeOther != NULL)
  {
    if (nodeThis != NULL && nodeOther == NULL)
    {
      return true;
    }
    if ( nodeThis == NULL && nodeOther != NULL)
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
bool LinkedStack<ItemType>::BuildStack(string fileName)
{
  string line;
  ItemType x;
  ifstream theFile;
  theFile.open(fileName);

  if (theFile.is_open())
  {
    while(theFile >> x)
    {
      this->Push(&x);
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
void LinkedStack<ItemType>::Push(ItemType *obj)
{
  if (obj == NULL)
  {
    return;
  }

  LinkedStack<ItemType>::Node* newNode = new LinkedStack<ItemType>::Node();
  ItemType *pItemData = new ItemType;
  *pItemData = *obj;
  newNode->data = pItemData;

  newNode->next = head;
  head = newNode;
}

template <class ItemType>
bool LinkedStack<ItemType>::Pop(ItemType &result)
{
  if(isEmpty() == true)
  {
    return false;
  }
  else
  {
    LinkedStack<ItemType>::Node* temp = head;

    result = *(head->data);

    head = head->next;

    delete temp->data;
    delete temp;

    return true;
  }
}

template <class ItemType>
bool LinkedStack<ItemType>::Peek(ItemType &result) const
{
  if(this->isEmpty() == true)
  {
    return false;
  }
  else
  {
    result = *(head->data);
    return true;
  }
}

template <class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
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
int LinkedStack<ItemType>::Size() const
{
  LinkedStack<ItemType>::Node* copy = head;
  int size = 0;

  while( copy != NULL)
  {
    copy = copy->next;
    size++;
  }

  return size;
}

template <class ItemType>
bool LinkedStack<ItemType>::isPalindrome() const
{
  if(this->head == NULL)
  {
    return true;
  }
  else if(this->Size() == 1)
  {
    return true;
  }
  else
  {
    LinkedStack<ItemType> copy;
    LinkedStack<ItemType> emptyStack;

    LinkedStack<ItemType>::Node *temp = this->head;

    copy = *(this);

    ItemType x;

    int sizeOriginal = this->Size();

    while(sizeOriginal > 0)
    {
      copy.Pop(x);
      emptyStack.Push(&x);
      sizeOriginal--;
    }

    return *(this) == emptyStack;
  }
}

template <class ItemType>
void LinkedStack<ItemType>::DeleteStack()
{
  if(head == NULL)
  {
    return;
  }

  while(head != nullptr)
  {
    LinkedStack<ItemType>::Node* temp = head;
    head = head->next;
    delete temp->data;
    delete temp;
    temp = head;
  }
}
