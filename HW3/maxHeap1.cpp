/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
#include "maxHeap1.h"
using namespace std;


Heap::Heap() {
    size = 0;
}

Heap::~Heap()
{

}

bool Heap::heapIsEmpty() const
{
    return (size == 0);
}

void Heap::heapInsert(const Patient & newPatient)
{
    if (size >= MAX_HEAP)
        cout << "HeapException: Heap Full!!" << endl;
    else{

    items[size] = newPatient;

    int place = size;
    int parent = (place-1)/2;

    while( (place > 0 ) && (items[place] > items[parent]))
    {
        Patient tmp = items[parent];
        items[parent] = items[place];
        items[place] = tmp;

        place = parent;
        parent = (place -1)/2;
    }
    ++size;
    }
}

bool Heap::heapDelete(Patient &rootItem)
{
    if(heapIsEmpty())
        return false;
    else
    {
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
        return true;
    }
}

void Heap::heapRebuild(int root)
{
    int child = 2*root + 1;

    if(child < size)
    {
        int rightChild = child + 1;

        if((rightChild < size) && (items[rightChild] > items[child]))
            child = rightChild;

        if(items[root] < items[child])
        {
            Patient tmp = items[root];
            items[root] = items[child];
            items[child] = tmp;

            heapRebuild(child);
        }

    }

}
void Heap::heapPrint()
{
    for (int i = 0; i <size;i++)
        cout <<"index is: " << i << "\t"<< "Priority is: "<<items[i].getKey() << endl;
    cout << "size is: " << size << endl;
}
