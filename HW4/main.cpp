#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string.h>
using namespace std;
int main()
{
int tableSize = 11;             //enter the Table size
HashTable h1(tableSize, LINEAR);//enter the enum hash type
string txt = "linear.txt";      //enter the txt file name
ifstream is(txt);
string lineString;
string op;
int x;
int numProb = 0;
while( getline(is, lineString))
{
    stringstream linestream(lineString);
    getline(linestream, op, ' ');
    linestream >> x;
    if(op == "I")
    {
        if(!h1.insert(x))
            cout << x << " cannot be inserted."<< endl;
    }
    if(op == "R")
    {
        if(!h1.remove(x))
            cout << x << " cannot be removed. " << endl;
    }

    if(op == "S")
    {
        if(h1.search(x,numProb))
            cout << x << " is found in " << numProb << " number of probes." << endl;
        else
            cout << x << " cannot be found in " << numProb << " number of probes." << endl;
    }
}

h1.display();
cout << "The size of the table is: "<<h1.getSize()<< endl;
is.close();

    double numSuccProbes = 0;
    double numUnsuccProbes = 0;
    h1.analyze(numSuccProbes, numUnsuccProbes);
    cout << "Average Successful Search: "  << numSuccProbes << endl;
    cout << "Average Unsuccessful Search: " << numUnsuccProbes << endl;
    return 0;

}
