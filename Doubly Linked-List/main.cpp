#include<fstream>
#include<cstdlib>
#include "DLL.h"
Node* head;
int main()
{
DLL list;
int x,option=0,number;
ifstream myfile;
myfile.open("data.txt",ios::in);
if(myfile!=NULL)
{
myfile>>x;
while(!myfile.eof())
{
list.Insert(head,x);
myfile>>x;
}
}
while(option!=7)
{
cout<<"\nPlease choose one of the following commands:\n"
    <<"1. Insert\n"
    <<"2. Delete\n"
    <<"3. Find\n"
    <<"4. Print\n"
    <<"5. Reverse List\n"
    <<"6. Reverse Print\n"
    <<"7. Exit\n";
cin>>option;
switch(option)
{
case 1:
	cout<<"\nPlease enter the number you want to insert: ";
	cin>>number;
	list.Insert(head,number);
	break;

case 2:
        cout<<"\nPlease enter the number you want to delete: ";
        cin>>number;
        list.Delete(head,number);
        break;

case 3:
        cout<<"\nPlease enter the number you want to find: ";
        cin>>number;
        list.Find(head,number);
        break;

case 4:
	cout<<"\nHere is the list: ";
	list.Print(head);
	cout<<endl;
	break;

case 5:
	cout<<"\nReversing the list\n";
	list.ReverseList(head);
	break;

case 6:
	cout<<"\nList printed in reverse order: ";
	list.ReversePrint(head);
	cout<<endl;
	break;

default:
	break;

}
//system("clear");
}
return 0;
}

