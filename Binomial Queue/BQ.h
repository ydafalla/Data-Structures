#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

struct node
{
  int data;
  int order;
  node* firstChild;
  node* rSibling;
  node* lSibling;
};

class BQ
{
  private:
    node* root;

  public:
    //This is the class constructor
    BQ();

    //This is the class destructor
    ~BQ();


    //This is a function to deallocate memory
    void Flush(node*);
    
    //This is a function to return the root value
    node* GetRoot();

    //This is a function to set the value of the root
    void SetRoot(node*);

    //This is a function to return the number of tree in the queue
    int Size(node*);

    //This is a function to append an element to the end of the list
    node* Add(node*,node*);

    //This is the function to insert an element to the binomial queue
    void Insert(node*,int);

    //This is a function to merge two binomial trees
    node* Merge(node*,node*);

    //This is a function to concate two binomial queues
    node* Concate(node*,node*);

    //This is a function to delete the minimum element in the binomial queues
    void DeleteMin(node*);

    //This is a function to find the minimum element in the Binomial queue
    int FindMin(node*);

    //This is a function to print the elements of the binomial queues
    void Print(node*);

    //This is a function that prints a binomial tree in level order
    void PrintBT(node*);
};
