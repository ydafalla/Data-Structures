#include "Hash.h"
class Double_Hash_Table
{
private:
    unsigned int size;
    int filled;
    node* table[53];
public:
  Double_Hash_Table();
  ~Double_Hash_Table();
  void SetSize(unsigned int);
  unsigned int GetSize();
  void Factor();
  void Insert(int x);
  void   Delete(int x);
  void Print();
  bool Find(int x);
  int Hash(int x,int k);
};
