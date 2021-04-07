/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
#include "maxHeap2.h"
using namespace std;


    Heap::Heap() {
    size2 = 0;
    heapSize = 10;
    items = new Patient[heapSize];

}
Heap::~Heap()
{
    delete [] items;
}

bool Heap::heapIsEmpty() const
{
    return (size2 == 0);
}

void Heap::heapInsert(const Patient & newPatient)
{
    if (size2 >= heapSize)
    {
        Patient* tmp = new Patient[heapSize*2];
        //tmp[heapSize] = Patient();
        for(int i = 0; i < heapSize; i++)
            tmp[i] = items[i];
        delete[] items;
        items = tmp;
        heapSize = heapSize*2;
    }


    items[size2] = newPatient;

    int place = size2;
    int parent = (place-1)/2;

    while( (place > 0 ) && (items[place] > items[parent]))
    {
        Patient tmp = items[parent];
        items[parent] = items[place];
        items[place] = tmp;

        place = parent;
        parent = (place -1)/2;
    }
    ++size2;
}

bool Heap::heapDelete(Patient &rootItem)
{
    if(heapIsEmpty())
        return false;

    if(size2 <= heapSize/2)
    {

        Patient* tmp = new Patient[heapSize/2];
        //tmp[heapSize] = Patient();
        for(int i = 0; i < heapSize/2; i++)
            tmp[i] = items[i];
        delete[] items;
        items = tmp;
        heapSize=heapSize/2;
    }
        rootItem = items[0];
        items[0] = items[--size2];
        heapRebuild(0);
        return true;
}

void Heap::heapRebuild(int root)
{
    int child = 2*root + 1;

    if(child < size2)
    {
        int rightChild = child + 1;

        if((rightChild < size2) && (items[rightChild] > items[child]))
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
    for (int i = 0; i <size2;i++)
        cout <<"index is: " << i << "\t"<< "Priority is: "<<items[i].getKey() << endl;
    cout << "size is: " << size2 << endl;
}

