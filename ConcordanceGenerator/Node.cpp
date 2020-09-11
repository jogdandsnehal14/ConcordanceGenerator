//---------------------------------------------------------------------------
// File: Node.cpp
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator

// DESCRIPTION:
// Node: 
//  The class file for Node class
//  Provides the implementation of variables and functions to process a Node
//---------------------------------------------------------------------------

#include "Node.h"

/** The node constructor
.  */
Node::Node() : key(), left(nullptr), right(nullptr), list(nullptr)
{
} // end default constructor

/** The node desctructor 
   */
Node::~Node()
{
   delete left;
   delete right;
   delete list;
}