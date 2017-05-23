#ifndef HUGEINT_H
#define HUGEINT_H
#include<iostream>
#include<string>
using namespace std;
class HugeInt{
  friend ostream &operator <<
 (ostream &, HugeInt &);
  friend istream &operator >>
 (istream &, HugeInt &);

public: 
  HugeInt();
  HugeInt(long long );
  HugeInt(string);
   HugeInt operator+(HugeInt );
   HugeInt operator=(HugeInt r);
   HugeInt operator-(HugeInt nn);
  int array[50];
};
#endif
