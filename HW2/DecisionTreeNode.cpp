/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:2
*/

#include <iostream>
#include "DecisionTreeNode.h"
#include<iostream>
#include <math.h>
#include <cmath>


using namespace std;

DecisionTreeNode:: DecisionTreeNode()
{
    left = NULL;
    right = NULL;
}

DecisionTreeNode:: DecisionTreeNode(int k)
{
    data = k;
    left = NULL;
    right = NULL;
}

DecisionTreeNode:: ~DecisionTreeNode()
{
}


bool DecisionTreeNode:: isLeaf()
{
    if (right == NULL && left == NULL)
        return true;
    else
        return false;
}



double calculateEntropy(const int* classCounts, const int numClasses)
{
    int sum = 0;
    double ent = 0;
    for (int j = 0; j < numClasses; j++)
    {
        sum = sum + classCounts[j];
    }

    for (int i = 0; i < numClasses; i++)
    {
        if (classCounts[i] != 0)
        {

        double tmp = (double)classCounts[i]/sum;
        ent +=(double)tmp*log2(tmp);
        }
    }

    return ent*-1;
}

double calculateInformationGain(const bool** data, const int* labels, const int numSamples,
                                 const int numFeatures, const bool* usedSamples, const int featureId)
{

        int maxL = 0;
        for (int i = 0; i < numSamples; i++)
        {
            if(maxL < labels[i]){
                maxL = labels[i];
            }
        }
        int* arr = new int[maxL];
        int* arrt = new int[maxL];
        int* arrf = new int[maxL];

        for (int i = 0; i < maxL; i++)
        {
            arr[i] = 0;
            arrt[i] = 0;
            arrf[i] = 0;
        }
        for (int i = 0; i < numSamples; i++)
        {
        if(!usedSamples[i])
        {
            arr[labels[i]-1]++;
        }
        }

        for (int i = 0; i < numSamples; i++)
        {
        if(!usedSamples[i])
        {
        if(data[i][featureId])
        {
            arrt[labels[i]-1]++;
        }

        else
        {
            arrf[labels[i]-1]++;
        }
        }
        }

        double t = 0;
        double f = 0;

        for (int i = 0; i < maxL; i++)
        {
            t = t + arrt[i];
            f = f + arrf[i];
        }

        double pt = double (t / numSamples);

        double pf = double (f / numSamples);

        double trueEnt = pt*calculateEntropy(arrt,maxL);
        double falseEnt = pf*calculateEntropy(arrf,maxL);
        double allEnt = calculateEntropy(arr, maxL);

        delete[] arr;
        delete[] arrt;
        delete[] arrf;

        double result = double(falseEnt + trueEnt);
        return double(allEnt - result);
}









