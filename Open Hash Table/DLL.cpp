//This version includes the Insert, Delete, Print, Find, Reverse List and Reverese Print Functions functions
#include "DLL.h"
//extern Node* head;
string first(string x)
{
string x2="";
int len=x.length();
if(len<8)
return x;
else
{
x2=x.substr(0,8);
return x2;
}
}

DLL::DLL()
{
head=NULL;
}

DLL::~DLL()
{
}
void DLL::Insert(string x)
{
Node* newNode=new Node;
newNode->data=x;
if(head==NULL)
{
newNode->ptrNext=NULL;
head=newNode;
head->ptrPrev=NULL;
}
else
{
newNode->ptrNext=head;
head->ptrPrev=newNode;
newNode->ptrPrev=NULL;
head=newNode;
}
}

//print all the elements of the list
void DLL::Print()
{
Node* pNav=head;
if(pNav==NULL)
{
cout<<"\n";
return ;
}
while(pNav!=NULL)
{
cout<<pNav->data<<" ";
pNav=pNav->ptrNext;
}
cout<<endl;
}


//Delete an element from the list
void DLL::Delete(string x)
{
Node* pNav=head;
//cout<<pNav<<"\t"<<pNav->data<<"\t"<<pNav->ptrNext<<"\t"<<pNav->ptrPrev<<endl;
if(pNav==NULL)
{
cout<<x<<" is not in the list \n";
return ;
}
while(pNav!=NULL && pNav->data!=x)
{
pNav=pNav->ptrNext;
}
if(pNav==NULL)
{
cout<<x<<" is not in the list\n";
return ;
}


if(pNav->ptrNext==NULL && pNav->ptrPrev==NULL)
{
delete pNav;
head=NULL;
return;
}
if(pNav->ptrPrev==NULL && pNav->ptrNext!=NULL)
{
head=pNav->ptrNext;
head->ptrPrev=NULL;
delete pNav;
return;
}
if(pNav->ptrNext!=NULL && pNav->ptrPrev!=NULL)
{
pNav->ptrPrev->ptrNext=pNav->ptrNext;
pNav->ptrNext->ptrPrev=pNav->ptrPrev;
delete pNav;
return ;
}

if(pNav->ptrNext==NULL && pNav->ptrPrev!=NULL)
{
pNav->ptrPrev->ptrNext=NULL;
delete pNav;
return ;
}

}

//Find an element in the list and return its address
bool DLL::Find(string x)
{
Node* pNav=head;
if(pNav==NULL)
{
return 0;
}
while(pNav!=NULL && pNav->data!=x)
{
pNav=pNav->ptrNext;
}
if(pNav!=NULL)
return 1;
else
return 0;
}

bool DLL::FindFirst(string x)
{
Node* pNav=head;
if(pNav==NULL)
return 0;
while(pNav!=NULL && first(pNav->data)!=first(x))
{
pNav=pNav->ptrNext;
}
if(pNav!=NULL)
return 1;
else
return 0;
}
