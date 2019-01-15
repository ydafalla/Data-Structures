//This version includes the Insert, Delete, Print, Find, Reverse List and Reverese Print Functions functions
#include "DLL.h"
extern Node* head;

DLL::DLL()
{
head=NULL;
}

DLL::~DLL()
{
}
void DLL::Insert(Node* ptrhead,int x)
{
if(ptrhead==NULL)
{
Node* newNode=new Node;
newNode->data=x;
newNode->ptrNext=NULL;
head=newNode;
head->ptrPrev=NULL;
}
else
{
if(ptrhead->ptrNext==NULL)
{
Node* newNode=new Node;
newNode->data=x;
newNode->ptrNext=NULL;
newNode->ptrPrev=ptrhead;
ptrhead->ptrNext=newNode;
}
else
{
Insert(ptrhead->ptrNext,x);
}
}
}


//print all the elements of the list
void DLL::Print(Node* ptrhead)
{
if(ptrhead==NULL)
{
cout<<"empty list\n";
return ;
}
while(ptrhead!=NULL)
{
cout<<ptrhead->data<<" ";
ptrhead=ptrhead->ptrNext;
}
}


//Delete an element from the list
void DLL::Delete(Node* ptrhead,int x)
{
if(ptrhead==NULL)
{
cout<<x<<" is not in the list \n";
return;
}
if(ptrhead->data==x)
{
if(ptrhead->ptrNext!=NULL && ptrhead->ptrPrev!=NULL)
{
ptrhead->ptrPrev->ptrNext=ptrhead->ptrNext;
ptrhead->ptrNext->ptrPrev=ptrhead->ptrPrev;
delete ptrhead;
}
else
{
if(ptrhead->ptrPrev==NULL && ptrhead->ptrNext==NULL)
{
head=NULL;
delete ptrhead;
}
else
{
if(ptrhead->ptrPrev==NULL)
{
head=ptrhead->ptrNext;
head->ptrPrev=NULL;
delete ptrhead;
}
else
{
ptrhead->ptrPrev->ptrNext=NULL;
delete ptrhead;
}
}
}
}
else
{
Delete(ptrhead->ptrNext,x);
}
}

//Find an element in the list and return its address
void DLL::Find(Node* ptrhead,int x)
{

if(ptrhead==NULL)
{
cout<<"\nThe List is empty\n";
return;
}
while(ptrhead!=NULL && ptrhead->data!=x)
{
ptrhead=ptrhead->ptrNext;
}
if(ptrhead!=NULL)
cout<<endl<<x<<" is in the list\n";
else
cout<<endl<<x<<" is not in the list\n";
/*
Node* pNav=ptrhead;
if(pNav==NULL)
{
cout<<"The list is empty\n";
return;
}
while(pNav!=NULL)
{
if(pNav->data==x)
{
cout<<"\n"<<x<<" is on the list\n";
break;
}
pNav=pNav->ptrNext;
}
if(pNav==NULL)
cout<<endl<<x<<" is not on the list\n";*/
}

//The reverse print function
void DLL::ReversePrint(Node* ptrhead)
{
if(ptrhead==NULL)
return ;
ReversePrint(ptrhead->ptrNext);

cout<<ptrhead->data<<" ";
}

void DLL::ReverseList(Node* ptrhead)
{
if(ptrhead==NULL)
{
cout<<"The list is empty\n";
return;
}

Node* temp=ptrhead->ptrNext;
ptrhead->ptrNext=ptrhead->ptrPrev;
ptrhead->ptrPrev=temp;

if(ptrhead->ptrPrev==NULL)
{
head=ptrhead;
return;
}
else
ReverseList(ptrhead->ptrPrev);
}


