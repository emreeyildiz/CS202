#include"FriendNet.h"
#include <string>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;
FriendNet::FriendNet()
{
    cout << "The empty FriendNet is created!!" << endl;
}


FriendNet::FriendNet(const string fileName)
{

    fstream file;
    file.open(fileName, ios_base::in);
    if(file.is_open())
    {
        file >> size;
        v = new linkedList[size];
        mularr = new int*[size];
        for(int i = 0; i < size; i++)
        {
            int id = 0;
            string name = "";
            int degree = 0;
            file >> id;
            file >> name;
            file >> degree;
            mularr[id] = new int[degree];
            for(int j = 0; j < degree; j++)
            {
                int fri = 0;
                file >> fri;
                mularr[id][j] = fri;
            }
            v[id].insert(1,id,name,degree);
        }

        for(int i = 0; i<size; i++)
        {
            int id1;
            string name2;
            int degree1;
            v[i].retrieve(1,id1,name2,degree1);
            for(int j = 1; j <=degree1; j++)
            {
                int dg;
                v[mularr[i][j-1]].retrieve(1,id1,name2,dg);
                v[i].insert(j+1,id1,name2,dg);
            }
        }

        for(int i = 0; i<size; i++)
        {
            delete[] mularr[i];
        }
        delete [] mularr;
    }
    else
        cout << "The empty FriendNet is created!!" << endl;
}
FriendNet::FriendNet(const FriendNet& aNet)
{
    size = aNet.size;
    if(size != 0){
    v = new linkedList[size];
    for(int i = 0; i <size; i++)
    {
        v[i] = aNet.v[i];
    }
//    for(int i = 0; i <size; i++)
//    {
//        v[i].display();
//    }

    }


}

FriendNet::~FriendNet()
{
    if(size != 0)
        delete [] v;
}

void FriendNet::listFriends(const string personName, const int hopNo)
{
    if(size == 0)
    {
        return;
    }
    string* names = new string[size];
    for(int i = 0; i < size; i++)
        names[i] == "";
    bool found = false;
    int id1;
    string name2;
    int degree1;
    int i = 0;
    for(; i<size; i++)
    {
        if(v[i].retrieve(1,id1,name2,degree1))
        {
            if(name2 == personName)
            {
                found = true;
                break;
            }
        }
    }
    if(!found)
    {
        cout << personName << " does not exist in the network." << endl;
        delete [] names;
        return;
    }

    if(hopNo <= 0)
    {
        cout << "People accessible from " << personName << " within "<< hopNo << " hops: NOBODY" << endl;
        delete [] names;
        return;
    }
    listFriends2(v[i],hopNo,names);

    int x = 0;
    cout << "People accessible from " << personName << " within "<< hopNo << " hops: ";
    for (int i = 0; i < size; i++)
    {
        if(names[i] != "" && names[i] != personName){
            x++;
            if(x == 1)
                cout <<names[i];
            else
                cout<< " , " <<names[i] ;

    }
    }

    if(x == 0)
        cout << "NOBODY"<<endl;
    cout << endl;

    delete [] names;
}

void :: FriendNet::listFriends2(linkedList l, int hopNo, string*&names)
{

    int id1;
    string name2;
    int degree1;
    int dg;
    int k = 2;
    l.retrieve(1,id1,name2,degree1);
    if(hopNo == 1)
    {
        names[id1] = name2;
        while(k <= degree1+1)
        {

            l.retrieve(k,id1,name2,dg);
            names[id1] = name2;
            k++;
        }
    }

    else{
    while(k <= degree1+1)
    {
        l.retrieve(k,id1,name2,dg);

        listFriends2(v[id1],hopNo-1, names);
        k++;
    }
    }
}

void FriendNet::displayAverageDegrees()
{
    if(size == 0)
    {
        return;
    }
    int* arr = new int[size];
    for(int i = 0; i<size; i++)
        arr[i] = 0;
    int j = 1;

    displayAverageDegrees2(v[0], arr, j);

    for(int i = 0; i < size; i++)
    {
        //cout << i << ": " << arr[i] << endl;
        if(arr[i] == 0)
        {
            j++;
            displayAverageDegrees2(v[i], arr, j);
        }
    }

    int* n = new int[j];
    int* sum = new int[j];

    for(int i = 0; i < j; i++)
    {
         n[i] = 0;
         sum[i] = 0;
    }

    for(int k = 0; k < size; k++)
    {
        int id1;
        string name2;
        int degree1;
        v[k].retrieve(1,id1,name2,degree1);
        n[arr[k]-1]++;
        sum[arr[k]-1] += degree1;
    }


    cout << "There are " <<j<< " connected components. The average degrees are:" << endl;
     for(int i = 0; i < j; i++)
     {
         cout << "For component " << i <<": "<< double((double)sum[i] / double(n[i])) << endl;
     }

    delete[] n;
    delete [] arr;
    delete[] sum;
}

void FriendNet::displayAverageDegrees2(linkedList l, int*&arr, int &j)
{
    int id1;
    string name2;
    int degree1;
    int dg;
    int k = 2;
    l.retrieve(1,id1,name2,degree1);
    arr[id1] = j;
    while(k <= degree1+1)
    {
        l.retrieve(k,id1,name2,dg);
        if(arr[id1] == 0)
            displayAverageDegrees2(v[id1], arr, j);
    k++;
    }

}

void FriendNet::displayDiameters()
{
    if(size == 0)
    {
        return;
    }
    int* arr = new int[size];
    for(int i = 0; i<size; i++)
        arr[i] = 0;
    int j = 1;

    displayAverageDegrees2(v[0], arr, j);

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 0)
        {
            j++;
            displayAverageDegrees2(v[i], arr, j);
        }
    }

    cout << "There are " <<j<< " connected components. The diameters are:" << endl;
    for(int i =0; i<j;i++)
    {
        int dia = 0;
        for(int k = 0; k <size; k++)
        {

            int id1;
            bool ch;
            int id2;
            string name2;
            int degree1;
            int dg;
            v[k].retrieve(1,id1,name2,degree1);
            if(arr[id1] == i+1)
            {

                bool* visited = new bool[size];
                int* num = new int[size];
                for(int i2 = 0; i2 <size; i2++)
                {
                    visited[i2] = false;
                    num[i2] = 0;
                }
                que q(size);
                visited[id1] = true;

                q.enque(id1);

                while(!q.isEmpty())
                {
                    ch =true;
                    id1 = q.deque();
                    //vs++;
                    //cout << id1 << endl;
                    int l = 2;
                    v[id1].retrieve(1,id2,name2,degree1);
                    //cout <<"q dan cikardim   " <<name2<< endl;
                    while(l <= degree1+1)
                    {
                        v[id1].retrieve(l,id2,name2,dg);
                        //cout <<" l:  " <<l <<"  id:  "<<id2 << " name:   "<<name2<<"  visited:   "<<visited[id2]<<endl;

                        if(!visited[id2])
                        {
                            num[id2] = num[id1]+1;
                            //cout << "id1: " << id1 <<"  id2: "<<id2 << endl;
                            visited[id2]=true;
                            //cout <<" q ya attim  " <<name2 << endl;
                            q.enque(id2);
                        }
                        l++;
                    }
                }


                for(int a= 0; a<size; a++)
                {
                    if(dia < num[a])
                        dia = num[a];
                }
                delete [] visited;
                delete[] num;
            }
        }
        cout << "For component "<< i <<": "<<dia << endl;
    }
    delete [] arr;
}

