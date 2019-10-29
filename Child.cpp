#include <iostream>
#include <string>
using namespace std;

#include "Child.h"


Child::Child()
{
}

Child::Child(string firstN, string lastN, int age)
{
  this->firstName = firstN;
  this->lastName = lastN;
  this->id = age;
}

Child::~Child()
{
}

void Child::setFirstName(string firstN)
{
  this->firstName = firstN;
}

void Child::setLastName(string lastN)
{
  this->lastName = lastN;
}

void Child::setId(int age)
{
  this->id = age;
}

string& Child::getFirstName()
{
  return this->firstName;
}

string& Child::getLastName()
{
  return this->lastName;
}

int& Child::getId()
{
  return this->id;
}

//overloading the cout operator
ostream& operator<<(ostream &out, const Child &other)
{
  out << other.firstName << other.lastName << other.id;
  return out;
}

istream& operator>>(istream &in, Child &other)
{
  string firstN, lastN;
  int age;

  in >> firstN;
  in >> lastN;
  in >> age;

  other.setFirstName(firstN);
  other.setLastName(lastN);
  other.setId(age);
  return in;
}

//overloadting the "less than" operator
bool Child::operator<(const Child &other) const
{

  if(*(this)==other)
  {
    return false;
  }

  if(this->lastName.compare(other.lastName) <= -1)
  {
    return true;
  }
  else
  {
    return false;
  }


  if (this->firstName.compare(other.firstName) <= -1 )
  {
    return true;
  }
  else
  {
    return false;
  }

  if (this->id < other.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Child::operator<=(const Child &other) const
{
  if(*(this) < other || *(this) == other)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Child::operator>(const Child &other) const
{

  if(*(this)==other)
  {
    return false;
  }

  if(this->lastName.compare(other.lastName) >= 1)
  {
    return true;
  }
  else
  {
    return false;
  }


  if (this->firstName.compare(other.firstName) >= 1 )
  {
    return true;
  }
  else
  {
    return false;
  }


  if (this->id > other.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Child::operator>=(const Child &other) const
{
  if(*(this) > other || *(this) == other)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Child::operator==(const Child &other) const
{
  return (this->firstName == other.firstName) && (this->lastName == other.lastName) && (this->id == other.id);
}

bool Child::operator!=(const Child &other) const
{
  return (this->firstName != other.firstName) || (this->lastName != other.lastName) || (this->id != other.id);
}
