#ifndef __HashTable_H
#define __HashTable
enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };
class HashTableItem
{
public:
    HashTableItem();
    HashTableItem(int item);
    int getItem();
    void setItem(int newItem);
    void setIsDeleted(bool flag);
    int item;
    bool isDeleted;
};
class HashTable{
public:

HashTable( const int tableSize, const CollisionStrategy option );
~HashTable();
bool insert( const int item );
int getSize();
bool remove( const int item );
bool search( const int item, int& numProbes );
bool isFull();
void display();
void analyze( double& numSuccProbes, double& numUnsuccProbes );
private:
    int size;
    HashTableItem **arr;
    int hashtype; //0 ->linear, 1->Quadratic, 2->DoubleHash

};
#endif // __HashTable_H
