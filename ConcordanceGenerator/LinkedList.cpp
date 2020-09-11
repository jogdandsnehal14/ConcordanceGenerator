//--------------------------------------------------------------------------
// File: LinkedList.cpp
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator
//
// DESCRIPTION:
// LinkedList: 
//  The header file for LinkedList class
//  Provides the set of variables and functions to create a linked list 
//---------------------------------------------------------------------------

#include "LinkedList.h"

/** The linked list constructor
   */
LinkedList::LinkedList():head(nullptr)
{
}

/** Gets the head node of the linked list */
ListNode* LinkedList::getHead()
{
   return head;
}

/** inserts a new node into the linked list */
void LinkedList::insert(string preContext, string postContext)
{
   ListNode* node = new ListNode();
   node->preContext = preContext;
   node->postContext = postContext;
   node->next = nullptr;

   if (head == nullptr)
   {
      head = node;
      return;
   }

   ListNode* current = head;
   while (current->next != nullptr) current = current->next;
   current->next = node;
}

/** Linked list destructor */
LinkedList::~LinkedList()
{
   clear();
}

/** Removes all the nodes from the linked list */
void LinkedList::clear()
{
   ListNode* nodeToDeletePtr = head;
   while (head != nullptr)
   {
      head = head->next;

      // Return node to the system
      nodeToDeletePtr->next = nullptr;
      delete nodeToDeletePtr;

      nodeToDeletePtr = head;
   } // end while
}  // end clear