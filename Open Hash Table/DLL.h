#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
//Defining a struct Node
struct Node
{
string data;
Node* ptrNext;
Node* ptrPrev;
};
//Node* head;

class DLL
{
public:
Node* head;
DLL();
~DLL();

/*
pre: string to insert
post: insert a string to the end of the list
Return: Nothing
*/
void Insert(string str);


/*
pre: string to delete
post: delete a string
Return: Nothing
*/

void Delete(string str);


/*
pre: string to find
post: find a string
Return: true if string found and false otherwise
*/

bool Find(string str);
/*
pre: Nothing
post: print the list
Return: Nothing
*/

void Print();

/*
pre: string to find
Post: find a string
Return true if string found and false otherwise*/
bool FindFirst(string str);
};
