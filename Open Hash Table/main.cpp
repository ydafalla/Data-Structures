#include<fstream>
#include<cstdlib>
#include "Hash.h"

int main()
{
  Hash_Table table;
  string x;
  unsigned int option=0;
  ifstream myfile;
  myfile.open("data.txt",ios::in);
  if(myfile!=NULL)
  {
  //myfile>>size;
  table.SetSize(17);
  while(!myfile.eof())
  {
  myfile>>x;
  table.Insert(x);
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
	cout<<"\nPlease enter a string to be inserted:\n";
	cin>>x;
	table.Insert(x);
	break;

case 2:
        cout<<"\nPlease enter a string to delete: \n";
        cin>>x;
        table.Delete(x);
        break;

case 3:
        cout<<"\nPlease enter a string to be found: \n";
        cin>>x;
        table.Find(x);
        break;

case 4:
	table.Print();
	cout<<endl;
	break;

default:
	break;

}

}
return 0;
}
