
/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:3
*/
#include <iostream>
class Patient
{
    public:
    Patient();
    Patient(const Patient &newP ) ;
    Patient(int id, int pr, int arrTime, int exTime);
    ~Patient();


    void operator=(const Patient&right);
    bool operator>(const Patient &right);
    bool operator<(const Patient &right);
    int getKey();
    int getPriority();
    int getId();
    int getArrTime();
    int getExTime();
    int fullTime();

    void setPriority(int x);
    void setId(int x);
    void setArrTime(int x);
    void setExTime(int x);

    friend class Heap;

    private:
    int id;
    int pr;
    int arrTime;
    int exTime;

};

