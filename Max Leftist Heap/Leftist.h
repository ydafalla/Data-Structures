#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
struct node
{
  node* leftChild;
  node* rightChild;
  unsigned int rank;
  int data;
};

class Leftist
{
private:
  node* root;

public:
  //This is the class constructor
  Leftist();

  //This is the class destructor
  ~Leftist();

  //This is a function to deallocate memory
  //pre: The function receives the root of the tree to deallocate
  //post: It clears the heap of allocated memory
  //return: The function has no return value
  void Flush(node*);

  //This is a function to get the root
  //pre: The function receives no arguments
  //post: The function returns the value of the root
  //return: The function returns the value of the root
  node* GetRoot();

  //This is a function to set the root
  //pre: The function receives the value of the new root as argument
  //post: The function sets the root to the new value
  //return: The function has no return value
  void SetRoot(node*);



  //This is a function to Build the heap using the insert operations
  //pre: The function has no arguments
  //post: The function inserts the elements in data.txt
  //return: The function has no return value
  void Buildheap();


  //This is a function to concate two leftist heaps together
  //This is a function to concate two leftist Heaps
  //pre: The function receives pointers to two leftist Heaps
  //post: The function concate the two leftist heaps that it received
  node* Concate(node*,node*);

  //This is a function for inserting a value to the leftist heap
  //pre: The function recives as an argument an integer to be inserted
  //post: The function inserts the input to the max leftistheap
  //return: The function has no return value
  void Insert(int);

  //This is a function to find the maximum element in the Leftist
  //pre: The function receives no arguments
  //post: The function prints the maximum element in the leftistheap
  //return: The function has no return value
  void FindMax();

  //This is a function for deleting the maximum element in the leftist heaps
  //pre: The function recives the root of the tree as argument
  //post: The function deletes the maximum element in the heap
  //return: The function has no return value
  void DeleteMax();

  //This is a function to calculate the rank of a node
  //pre: The function receives the node as an argument
  //post: The function calculates the rank of the given node
  //return: The function returns the rank of the node
  unsigned int Rank(node*);

  //This is a function to print the elements in the leftist in Preorder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in PreOrder
  //return: The function has no return value
  void PreOrder(node*);

  //This is a function to print the elements in the leftist in inorder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in InOrder
  //return: The function has no return value
  void InOrder(node*);

  //This is a function to print the elements in the leftist in Postorder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in PostOrder
  //return: The function has no return value
  void PostOrder(node*);

  //This is a function for calculating the height of the tree
  //pre: The function receives the root of the tree as an argument
  //post: The function calculates the height of the tree
  //return: The function returns the height of the tree
  int Height(node*);

  //This is a function to print the nodes of the leftist heap in levelOrder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in LevelOrder
  //return: The function has no return value
  void LevelOrder(node*);

  //This is a function to print the nodes of a given level
  //pre: The function receives the root of the tree as an argument and the levelnumber
  //post: The function prints a given level of the tree
  //return: The function has no return value
  void PrintLevel(node*,int);



};
