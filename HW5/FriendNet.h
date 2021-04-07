#include <iostream>
#include <string>
#include"linkedList.h"
#include "que.h"
using namespace std;
class FriendNet{
public:
FriendNet();
FriendNet(const string fileName); // constructor
FriendNet(const FriendNet& aNet); // copy constructor
~FriendNet(); // destructor
void listFriends(const string personName, const int hopNo);
void listFriends2(linkedList l, int hopNo, string*&names);
void displayAverageDegrees2(linkedList l, int*&arr, int &j);
void displayAverageDegrees();
void displayDiameters();
void traverse(linkedList l,int*paths, int &maxPath);
private:
linkedList*v;
int size = 0;
int** mularr;
// ...
// define your data members here
// define private class functions here, if you have any
// YOU HAVE TO USE THE ADJACENCY LIST REPRESENTATION
};
