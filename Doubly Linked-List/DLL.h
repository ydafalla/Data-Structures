#include<iostream>
#include<cstdlib>
using namespace std;
//Defining a struct Node
struct Node
{
int data;
Node* ptrNext;
Node* ptrPrev;
};
//Node* head;

class DLL
{
public:
DLL();
~DLL();

/*
pre: integer to insert, pointer to head
post: insert an integer
Return: Nothing
*/ 
void Insert(Node* ptrhead,int x);


/*
pre: integer to delete, pointer to head
post: delete an integer
Return: Nothing
*/

void Delete(Node* ptrhead,int x);


/*
pre: integer to find, pointer to head of the list
post: find an integer
Return: Nothing
*/

void Find(Node* ptrhead,int x);


/*
pre: head of the list
post: print the list
Return: Nothing
*/

void Print(Node* ptrhead);


/*
pre: head of the list
post: print the list in reverse order
Return: nothing
*/

void ReversePrint(Node* ptrhead);

/*
pre: head of the list
post: reverse the list
Return: nothing
*/

void ReverseList(Node* ptrhead);

};
