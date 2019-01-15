#include<iostream>
#include<fstream>
using namespace std;

struct node
{
  node* leftChild;
  node* rightChild;
  int key;
};


//This is a max skewheap class
class SkewHeap
{
private:
  node* root;


public:
  //This is the constructor of the class
  SkewHeap();

  //This is the destructor of the class
  ~SkewHeap();

  //This is a function to deallocate the tree from memory
  //pre: The function receives the root of the tree to deallocate
  //post: It clears the heap of allocated memory
  //return: The function has no return value
  void Flush(node*);

  //This is a function to set the value of the root
  //pre: The function receives the value of the new root as argument
  //post: The function sets the root to the new value
  //return: The function has no return value
  void SetRoot(node*);

  //This is a function to get the value of the root
  //pre: The function receives no arguments
  //post: The function returns the value of the root
  //return: The function returns the value of the root
  node* GetRoot();

  //This is a function to concate two Skew Heaps
  //pre: The function receives pointers to two skew Heaps
  //post: The function concate the two skew heaps that it received
  //return: The function returns the root of the new skew heap after concate
  node* Concate(node*,node*);

  //This is a function to build the skewheap using the insert operations
  //pre: The function has no arguments
  //post: The function inserts the elements in data.txt
  //return: The function has no return value
  void Buildheap();

  //This is a function to insert elements to the max SkewHeap
  //pre: The function recives as an argument an integer to be inserted
  //post: The function inserts the input to the max skewheap
  //return: The function has no return value
  void Insert(int);

  //This is a function to return the maximum element of the max skewheap
  //pre: The function receives no arguments
  //post: The function prints the maximum element in the skewheap
  //return: The function has no return value
  void FindMax();

  //This is a function to delete the maximum element of the Heap
  //pre: The function recives the root of the tree as argument
  //post: The function deletes the maximum element in the heap
  //return: The function has no return value
  void DeleteMax(node*);

  //This is a function to print the elements in the skewheap in Preorder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in PreOrder
  //return: The function has no return value
  void PreOrder(node*);

  //This is a function to print the elements in the skewheap in inorder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in InOrder
  //return: The function has no return value
  void InOrder(node*);

  //This is a function to print the elements in the skewheap in Postorder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in PostOrder
  //return: The function has no return value
  void PostOrder(node*);

  //This is a function to print the elements in the skewheap in LevelOrder
  //pre: The function receives the root of the tree as an argument
  //post: The function prints the tree in LevelOrder
  //return: The function has no return value
  void LevelOrder(node*);

  //This is a function to calculate the height of the tree
  //pre: The function receives the root of the tree as an argument
  //post: The function calculates the height of the tree
  //return: The function returns the height of the tree
  int Height(node*);

  //This is a function to print the nodes of a given Level
  //pre: The function receives the root of the tree as an argument and the levelnumber
  //post: The function prints a given level of the tree
  //return: The function has no return value
  void PrintLevel(node*,int);

};
