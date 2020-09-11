//---------------------------------------------------------------------------
// File: BSTree.cpp
// Author: Snehal Jogdand
// Date: 11/21/2019
// Program 4: Concordance Generator
//
// DESCRIPTION:
// BSTree: 
//  The cpp file for BSTree class
//  Provides the set of variables and functions to process 
//  a Binary Search Tree
//---------------------------------------------------------------------------

#include "BSTree.h"
#include <iostream>

/** The binary search tree default constructor
    */
BSTree::BSTree(): root(nullptr), maxContextLength(0)
{
}

/** Inserts the given context information into the tree.
    @pre  None.
    @param key  The context key word.
    @param preContext  The pre context 5 words.
    @param postContext  The post context 5 words.
    */
void BSTree::insert(string key, string preContext, string postContext)
{
   // set the maximum length of the pre context string
   if (preContext.length() > (size_t) maxContextLength) maxContextLength = preContext.length();

   if (root == nullptr)
   {
      root = createNode(key, preContext, postContext);
      return;
   }

   Node* curr = root;
   Node* parent = curr;
   while (curr != nullptr)
   {
      parent = curr;
      if (key < curr->key) curr = curr->left;
      else curr = curr->right;
   }

   if (key < parent->key)
      parent->left = createNode(key, preContext, postContext);
   else if (key > parent->key)
      parent->right = createNode(key, preContext, postContext);
   else
      parent->list->insert(preContext, postContext);
}

/** Creates a new node with the given context information
    @pre  None.
    @param key  The context key word.
    @param preContext  The pre context 5 words.
    @param postContext  The post context 5 words.
    */
Node* BSTree::createNode(string key, string preContext, string postContext)
{
   Node* node = new Node();
   LinkedList* list = new LinkedList();
   list->insert(preContext, postContext);
   node->key = key;
   node->list = list;
   node->left = nullptr;
   node->right = nullptr;

   return node;
}

/** Checks if the BS Tree is empty
    @return  true if empty, false elsewise
    */
bool BSTree::isEmpty() const
{
   return root == nullptr;
}

/** Prints the context information in sorted order.
    */
void BSTree::print() const
{
   inorderTraversal(root);
}

/** Prints the context information in sorted order.
    @pre  None.
    @param node  The node to traverse from 
    */
void BSTree::inorderTraversal(Node* node) const
{
   if (node == nullptr) return;
   inorderTraversal(node->left);

   ListNode* context = node->list->getHead();
   while (context != nullptr)
   {
      string spacesBefore = "";
      for (int i = 0; (size_t) i < maxContextLength - context->getPreContext().length(); i++) spacesBefore += " ";
      cout << spacesBefore << context->getPreContext();
      cout << node->key << " ";
      cout << context->getPostContext();
      cout << endl;
      context = context->getNext();
   }

   inorderTraversal(node->right);
}

/** The BS Tree destructor
   */
BSTree::~BSTree()
{
   clear(root);
   root = nullptr;
   delete root;
}

/** Destroys all the nodes in the given BS Tree in a recursive manner
  */
void BSTree::clear(Node* node)
{
   Node* nodeToDeletePtr = node;

   if (node == nullptr) return;

   if (node->left != nullptr) clear(node->left);
   if (node->right != nullptr) clear(node->right);

   // Return node to the system
   nodeToDeletePtr->left = nullptr;
   nodeToDeletePtr->right = nullptr;
   delete nodeToDeletePtr;
}