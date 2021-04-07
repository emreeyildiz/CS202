/**
*Author: Muhammed Emre YILDIZ
*ID:21702825
*Seciton:2
*Assignment:2
*/

#include <iostream>
using namespace std;

class DecisionTreeNode{
//struct Node
//{
//    Node *left;
//    Node *right;
//    int data;
//};
public:
DecisionTreeNode();
DecisionTreeNode(int k);
~DecisionTreeNode();
bool isLeaf();

private:
    DecisionTreeNode *left;
    DecisionTreeNode *right;
    int data;

friend class DecisionTree;

};
double calculateEntropy(const int* classCounts, const int numClasses);
double calculateInformationGain(const bool** data, const int* labels, const int numSamples,
                                 const int numFeatures, const bool* usedSamples, const int featureId);
