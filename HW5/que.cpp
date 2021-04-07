#include "que.h"
using namespace std;

que::que(int size2)
{
    size = 0;
    q = new int[size2];
}

que::~que()
{
    delete [] q;
}

void que::enque(int item)
{
    if(front == -1)
        front = 0;
    rear++;
    q[rear] = item;
    size++;
}

int que::deque()
{
    if (front == - 1 || front > rear)
        return -1;
    size--;
    return q[front++];

}

void que::display()
{
   if (front == - 1 || size ==0)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
         cout<<q[i]<<" ";
      cout<<endl;
   }
}

bool que::isEmpty()
{
    if(size == 0)
        return true;
    return false;
}
