/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:2
*/


#include "DecisionTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

DecisionTree :: DecisionTree()
{
    root= NULL;
}
void DecisionTree::train(const bool** data, const int* labels, const
int numSamples, const int numFeatures)
{


    bool* usedSamples = new bool[numSamples];
    bool* usedFeatures = new bool[numFeatures];
    for(int i = 0; i < numSamples; i++)
        usedSamples[i] = false;

    for (int i = 0; i < numFeatures; i++)
        usedFeatures[i] = false;
    trainTree(data,labels,numSamples,numFeatures, usedSamples, usedFeatures,root);
    delete[] usedSamples;
    delete[] usedFeatures;
}

void DecisionTree :: trainTree(const bool** data, const int* labels, const
int numSamples, const int numFeatures, bool* &usedSamples, bool* &usedFeatures, DecisionTreeNode* &root)
{
    int f = trainCalculate(data, labels, numSamples, numFeatures,usedFeatures,usedSamples);
    bool* usedSamplesRight = new bool[numSamples];
    bool* usedSamplesLeft = new bool[numSamples];
    //cout << "f: " << f << endl;
    bool exit = true;
    int j = 0;
    int* indexes = new int[numSamples];


    for (int i = 0; i < numSamples; i++)
    {
        usedSamplesLeft[i] = usedSamples[i];
        usedSamplesRight[i] = usedSamples[i];
        if(!usedSamples[i])
        {
            indexes[j] = i;
            j++;
        }
    }

    for (int i = 0; i < j-1; i++)
    {
        if(labels[indexes[i]] != labels[indexes[i+1]] ){
            exit = false;
        }
    }

        if(f < 0){
            for(int i = 0; i < numSamples; i++)
            {
                if (usedSamplesLeft[i] == 0)
                {
                    int k = labels[i];
                    root = new DecisionTreeNode(k);
                    break;
                }
                else if(usedSamplesRight[i] == 0)
                {
                    int k = labels[i];
                    root = new DecisionTreeNode(k);
                    break;
                }

            }
            return;

        }



    if (exit)
    {
        cout << "All features are used, there is not a certain tree" << endl;
        return;
    }

    for (int i = 0; i < numSamples; i++)
    {
        if(!usedSamples[i]){
            if(root == NULL)
            {
                root = new DecisionTreeNode(f);
                usedFeatures[f] = true;

            }

            if(data[i][f])
            {
                usedFeatures[f] = true;
                usedSamplesRight[i] = true;
            }

            else
            {
            usedFeatures[f] = true;
            usedSamplesLeft[i] = true;
            }
        }
    }

    trainTree(data, labels, numSamples, numFeatures, usedSamplesLeft, usedFeatures, root->left);
    trainTree(data, labels, numSamples, numFeatures, usedSamplesRight, usedFeatures, root->right);

    delete[] usedSamplesLeft;
    delete[] usedSamplesRight;


}





void DecisionTree :: print2D(DecisionTreeNode* root, int s)
{
    int c = 1;
    if(root == NULL){
        return;
    }
    s = s + c;

    print2D(root ->left,s);

    cout << endl;

    for(int i = c; i < s; i++)
        cout << "\t";
    if(root ->isLeaf())
        cout<< "class: "<< root ->data << "\n";
    else
        cout<< root ->data << "\n";

    print2D(root ->right, s);
}

void DecisionTree:: print()
{
    if(root != NULL)
        print2D(root, 0);
}


int DecisionTree :: trainCalculate(const bool** data, const int* labels, const
int numSamples, const int numFeatures, bool* usedFeatures ,bool* usedSamples)
{
    int f = -1;
    double maxC = 0 ;//calculateInformationGain(data, labels, numSamples, numFeatures,usedSamples, 0);
    for (int i = 0; i < numFeatures; i++)
    {

        double t = calculateInformationGain(data, labels, numSamples, numFeatures,usedSamples, i);
        //cout << "t is: " << t << "  maxC: "<<maxC << " i is:" <<i<< endl;
        if (t != 0 && t > maxC)
        {

            maxC = t;
            f = i;
        }
    }
    return f;
}


void DecisionTree :: train(const string fileName, const int numSamples,const int numFeatures)
{
int x = 0;
    int j = 0;

    string str;
    string label;

    int * labels = new int[numSamples];
    bool* dataRow = new bool[numFeatures];
    bool**  data = new bool*[numSamples];

    for(int i = 0; i<numSamples; i++)
        data[i] = new bool[numFeatures];

    int i = 0;
    ifstream infile;

    infile.open(fileName);

    while (getline(infile, str) && j < numSamples)
    {
        //cout << "lenght: " <<str.length() << endl;
        int k = 0;
        for (int i = 0; i <= 2*numFeatures; i = i+2)
        {

            label = str.substr(i,1);
            stringstream geek(label);
            x = 0;
            geek >> x;
            dataRow[k] = x;
            k++;

        }

        //cout << "numFeatures*2: " << numFeatures*2 << endl;
        label = str.substr(numFeatures*2,str.length()-(2*numFeatures)-1);  //For linux make it str.length()-2
        stringstream geek(label);
        x = 0;
        geek >> x;
        labels[j] = x;
        data[j] = new bool[numFeatures];
        for (int m = 0; m < numFeatures; m++)
            data[j][m] = dataRow[m];
        j++;

    }
    infile.close();

    delete[] dataRow;

//    for (int i = 0; i < numSamples; i++)
//        cout << labels[i] ;
//    cout << endl;


    train((const bool**)data, labels, numSamples,numFeatures);

    delete[] data;


}



int DecisionTree::predict(const bool* data)
{
    if (root != NULL)
    {
        DecisionTreeNode* cur = root;

            while(!cur->isLeaf())
            {
                int f = cur ->data;
                if(data[f] == 0)
                    cur = cur ->right;
                else
                    cur = cur ->left;
            }
        return cur->data;
    }

    cout << "Train function is not called (no predict)" << endl;
    return -1;
}


double DecisionTree::test(const bool** data, const int* labels, const
int numSamples)
{
    if (root != NULL)
    {
        double r;
        int* pre = new int[numSamples];
        int* rate = new int[numSamples];
        double sum = 0;
        for(int i = 0; i < numSamples; i++)
        {
            pre[i] = predict(data[i]);
        }

        for (int i = 0; i < numSamples; i++)
        {
            if(pre[i] == labels[i])
                rate[i] = 1;
            else
                rate[i] = 0;
        }

        for (int i = 0; i < numSamples; i++)
            sum = sum + rate[i];

        delete[] pre;
        delete[] rate;
        //cout << "sum: " << sum << endl;
        //cout << "numSamples: " << numSamples << endl;

        r = (double)(double (sum)/double(numSamples));
        return r;

    }


        cout << "Train function is not called (no test is possible)" << endl;
        return -1;



}

double DecisionTree::test(const string fileName, const int numSamples)
{
	int x = 0;
    int j = 0;
    string str;
    string str2;
    string label;
    int numFeatures;

    int * labels = new int[numSamples];
    bool**  data = new bool*[numSamples];
    bool* dataRow;


    ifstream infile;

    infile.open(fileName);

    while (getline(infile, str) && j < numSamples)
    {
        if (j == 0)
        {
            numFeatures = (str.length()-1)/2;
            //cout << "numFeatures: "<<numFeatures << endl;
            dataRow = new bool[numFeatures];
        }

        int k = 0;

        for (int i = 0; i < numFeatures*2; i = i+2)
        {
            label = str.substr(i,1);
            stringstream geek(label);
            x = 0;
            geek >> x;
            dataRow[k] = x;
            k++;

        }

        label = str.substr(numFeatures*2,str.length()-(2*numFeatures)-1);
        stringstream geek(label);
        x = 0;
        geek >> x;
        labels[j] = x;
        data[j] = new bool[numFeatures];
        for (int m = 0; m < numFeatures; m++)
            data[j][m] = dataRow[m];
        j++;

    }
    infile.close();

   return test((const bool**)data, labels, numSamples);


}

