#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>
using namespace std;

class Child{

friend ostream& operator<<(ostream &out, const Child &other);
friend istream& operator>>(istream &in, Child &other);

public:

  Child();
  Child(string firstN, string lastN, int age);
  ~Child();

  void setFirstName(string firstN);
  void setLastName(string lastN);
  void setId(int age);
  string& getFirstName();
  string& getLastName();
  int& getId();

  bool operator>(const Child &other) const;
  bool operator>=(const Child &other) const;
  bool operator<(const Child &other) const;
  bool operator<=(const Child &other) const;
  bool operator==(const Child &other) const;
  bool operator!=(const Child &other) const;

private:
  string firstName;
  string lastName;
  int id;
};

#include "Child.cpp"

#endif
