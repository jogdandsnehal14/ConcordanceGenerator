//---------------------------------------------------------------------------
// File: Node.h
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator

// DESCRIPTION:
// Node: 
//  The header file for Node class
//  Provides the set of variables and functions to process a Node
//---------------------------------------------------------------------------

#include "LinkedList.h"
#ifndef NODE_
#define NODE_

//---------------------------------------------------------------------------
// Node: The header file for Node class
//  Provides the set of variables and functions to process a Node
//---------------------------------------------------------------------------
class Node
{
private:
   string key;
   Node* left;
   Node* right;
   LinkedList* list;

   friend class BSTree;

public:
   Node();
   ~Node();
}; // end Node
#endif