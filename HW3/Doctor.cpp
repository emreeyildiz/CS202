/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
#include "Doctor.h"
using namespace std;

doctor::doctor()
{
    busyTime = 0;
    av = true;
    patientID = -1;
}

doctor::~doctor()
{

}

doctor::doctor(bool av, int PatientID)
{
    this->av = av;
    this->patientID = patientID;
}

bool doctor::isAv()
{
    return av;
}

void doctor::getPatient(Patient &p)
{
    patientID = p.getId();
    busyTime = p.getExTime();
}

bool doctor::check()
{
    if(busyTime <= 0)
        return true;
    return false;
}

void doctor::dc()
{
    if(!check())
        busyTime--;
}
