#include<iostream>
using namespace std;
struct node
{
  int minSecond;
  node* Parent;
  int minThird;
  int key;
  bool tag; //True is leafNode False is interior node
  node* First;
  node* Second;
  node* Third;
};

class TwoThreeTree
{
private:
  node* root;

public:
  //This is the class constructor
  TwoThreeTree();

  //This is the class destructor
  ~TwoThreeTree();

  //This is a function to flush the TwoThreeTree
  //pre: The function receives the root of the tree as an input argument
  //post: The function clears the heap
  //return: The function has no return value
  void Flush(node*);

  //This is a function to return the value of root
  //pre: The function receives no argument
  //post: The function return the root of th  Tree
  //return: The root of the tree is returned
  node* GetRoot();

  //This is a function to set the value of root
  //pre: The function receives a pointer to node as argumetn
  //post: The function sets the root to the input argument
  //return: The function has no return value
  void SetRoot(node*);

  //This is a function that returns the parent of a specific node
  //pre: The function receives an int and a node*
  //post: The function returns the parent for that specific leaf node1
  //return: The function return a pointer to node
  node* FindParent(int,node*);

  //This is a function that returns the address of the specific node
  //pre: The function receives an integer and a node* as an argument
  //post: The function returns the address of the specific leaf node
  //return: The function returns the address of the leaf node if found
  node* FindNode(int,node*);

  //This is a function that performs search operation
  //pre: The function receives an integer and a pointer to node as argument
  //post: The function searches for a specifc value in the TwoThreeTree
  //return: The function returns true if value found, false otherwise
  bool Search(int,node*);

  //This is a function that finds the minimum element
  //pre: The function receives a pointer to node
  //post: The function returns the minimum element in the Tree
  //return: The function returns an integer value indicating the minimum element
  int Min(node*);

  //This is the function that finds the maximum element
  //pre: The function receives a pointer to node as an argument
  //post: The function returns the maximum element in the Tree
  //return: The function returns an integer indicating the maximum value in the tree
  int Max(node*);

  //This is a function to create a leafNode
  //pre: The function receives an integer as an argument
  //post: The function creates a new leaf node with the key being the integer
  //return: The function returns the address of the created node
  node* Leaf(int);

  //This is a function to create an InteriorNode
  //pre: The function receives no input argument
  //post: The function creates a new Interior node
  //return: The function returns the address of the created node
  node* Interior();

  //This is the function to insert an element to the TwoThreeTree
  //pre: The function receives an integer and a node pointer as an argument
  //post: The function inserts a new node with key int to the root of the tree in node*
  //return: The function has no return value
  void Insert(int,node*);


  //This is a function to attach two nodes to a parent node
  //pre: The function receives four node* as argument
  //Post the function attach the first two arguments to the third argument
  //return: The function has no return value
  void Attach(node*,node*,node*,node*);


  //This is the function to delete an element from the TwoThreeTree
  //pre: The function receives the integer to delete
  //post: The received integer is deleted from the tree if it exists
  //return: The function has no return value
  void Delete(int,node*);

  //This is a function to delete the minimum element from the TwoThreeTree
  //pre: The function receives the root of the Tree
  //post: The function deletes the minimum element in the Tree
  //return: The function has no return value
  void DeleteMin(node*);

  //This is a function to delete the maximum element from the TwoThreeTree
  //pre: The function recives the root of the Tree
  //post: The function deletes the maximum element in the Tree
  //return: The function has no return value
  void DeleteMax(node*);

  //This is a function to delete a node from the 2-3 Tree
  //pre: the function receives to node pointers for a node and its Parent
  //post: The function deletes the node from the Tree
  //return: The function has no return value
  void DeleteNode(node*,node*);

  //This is a function to update the parent of a node
  //pre: The function input argument is the node that needs Update
  //post: The function updates the minsecond and minthird fields
  //return: The function has no return value
  void Update(node*);


  //This is a function to print the 2-3 tree
  //pre: The function receives the root as argument
  //post: The function prints the leaf level of the Tree
  //return: The function has no return value
  void LevelOrder(node*);

};
