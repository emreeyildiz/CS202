/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
#include "Patient.h"
class doctor
{
    public:
    doctor();
    ~doctor();
    doctor(bool av, int patientID);

    bool isAv();
    void getPatient(Patient &p);
    void dc();
    bool check();

    private:
    bool av;
    int patientID;
    int busyTime;
};
