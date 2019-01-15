#include "DLL.h"
class Hash_Table
{
private:
    unsigned int size;
    DLL* table[17];
public:
  Hash_Table();
  ~Hash_Table();
  void SetSize(unsigned int);
  unsigned int GetSize();

  void Insert(string str);
  void   Delete(string str);
  void Print();
  void Find(string str);
  int Hash(string str);
};
