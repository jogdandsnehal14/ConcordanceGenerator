#pragma once
#include <string>
using namespace std;

struct ListNode
{
   string preContext;
   string postContext;
   ListNode* next;
};

class ContextLinkedList
{
private:
   ListNode* head;
public:
   ContextLinkedList();
   ~ContextLinkedList();
   ListNode* getHead();
   void insert(string preContext, string postContext);
};