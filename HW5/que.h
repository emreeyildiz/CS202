#include <iostream>
using namespace std;

class que
{
    public:
    que(int size);
    ~que();
    void enque(int item);
    int deque();
    void display();
    bool isEmpty();
    int size;
    int* q;
    int front = - 1, rear = - 1;
    friend class FriendNet;
};
