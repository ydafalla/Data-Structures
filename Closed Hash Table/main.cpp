#include<fstream>
#include<cstdlib>
#include "DoubleHash.h"
int main()
{
  Hash_Table table;
  Double_Hash_Table table1;
  int x;
  unsigned int option=0;
  ifstream myfile;
  myfile.open("data.txt",ios::in);
  if(myfile!=NULL)
  {
  myfile>>x;
  while(!myfile.eof())
  {
  table.Insert(x);
  table1.Insert(x);
  myfile>>x;
  }
  }

while(option!=5)
{
cout<<"\nPlease choose one of the following commands:\n"
    <<"1. Insert\n"
    <<"2. Delete\n"
    <<"3. Find\n"
    <<"4. Print\n"
    <<"5. Exit\n";
cin>>option;
switch(option)
{
case 1:
	cout<<"\nPlease enter an integer to be inserted:\n";
	cin>>x;
	table.Insert(x);
  table1.Insert(x);
	break;

case 2:
        cout<<"\nPlease enter an integer to delete: \n";
        cin>>x;
        table.Delete(x);
        table1.Delete(x);
        break;

case 3:
				bool check;
        cout<<"\nPlease enter an integer to be found: \n";
        cin>>x;
        check=table.Find(x);
				if(check)
				cout<<x <<" was found in the hash table with quadratic probing\n";
				else
				cout<<x <<" was not found in the hash table with quadratic probing\n";
        check=table1.Find(x);
				if(check)
				cout<<x<<" was found in the hash table with double hashing\n";
				else
				cout<<x<<" was not found in the hash table with double hashing\n";
        break;

case 4:
	     table.Print();
       table1.Print();
	     cout<<endl;
	     break;

default:
	     break;
}
}
return 0;
}
