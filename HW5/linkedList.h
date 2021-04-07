#include <iostream>
using namespace std;

class linkedList
{
public:
    linkedList();
    linkedList(const linkedList& aList);
    ~linkedList();

   bool retrieve(int index, int &id, string &name, int &degree);

   bool insert(int index, int id, string name, int degree);

    int getLength() const;
    void  display();
    void operator =(const linkedList& l);
   struct ListNode
   {
       int id;
       string name;
       int degree;
       ListNode* next;
   };

   int size;
   ListNode* head;
    friend class FriendNet;
   ListNode *find(int index);

};
