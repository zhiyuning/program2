#ifndef TREE_H
#define TREE_H

#include <string>

class AVLNODE {
public:
  int key;
  AVLNODE *left;
  AVLNODE *right;
  int height;
  //set the rotation
  //int RotationNumber;


  AVLNODE();
  AVLNODE(int key);
  //AVLNODE(const int & key, AVLNODE *left, AVLNODE *right, int h=0)
  //  :key{key}, left{left}, right{right}, height{h} {}
  ~AVLNODE();

};

//function to get the height of node;
int height(AVLNODE *i);

//helper function of compare two subtree;
int compare(int a, int b);

//helper function that create a new node for insertion
//AVLNODE* newNode(int key);

//operation for left rotation
AVLNODE* LeftRotate(AVLNODE *node);

//operation for right rotation
AVLNODE* RightRotate(AVLNODE *node);

//get the balance factor
int balance(AVLNODE *N);

//the function to insert a key in the tree, and return the number of rotations each operation
int insert(AVLNODE * node, int key);

//a function to execute current print order
//void PrintTree(AVLNODE* node, string inputValue);

//a function to saerch the value in tree;
bool lookup(AVLNODE* node, int value);

//a helper function to generate the report both for insert and look up
void Report(int totalNum, double noperations, int RotationN);


#endif
