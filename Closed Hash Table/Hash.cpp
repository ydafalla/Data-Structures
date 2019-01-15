#include "Hash.h"
Hash_Table::Hash_Table()
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
Hash_Table::~Hash_Table()
{
  int i;
  for(i=0;i<size;i++)
  delete table[i];

}


//A function to print the load_factor of the table
void Hash_Table::Factor()
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
  cout<<"Load factor of hash table with quadratic probing is: "<<setprecision(2)<<load_factor<<endl;
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

//This is the function that implements the hashing
int Hash_Table::Hash(int x,int k)
{
  int hx=x%size;
  int hix=(hx+(k*k))%size;
  return hix;
}


//This is the function that implements the double hashing
/*int Hash_Table::DoubleHash(int x,int k)
{
  int hx=x%size;
  int hix=(hx+(k*(5-(x%5))))%size;
  return hix;
}*/
//A function for inserting an integer to the hash table
//pre: An integer to insert
//post: An integer inserted to the hash table if insertion was successful
//Return: Nothing

void Hash_Table::Insert(int x)
{
	if(Find(x))
	{
		cout<<x <<" is already in the hash table with quadratic probing\n";
	}
	else
	{
  int loc=Hash(x,0);
  if(table[loc]->data==-1 && table[loc]->flag==false)
  {
    table[loc]->data=x;
    cout<<x <<" was inserted successfully to the hash table with quadratic probing\n";
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
        cout<<x <<" was inserted successfully to the hash table with quadratic probing\n";
      }
      else
      cout<<x<<" was not inserted successfully to the hash table with quadratic probing\n";

    }
	}
  Factor();
}




/* This is a function to print the contents of the hash table
pre: no initial arguments
post: The contents of the hash table are printed
Return: Nothing */

void Hash_Table::Print()
{
  cout<<"Hash table with quadratic probing: \n";
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
bool Hash_Table::Find(int x)
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
    if (table[loc]->data==x)
    {
      return true;
    }
    else
     return false;
    }
  }
}


/*This is a function to delete an integer from the hash table
pre: the integer to be deleted
post: a message printed in the screen whether the integer was deleted or not
Return: Nothing
*/
void Hash_Table::Delete(int x)
{
  int loc=Hash(x,0);
  if(table[loc]->data==x)
  {
    table[loc]->data=-1;
    table[loc]->flag=true;
    cout<<x<<" is deleted from hash table with quadratic probing\n";
  }
  else
  {
    int i=1;
    while(i<10 && table[loc]->data!=x)
    {
      loc=Hash(x,i);
      i++;
    }
    if (table[loc]->data==x)
    {
      table[loc]->data=-1;
      table[loc]->flag=true;
      cout<<x <<" was deleted successfully from the hash table with quadratic probing\n";
    }
    else
    cout<<x<<" was not deleted susccessfully from the hash table with quadratic probing\n";

  }
  Factor();
}
