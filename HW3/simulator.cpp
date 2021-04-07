
/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
//#include "maxHeap1.h"
//#include"maxHeap2.h"
#include <fstream>
#include<string.h>
using namespace std;

int main(int argc, char* argv[]){
if(argc == 3){
Heap h;

int size = 0;

int sizeOfTxt = 100;
int *pat = new int[sizeOfTxt];

string txt(argv[argc-2]);

ifstream is(txt);
int cnt = 0;
int x;

while(is >> x)
{
    if(cnt >= sizeOfTxt)
    {
        int* tmp = new int[sizeOfTxt*2];
        for(int i = 0; i < sizeOfTxt; i++)
            tmp[i] = pat[i];
        delete[] pat;
        pat = tmp;
        sizeOfTxt = sizeOfTxt*2;
    }

    pat[cnt++] = x;

}


is.close();

int wt;
wt= atoi(argv[argc-1]);

int waitingTime = wt;
double tmpWtime =0;
int numberOfPatient = pat[0];
Patient *pt = new Patient[numberOfPatient];
cout << "numberOfPatient is: " << numberOfPatient << endl;

int j = 0;
for(int i = 1; i <= numberOfPatient*4-3; i = i+4)
{
    Patient patie(pat[i],pat[i+1],pat[i+2],pat[i+3]);
    pt[j] = patie;
    j++;

}

delete[] pat;

//for(int i = 0; i < numberOfPatient; i++)
//    cout << pt[i].getId() << " " << pt[i].getPriority() << " " << pt[i].getArrTime() << " " << pt[i].getExTime()<< endl;

//for (int i =0; i < numberOfPatient; i++)
//    h.heapInsert(pt[i]);
//for (int i = 0; i < numberOfPatient; i++)
//    h.heapDelete(p1);

do
{
    tmpWtime = 0;
    int maxTime = pt[0].fullTime();
    int time = 1;
    doctor *dr = new doctor[++size];

    for (int i = 0; i < numberOfPatient; i++)
    {
        if(maxTime < pt[i].fullTime())
            maxTime = pt[i].fullTime();
    }
    int k = 0;
    //while(time <= maxTime + numberOfPatient*waitingTime)
    while(time <= pt[numberOfPatient-1].getArrTime() || !h.heapIsEmpty())
    {

        for (int i = k; i < numberOfPatient; i++)
        {
            if(pt[i].getArrTime() == time){
                h.heapInsert(pt[i]);
                k++;
                //h.heapPrint();
            }

            else
                break;
        }


        for (int i = 0; i < size; i++)
        {
            if(dr[i].check())
            {
                Patient p;
                if(h.heapDelete(p))
                {
                    dr[i].getPatient(p);
                    tmpWtime += time-p.getArrTime();
//                    if(flag)
//                    {
//                        cout << "Doctor " << i << " takes patient " << p.getId() << " at minute " << time << " (wait: " << time-p.getArrTime() << " mins)" << endl;
//                    }

                }

            }
            dr[i].dc();
        }

        time++;

    }
    tmpWtime = tmpWtime/numberOfPatient;

    delete[] dr;

//cout <<"avg time is: " << tmpWtime <<" --------------------------------------------" << endl;
    //h.heapPrint();
}while(tmpWtime > waitingTime);



cout << "Minimum number of doctors required: " << size << endl;
cout << endl;
cout << "Simulation with "<< size <<" doctors: " << endl;
cout << endl;

    int maxTime = pt[0].fullTime();
    int time = 1;
    doctor *dr = new doctor[size];

    for (int i = 0; i < numberOfPatient; i++)
    {
        if(maxTime < pt[i].fullTime())
            maxTime = pt[i].fullTime();
    }
    int k = 0;
    while(time <= maxTime + numberOfPatient*waitingTime)
    {
        for (int i = k; i < numberOfPatient; i++)
        {
            if(pt[i].getArrTime() == time){
                h.heapInsert(pt[i]);
                k++;
            }
            else
                break;
        }


        for (int i = 0; i < size; i++)
        {
            if(dr[i].check())
            {
                Patient p;
                if(h.heapDelete(p))
                {
                    dr[i].getPatient(p);
                        cout << "Doctor " << i << " takes patient " << p.getId() << " at minute " << time << " (wait: " << time-p.getArrTime() << " mins)" << endl;
                }

            }
            dr[i].dc();
        }

        time++;

    }
delete[] dr;
delete[] pt;
cout << endl;
cout << "Average waiting time: " << tmpWtime << " minutes"<<endl;
}
else
    cout << "Enter the inputFile and avarage waiting time! " << endl;
return 0;

}
