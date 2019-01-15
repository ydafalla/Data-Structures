#include<iostream>
using namespace std;
struct node
{
  int data;
  node* leftNode;
  node* rightNode;
};



class BST
{
private:
  node* root;

public:

  //BST class constructor
  BST();

  //BST class destructor
  ~BST();

  //This is a function to clean the Tree
  //pre: This function recives the root as argument
  //post: The function cleans the Tree
  //return: The function has no return value
  void Flush(node*);

  //This is a function to return the root of the tree
  //pre: This function receives no arguments
  //post: The root of the tree is returned
  //return: The function returns the root of the tree
  node* GetRoot();

  //This is a function to set the value of the root of the tree
  //pre: This function receives the root of tree as argument
  //post: The function has no return value
  //return: The function sets the root of the tree
  void SetRoot(node*);

  //This is a function to insert data to the binary search tree
  //pre: the function receives an int data
  //post: The function inserts the received data to the binary search tree
  //return: The function returns nothing
  node* Insert(node*,int);


  //This is a function that deletes the minimum node in the binary tree
  //pre: The function receives a pointer to the tree
  //post: The function deletes the minimum element
  //return: The function returns nothing
  node* DeleteMin(node*);

  //This is a function that deletes the maximum node in the binary tree
  //pre: The function receives a pointer to the tree
  //post: The function deletes the maximum element
  //return: The function returns nothing
  node* DeleteMax(node*);

  //This is a function that returns the address of the minimum node in the binary tree
  //pre: The function receives the root of the tree as arguments
  //Post: The function returns the address of the minimum node
  //return: The address of the minimum node
  node* FindMin(node*);

  //This is the function that deletes a node from the tree
  //pre: The function receives as an argument the element to be deleted and the root of the Tree
  //post: The function deletes an element from the tree if found
  //return: The function returns nothing
  node*  Delete(int,node*);


  //This is a function that looks for a specific node in the binary tree and returns the address of the node or null otherwise
  //pre: The function receives as arguments the element to find and the root
  //post: The function returns the address of the node
  //return: The function returns the address of the node
  node* Find(int,node*);




  //This is a function to find the minimun value in the tree
  //Pre: This function receives the address of the root as argument
  //Post: The address of minimum node is returned
  //return: The function returns nothing
  void FindMinimum(node*);


  //This is a function to find the maximum value in the tree
  //Pre: This function receives no arguments
  //Post: The maximum element in the tree is printed
  //return: The function returns nothing
  void FindMax(node*);


  //This is a function to traverse the binary search tree inorder
  //pre: The function receives no arguments
  //post: The tree is traversed in order
  //return: The function returns nothing
  void Inorder(node*);

  //This is a function to traverse the binary search tree preorder
  //pre: The function receives no arguments
  //post: The tree is traversed in preorder
  //return: The function returns nothing
  void Preorder(node*);

  //This is a function to traverse the binary search tree postorder
  //pre: The function receives no arguments
  //post: The tree is traversed in postorder
  //return: The function returns nothing
  void Postorder(node*);
};
