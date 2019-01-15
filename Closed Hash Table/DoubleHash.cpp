#include "DoubleHash.h"
Double_Hash_Table::Double_Hash_Table()
{
  SetSize(53);
  filled=0;
  int i;
  for(i=0;i<size;i++)
  {
    node* newNode=new node;
    newNode->data=-1;
    newNode->flag=false;
    table[i]=newNode;
  }
}
Double_Hash_Table::~Double_Hash_Table()
{
  int i;
  for(i=0;i<size;i++)
  delete table[i];
}


//A function to print the load_factor of the table
void Double_Hash_Table::Factor()
{
  int i;
  double sum=0;
  double load_factor;
  for(i=0;i<size;i++)
  {
    if((table[i]->data)!=-1)
    sum++;
  }
  load_factor=sum/size;
  cout<<"Load factor of hash table with double hashing is: "<<setprecision(2)<<load_factor<<endl;
}

//A function that returns the size of the hash table
unsigned int Double_Hash_Table::GetSize()
{
  return size;
}


//A function for setting the size of the hash table
void Double_Hash_Table::SetSize(unsigned int n)
{
  size=n;
}




//This is the function that implements the double hashing
int Double_Hash_Table::Hash(int x,int k)
{
  int hx=x%size;
  int hix=(hx+(k*(13-(x%13))))%size;
  return hix;
}
//A function for inserting an integer to the hash table
//pre: An integer to insert
//post: An integer inserted to the hash table if insertion was successful
//Return: Nothing

void Double_Hash_Table::Insert(int x)
{
	if(Find(x))
	{
	cout<<x<<" is already in the hash table with double hashing\n";
	}
	else
	{
  int loc=Hash(x,0);
  if(table[loc]->data==-1 && table[loc]->flag==false)
  {
    table[loc]->data=x;
    cout<<x <<" was inserted successfully to the hash table with double hashing\n";
  }

    else
    {
      int i=1;
      while(i<10 && table[loc]->data!=-1)
      {
        loc=Hash(x,i);
        i++;
      }
      if (table[loc]->data==-1)
      {
        table[loc]->data=x;
        cout<<x <<" was inserted successfully to the hash table with double hashing\n";
      }
      else
      cout<<x<<" was not inserted successfully to the hash table with double hashing\n";

    }
	}
  Factor();
}




/* This is a function to print the contents of the hash table
pre: no initial arguments
post: The contents of the hash table are printed
Return: Nothing */

void Double_Hash_Table::Print()
{
  cout<<"Hash table with double hashing: \n";
  int i;
  for(i=0;i<size;i++)
  {
    if(table[i]->data!=-1)
    cout<<i<<": "<<table[i]->data<<endl;

  }
}

/*This is a function to find a string in the hash table
pre: the string to find
post: a message printed in the screen whether the string was found or not
Return: Nothing
*/
bool Double_Hash_Table::Find(int x)
{
  int loc=Hash(x,0);
  if(table[loc]->data==x)
  return true;
  else
  {
    if(table[loc]->data==-1 && table[loc]->flag==false)
    return false;
    else
    {
      int i=1;
      while(i<10 && table[loc]->data!=x)
      {
        loc=Hash(x,i);
        i++;
      }
      if(table[loc]->data==x)
      return true;
      else
      return false;
    }
  }
}


/*This is a function to delete an integer from the hash table
pre: the integer to be deleted
post: a message printed in the screen whether the integer was deleteed or not
Return: Nothing
*/
void Double_Hash_Table::Delete(int x)
{
  int loc=Hash(x,0);
  if(table[loc]->data==x)
  {
    table[loc]->data=-1;
    table[loc]->flag=true;
    cout<<x<<" is deleted from hash table with double hashing\n";

  }
  else
  {
    int i=1;
    while(i<10 && table[loc]->data!=x)
    {
      loc=Hash(x,i);
      i++;
    }
    if(table[loc]->data==x)
    {
      table[loc]->data=-1;
      table[loc]->flag=true;
      cout<<x<<" was deleted successfully from the hash table with doulble hashing\n";
    }
    else
      cout<<x<<" was not deleted successfully from the hash table with double hashing\n";
  }
  Factor();
}
