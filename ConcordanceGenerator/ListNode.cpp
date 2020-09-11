//---------------------------------------------------------------------------
// File: ListNode.cpp
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator

// DESCRIPTION:
// ListNode: 
//  The cpp file for ListNode class
//  Provides the set of variables and functions to process a ListNode
//---------------------------------------------------------------------------

#include "ListNode.h"

/** The list node constructor. */
ListNode::ListNode(): preContext(), postContext(), next(nullptr)
{
}

/** Gets the previous context
   */
string ListNode::getPreContext()
{
   return preContext;
}

/** Gets the post context
   */
string ListNode::getPostContext()
{
   return postContext;
}

/** Gets the next node
   */
ListNode* ListNode::getNext()
{
   return next;
}

/** The list node desctructor
. */
ListNode::~ListNode()
{
}