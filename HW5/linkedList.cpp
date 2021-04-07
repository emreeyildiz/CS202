#include "linkedList.h"
#include <algorithm>
#include <cstddef>

linkedList::linkedList(): size(0), head(NULL)
{

}

linkedList::linkedList(const linkedList& aList): size(aList.size){
   if (aList.head == NULL)
      head = NULL;  // original list is empty
   else {
      // copy first node
      head = new ListNode;
      head->id = aList.head->id;
      head->degree = aList.head->degree;
      head->name = aList.head->name;
      // copy rest of list
      ListNode *newPtr = head;  // new list ptr

      for (ListNode *origPtr = aList.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new ListNode;
         newPtr = newPtr->next;
         newPtr->id = origPtr->id;
         newPtr->degree = origPtr->degree;
         newPtr->name = origPtr->name;
      }
      newPtr->next = NULL;
   }
}

linkedList::~linkedList(){

    ListNode* cur = head;
   while (cur!=NULL)
    {
        head = head->next;
        delete cur;
        cur = head;
    }

}

void linkedList::operator =(const linkedList& aList)
{
    size = aList.size;
    ListNode* cur = head;
   while (cur!=NULL)
    {
        head = head->next;
        delete cur;
        cur = head;
    }
    if (aList.head == NULL)
      head = NULL;  // original list is empty
   else {
      // copy first node
      head = new ListNode;
      head->id = aList.head->id;
      head->degree = aList.head->degree;
      head->name = aList.head->name;
      // copy rest of list
      ListNode *newPtr = head;  // new list ptr

      for (ListNode *origPtr = aList.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new ListNode;
         newPtr = newPtr->next;
         newPtr->id = origPtr->id;
         newPtr->degree = origPtr->degree;
         newPtr->name = origPtr->name;
      }
      newPtr->next = NULL;
   }
}

int linkedList::getLength() const{

   return size;

}

bool linkedList::retrieve(int index, int &id, string &name, int &degree)
{
if ((index < 1) || (index > getLength()))
      {
          return false;
      }

   ListNode *cur = find(index);
   id = cur->id;
   name = cur->name;
   degree = cur->degree;

   return true;
}

bool linkedList:: insert(int index, int id, string name, int degree)
{
    int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   ListNode *newPtr = new ListNode;
   size = newLength;
    newPtr->id = id;
    newPtr->degree = degree;
    newPtr->name = name;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      ListNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

}

linkedList::ListNode *linkedList::find(int index)
{
    if ( (index < 1) || (index > size) )
      return NULL;

   else{ // count from the beginning of the list
      ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}

void linkedList:: display()
{
    cout << head->id << " " << head->name<< " " << head->degree<< " ";
    ListNode* cur = head->next;
    while(cur != NULL)
    {
        cout << cur->id << " ";
        cur = cur->next;
    }
    cout << endl;

}
