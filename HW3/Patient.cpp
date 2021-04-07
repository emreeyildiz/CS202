
/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
#include "Patient.h"
using namespace std;

Patient::Patient()
{
    id = 0;
    pr = 0;
    arrTime = 0;
    exTime = 0;
}

Patient::Patient(int id, int pr, int arrTime, int exTime)
{
    this->id = id;
    this->pr = pr;
    this -> arrTime = arrTime;
    this->exTime = exTime;
}

Patient::Patient( const Patient &newP)
{
    id = newP.id;
    pr =newP.pr;
    arrTime = newP.arrTime;
    exTime = newP.exTime;
}

Patient::~Patient()
{

}

void Patient :: operator = (const Patient &right)
{
    if(&right != this){
    id = right.id;
    pr =right.pr;
    arrTime = right.arrTime;
    exTime = right.exTime;
}
}

bool Patient :: operator >(const Patient &right)
{
    if(pr > right.pr)
        return true;
    else if(pr == right.pr)
        return arrTime < right.arrTime;
    else
        return false;
}

bool Patient :: operator <(const Patient &right)
{
    if(pr < right.pr)
        return true;
    else if(pr == right.pr)
        return arrTime > right.arrTime;
    else
        return false;
}


int Patient::getId()
{
    return id;
}

int Patient::getPriority()
{
    return pr;
}

int Patient::getArrTime()
{
    return arrTime;
}

int Patient::getExTime()
{
    return exTime;
}



void Patient::setId(int x)
{
     id = x;
}

void Patient::setPriority(int x)
{
     pr= x;
}

void Patient::setArrTime(int x)
{
    arrTime= x;
}

void Patient::setExTime(int x)
{
    exTime= x;
}

int Patient::getKey()
{
    return getPriority();
}

int Patient::fullTime()
{
    return arrTime + exTime;
}
