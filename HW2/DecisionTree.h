/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:2
*/

#include <iostream>
#include "DecisionTreeNode.h"

class DecisionTree{
public:
DecisionTree();
void train(const bool** data, const int* labels, const
int numSamples, const int numFeatures);
void trainTree(const bool** data, const int* labels, const
int numSamples, const int numFeatures, bool* &usedSamples, bool* &usedFeatures, DecisionTreeNode* &root);
int trainCalculate(const bool** data, const int* labels, const
int numSamples, const int numFeatures,bool* usedFeatures, bool* usedSamples);
void train(const string fileName, const int numSamples,
const int numFeatures);
void print();
int predict(const bool* data);
void print2D(DecisionTreeNode* root, int s);
double test(const bool** data, const int* labels, const
int numSamples);
double test(const string fileName, const int numSamples);



private:
DecisionTreeNode* root;

};


