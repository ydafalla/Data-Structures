#include <iostream>
#include <cmath>
using namespace std;

class MaxMin
{
private:
  int array[500];
  int last;

public:
  //This is the constructor
  MaxMin();

  //This is the destructor
  ~MaxMin();



  //This is a method for inserting an item to the heap
  //pre: The function receives a data to be inserted to the heap
  //post: The function inserts the element to the heap
    //return: The function has no return value
  void Insert(int);

  //To check if a number is a power of two or not
  //pre: The function receives a number to check if it is PowerOfTwo
  //post: Returns wheteher a number is a power of two
  //return: The function returns a bool to indicate whether a number is PowerOfTwo
  bool PowerOfTwo(unsigned int);

  //This is a method for returning whether the node is minNode or not
  //pre: The function receives a position of the minNode
  //post: Returns whether a node is minnode or maxnode
  //return: The function returns a bool to indicate whether a node is minnode or maxnode
  bool minNode(int);

  //This is a method for deleting the minimum element in the MaxMin heap
  //pre: The function has no input argument
  //post: Delete the minimum element in the heap
  //return: The function has no return value
  void DeleteMin();

  //This is a method for swapping two array indices
  //pre: The function receive two indices as arguments
  //post: Two elements in the heap are swapped
  //return: The function has no return value
  void Swap(unsigned int,unsigned int);

  //This is a method for finding the second smallest element in the MaxMin heap
  //pre: The function has no input value
  //post: The function returns the second minimum element in the heap
  //return: The function returns the second minimun in the subheap
  int SecondMin(int);

  //This is a method for finding the second largest element in the maxmin heap
  //pre: The function has no input value
  //post: The function returns the second maximum element in the heap
  //return: The function returns the second maximum in the subheap
  int SecondMax(int);

  //This is a method to patch a tree and it receives the index of the tree to patch
  //pre: The function receives an input which is the position of the hole
  //post: The function patches the hole in the Buildheap
  //return: The function has no return value
  void Patch(int);

  //This is a method to patch a Maxmin heap and it receives the starting index of the subtree
  //pre: The function receives an input which is the position of the hole
  //post: The function patches the hole in the Buildheap
  //return: The function has no return value
  void PatchMax(int);

  //This is a method for finding the minimum element in the MaxMin heap
  //pre: The function has no input value
  //post: The function prints the minimum value in the heap
  //return: The function has no return value
  void FindMin();

  //This is a method for finding the maximum element in the MaxMin heap
  //pre: The function has no input value
  //post: The function prints the maximum value in the heap
  //return: The function has no return value
  void FindMax();

  //This is a method for deleting the maximum element in the heap
  //pre: The function has no input argument
  //post: Delete the maximum element in the heap
  //return: The function has no return value
  void DeleteMax();

  //This is a method for printing out the elements of the MixMax heap in level order traversal
  //This is a method for printing out the elements of the MixMax heap in level order traversal
  //pre: The function has no input argument
  //post: prints the heap in LevelOrder
  void LevelOrder();
};
