#include "ContextLinkedList.h"

ContextLinkedList::ContextLinkedList():head(nullptr)
{
}

ContextLinkedList::~ContextLinkedList()
{
}

ListNode* ContextLinkedList::getHead()
{
   return head;
}

void ContextLinkedList::insert(string preContext, string postContext)
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