#include "Hash.h"
Hash_Table::Hash_Table()
{
  SetSize(17);
  int i;
  for(i=0;i<size;i++)
  table[i]=NULL;
}
Hash_Table::~Hash_Table()
{

}


//A function that returns the size of the hash table
unsigned int Hash_Table::GetSize()
{
  return size;
}


//A function for setting the size of the hash table
void Hash_Table::SetSize(unsigned int n)
{
  size=n;
}


//A function for inserting a string to the hash table
//pre: A string to insert
//post: A string inserted to the hash table
//Return: Nothing

void Hash_Table::Insert(string str)
{
  int loc=Hash(str);
  if(table[loc]==NULL)
  {
    DLL* newList=new DLL;
    newList->Insert(str);
    table[loc]=newList;
    cout<<str <<" was inserted successfully\n";
  }
  else
  {
    if(!table[loc]->Find(str))
    {
		if(table[loc]->FindFirst(str))
		cout<<str<<" is duplicated, can't be added to the table\n";
		else
		{
    table[loc]->Insert(str);
    cout<<str<<" was inserted successfully\n";
		}
  }
  else
  cout<<str<<" was not inserted successfully, it is already in the table\n";
  }
}


/* This is a function to print the contents of the hash table
pre: no initial arguments
post: The contents of the hash table are printed
Return: Nothing */

void Hash_Table::Print()
{
  int i;
  for(i=0;i<size;i++)
  {
    if(table[i]==NULL)
    cout<<i<<": "<<endl;
    else
    {
      cout<<i<<": ";
      table[i]->Print();
    }

  }
}

/*This is a function to find a string in the hash table
pre: the string to find
post: a message printed in the screen whether the string was found or not
Return: Nothing
*/
void Hash_Table::Find(string str)
{
  int loc=Hash(str);
  if(table[loc]==NULL)
  cout<<str<<" is not found in the hash table\n";
  else
  {
    if(table[loc]->Find(str))
    cout<<str<< " is found in the hash table\n";
    else
    cout<<str<<" is not found in the hash table\n";
  }
}


/*This is a function to delete a string from the hash table
pre: the string to be deleted
post: a message printed in the screen whether the string was deleteed or not
Return: Nothing
*/
void Hash_Table::Delete(string str)
{
  int loc=Hash(str);
  if(table[loc]==NULL)
  cout<<str<<" is not found in the hash table\n";
  else
  {
    if(table[loc]->Find(str))
    {
    table[loc]->Delete(str);
    cout<<str<< " has been deleted from the hash table\n";
    }
    else
    cout<<str<<" is not found in the hash table\n";
  }
}

//This is the function that implements the hashing
int Hash_Table::Hash(string str)
{
  int len=str.length();
  int i,j,result=0,factor;
  string::iterator it=str.begin();
  for (i=0 ; i<8 && it!=str.end(); ++it,i++)
  {
  factor=1;
  for(j=0;j<i;j++)
  {
  factor*=10;
  }
  result+=int(*it)*factor;
  }
  return result%size;
}
