#include "HashTable.h"
#include <iostream>
using namespace std;


HashTableItem::HashTableItem(int item)
{
    this ->item = item;
    isDeleted = false;
}

void HashTableItem::setIsDeleted(bool flag)
{
    isDeleted = flag;
}


int HashTableItem::getItem()
{
    return item;
}

void HashTableItem::setItem(int newItem)
{
    item = newItem;
}

HashTable::HashTable( const int tableSize, const CollisionStrategy option )
{
    size = tableSize;
    arr = new HashTableItem*[size];

    if (option == 0 || option == LINEAR)
        hashtype = 0;
    else if (option == 1 || option == QUADRATIC)
        hashtype = 1;
    else if (option == 2 || option == DOUBLE)
        hashtype = 2;
    else
        hashtype = -1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = NULL;
    }

}
HashTable::~HashTable()
{
    for(int i = 0; i < size; i++)
    {
        //if(arr[i] != NULL)
            delete arr[i];
    }
    if(arr != NULL)
        delete[] arr;
}

int HashTable::getSize()
{
    return size;
}

bool HashTable:: insert(const int newItem)
{
    if (isFull()){
        return false;
    }
    int k = 0;
    if(!search(newItem,k)){

    int key = newItem % size;
    if(arr[key] == NULL){
        HashTableItem* item = new HashTableItem(newItem);
        arr[key] = item;
        //cout << "newItem is: " << newItem << endl;
        return true;
    }
    else if(arr[key]->isDeleted){
        arr[key]->setItem(newItem);
        arr[key] ->setIsDeleted(false);
        //cout << " (else if) newItem is: " << newItem << endl;
        return true;
    }
    else
    {
        //cout << " (else) newItem is: " << newItem << endl;
        if(hashtype == 0) //linear
        {
            int i = 0;
            while(arr[(key +i)%size]!=NULL)
            {
                if (arr[(key +i)%size]->isDeleted)
                {
                    arr[(key +i)%size]->setItem(newItem);
                    arr[(key +i)%size]->setIsDeleted(false);
                    return true;
                }
                i++;
                if(i == size){
                    return false;
                }
            }
            HashTableItem* item = new HashTableItem(newItem);
            arr[(key +i)%size] = item;
            return true;
        }

        else if(hashtype == 1) //quadratic
        {

            int i = 0;
            while(arr[(key + i*i)%size]!=NULL)
            {

                if(arr[(key + i*i)%size]->isDeleted)
                {
                    arr[(key + i*i)%size]->setItem(newItem);
                    arr[(key + i*i)%size]->setIsDeleted(false);

                    return true;
                }
                i++;
                if(i == (size/2) + 1)
                    return false;
            }
            HashTableItem* item = new HashTableItem(newItem);
            arr[(key +i*i)%size] = item;
            return true;
        }

        else if(hashtype == 2)  //double
        {
            int i = 0;
            int k = newItem;
            int x = 0;
            int r = 0;
            while (k != 0)
            {
                x = k %10;
                r = r*10 + x;
                k /= 10;
            }
            r = r%size;
            while(arr[(key + i*r)%size]!=NULL)
            {
                if(arr[(key + i*r)%size]->isDeleted)
                {
                    arr[(key + i*r)%size]->setItem(newItem);
                    arr[(key + i*r)%size]->setIsDeleted(false);
                    return true;
                }
                i++;
                if(i == size)
                    return false;
            }
            HashTableItem* item = new HashTableItem(newItem);
            arr[(key + i*r)%size] = item;
            return true;
        }
    }

}
return false;
}

bool HashTable::isFull()
{
    for(int i = 0; i < size; i++){
        if(arr[i] == NULL || arr[i] ->isDeleted)
            return false;
    }

    return true;

}

bool HashTable::remove( const int item )
{
    int key = item%size;

    if(hashtype == 0)
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[(key + i)%size] == NULL)
            {
                return false;
            }
            if(arr[(key + i)%size]->getItem() == item){
                arr[(key + i)%size]->setIsDeleted(true);
                return true;
            }
        }
        return false;
    }

    else if (hashtype == 1)
    {
        for(int i = 0; i <= size/2; i++)
        {
            if(arr[(key + i*i)%size] == NULL)
            {
                return false;
            }
            if(arr[(key + i*i)%size]->getItem() == item){
                arr[(key + i*i)%size]->setIsDeleted(true);
                return true;
            }
        }
        return false;
    }

    else if (hashtype == 2)
    {
        int i = 0;
        int k = item;
        int x = 0;
        int r = 0;
        while (k != 0)
        {
            x = k %10;
            r = r*10 + x;
            k /= 10;
        }

        r = r%size;
        for(int i = 0; i < size; i++)
        {
            if(arr[(key + i*r)%size] == NULL)
            {
                return false;
            }
            if(arr[(key + i*r)%size]->getItem() == item){
                arr[(key + i*r)%size]->setIsDeleted(true);
                return true;
            }
        }
        return false;
    }


}


bool HashTable::search(const int item, int &numProbes)
{
    int key = item%size;
    numProbes = 0;

    if(hashtype == 0)
    {
        for(int i = 0; i < size; i++)
        {
            numProbes++;
            if(arr[(key + i)%size] == NULL)
            {
                return false;
            }
            if( arr[(key + i)%size]->isDeleted == false && arr[(key + i)%size]->getItem() == item){
                return true;
            }
        }
        return false;
    }

    else if (hashtype == 1)
    {
        for(int i = 0; i <= size/2 ; i++)
        {
            numProbes++;
            if(arr[(key + i*i)%size] == NULL)
            {
                return false;
            }
            if(arr[(key + i*i)%size]->isDeleted ==false &&arr[(key + i*i)%size]->getItem() == item){
                return true;
            }
        }
        return false;
    }
    else if (hashtype == 2)
    {
        int i = 0;
        int k = item;
        int x = 0;
        int r = 0;
        while (k != 0)
        {
            x = k %10;
            r = r*10 + x;
            k /= 10;
        }

        r = r%size;
        for(int i = 0; i < size; i++)
        {
            numProbes++;
            if(arr[(key + i*r)%size] == NULL)
            {
                return false;
            }
            if(arr[(key + i*r)%size]->isDeleted == false && arr[(key + i*r)%size]->getItem() == item){
                return true;
            }
        }
        return false;
    }


}


void HashTable::display()
{
    cout << "---------------------------------" << endl;
    for(int i = 0; i< size; i++)
    {

        cout << i <<": ";
        if(arr[i] != NULL && arr[i]->isDeleted == false){
            cout << arr[i]->getItem() << endl;
        }
        else
            cout << endl;
    }

    cout << "---------------------------------" << endl;
}

void HashTable::analyze( double& numSuccProbes, double& numUnsuccProbes )
{
    int* items = new int[size];
    int validSize = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] != NULL && arr[i]->isDeleted == false)
        {
            items[validSize++] = arr[i]->getItem();
        }
    }

    int n = 0;
    for(int j = 0; j < validSize; j++)
    {
        search(items[j], n);
        numSuccProbes += n;
    }

    numSuccProbes = numSuccProbes/validSize;
    delete[] items;
    if(hashtype == 2)
        numUnsuccProbes = -1;
    else{
    int k = 0;
    int noNumber = 0;
    for(int i = 0; i < size; i++)
    {
        while(search(noNumber,k))
            noNumber = noNumber+size;

            numUnsuccProbes += k;
            noNumber++;
    }

    numUnsuccProbes = double((double)numUnsuccProbes/(double)size);

    }
}


