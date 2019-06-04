#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;

AVLNODE::AVLNODE(){
  AVLNODE* node=new AVLNODE();
  node->key=0;
  node->left=NULL;
  node->right=NULL;
  node->height=1;
}


AVLNODE::AVLNODE(int key){
  AVLNODE* node=new AVLNODE();
  node->key=key;
  node->left=NULL;
  node->right=NULL;
  node->height=0;
}

int height(AVLNODE *i){
  if(i==NULL){
    return 0;
  }
  return i->height;
}

int compare(int a, int b){
  return (a>b)? a : b;
}

//AVLNODE* newNode(int key){
//  AVLNODE* node=new AVLNODE();
//  node->key=key;
//  node->left=NULL:
//  node->right=NULL;
//  node->height=1;
//
//  return node;
//}


AVLNODE* LeftRotate(AVLNODE *node){
  AVLNODE *subnodeL = node->right;
  AVLNODE *subnodeR = subnodeL->left;

  subnodeL->left=node;
  node->right=subnodeR;

  node->height=compare(height(node->left),height(node->right)+1);
  subnodeL->height=compare(height(subnodeL->left),height(subnodeL->right)+1);

  return subnodeL;
}


AVLNODE* RightRotate(AVLNODE *node){
  AVLNODE *subnodeL = node->left;
  AVLNODE *subnodeR = subnodeL->right;

  subnodeL->right=node;
  node->left=subnodeR;


  node->height=compare(height(node->left),height(node->right))+1;
  subnodeL->height=compare(height(subnodeL->left),height(subnodeL->right))+1;

  return subnodeL;
}



int balance(AVLNODE *N){
  if(N==NULL)
    return 0;
  return height(N->left)-height(N->right);
}



int insert(AVLNODE* node, int key){
  if(node->key==0){
    node->key=key;
    return 0;
  }
  AVLNODE* Temp=new AVLNODE(key);

  while(1){
    if((key<node->key)&&(node->left!=NULL)){
      node=node->left;
      continue;
    }
    else if((key>node->key)&&(node->left==NULL)){
      node->left=Temp;
      break;
    }
    else if((key>node->key)&&(node->right!=NULL)){
      node=node->right;
      continue;
    }
    else
    {
      node->right=Temp;
      break;
    }

  }


  //insert into left subtree

  //if equal element inserted, do nothing and return
  //else if(key==node->key){
  //  return;
  //}

  //update the current height of AVL tree
  node->height=compare(height(node->left), height(node->right))+1;

  int RotationCounter=0;

  //check if the tree need rotation
  int BalanceFactor=balance(node);

  //Right rotate once
  if(BalanceFactor>1 && key<node->left->key){
    RightRotate(node);
    RotationCounter+=1;
  }

  //Left Rotate once
  if(BalanceFactor<-1 && key>node->right->key){
    LeftRotate(node);
    RotationCounter+=1;
  }

  //First left and then right
  if(BalanceFactor>1 && key>node->left->key){
    node->left=LeftRotate(node->left);
    RightRotate(node);
    RotationCounter+=2;
  }

  //first right and the left
  if(BalanceFactor<-1 && key<node->right->key){
    node->right=RightRotate(node->right);
    LeftRotate(node);
    RotationCounter+=2;
  }
  return RotationCounter;

}



bool lookup(AVLNODE* node, int value){

  if(node==NULL){
    return false;
  }
  else if(value<node->key){
    return lookup(node->left, value);
  }
  else if(value>node->key){
    return lookup(node->right, value);
  }else

  return true;
}





void Report(int totalNum, double noperations, int RotationN){
  cout<<"Visited "<<totalNum<<" ("
  << double(totalNum)/noperations <<") "<<"nodes and performed "<<RotationN<<" ("
  << double(RotationN)/noperations<<") rotations."<<endl;
}




//void PrintTree(AVLNODE* node, string inputValue){
//}
