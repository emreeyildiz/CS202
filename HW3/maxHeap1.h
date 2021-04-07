
/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
#include "Doctor.h"
const int MAX_HEAP = 2000;

class Heap
{
public:

    Heap();
    ~Heap();
    bool heapIsEmpty() const;
    void heapInsert(const Patient & newItem);
    bool heapDelete(Patient & rootItem);

    void heapPrint();

protected:
    void heapRebuild(int root);

private:
    Patient items[MAX_HEAP];
    int size;
};
#include "simulator.cpp"
