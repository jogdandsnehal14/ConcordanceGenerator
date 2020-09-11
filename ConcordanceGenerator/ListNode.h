//---------------------------------------------------------------------------
// File: Node.h
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator

// DESCRIPTION:
// ListNode: 
//  The header file for ListNode class
//  Provides the set of variables and functions to process a ListNode
//---------------------------------------------------------------------------

#include "LinkedList.h"
#ifndef LIST_NODE_
#define LIST_NODE_

//---------------------------------------------------------------------------
// ListNode: 
//  The header file for ListNode class
//  Provides the set of variables and functions to process a ListNode
//---------------------------------------------------------------------------

#include <string>
using namespace std;

class ListNode
{
private:
   string preContext;
   string postContext;
   ListNode* next;

   friend class LinkedList;

public:
   ListNode();
   ~ListNode();

   string getPreContext();
   string getPostContext();
   ListNode* getNext();
};
#endif