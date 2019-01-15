#include<iostream>
#include<iomanip>
#include "node.h"
using namespace std;
class Hash_Table
{
private:
    unsigned int size;
    int filled;
    node* table[53];
public:
  Hash_Table();
  ~Hash_Table();
  void SetSize(unsigned int);
  unsigned int GetSize();
  void Factor();
  void Insert(int x);
  void   Delete(int x);
  void Print();
  bool Find(int x);
  int Hash(int x,int k);
};
