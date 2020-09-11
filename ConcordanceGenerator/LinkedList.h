//--------------------------------------------------------------------------
// File: LinkedList.h
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator
//
// DESCRIPTION:
// LinkedList: 
//  The header file for LinkedList class
//  Provides the set of variables and functions to create a linked list 
//---------------------------------------------------------------------------

#ifndef LINKED_LIST_
#define LINKED_LIST_

//---------------------------------------------------------------------------
// LinkedList: 
//  The header file for LinkedList class
//  Provides the set of variables and functions to create a linked list
//---------------------------------------------------------------------------

#include <string>
#include "ListNode.h"
using namespace std;

class LinkedList
{
private:
   ListNode* head;

public:
   LinkedList();
   ~LinkedList();
   void clear();
   ListNode* getHead();
   void insert(string preContext, string postContext);
};
#endif