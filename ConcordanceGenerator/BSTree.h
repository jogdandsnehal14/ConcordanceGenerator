//---------------------------------------------------------------------------
// File: BSTree.h
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator
//
// DESCRIPTION:
// BSTree: 
//  The header file for BSTree class
//  Provides the set of variables and functions to process 
//  a Binary Search Tree
//---------------------------------------------------------------------------

#ifndef BSTREE_
#define BSTREE_

//---------------------------------------------------------------------------
// BSTree: The header file for BSTree class
// Provides the set of variables and functions to process 
// a Binary Search Tree
//---------------------------------------------------------------------------

#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

class BSTree
{
private:
   Node* root;
   int maxContextLength;
   Node* createNode(string key, string preContext, string postContext);
   void inorderTraversal(Node* tree) const;

public:
   BSTree();
   ~BSTree();
   void clear(Node* node);
   void insert(string key, string preContext, string postContext);
   bool isEmpty() const;
   void print() const;
}; 
#endif