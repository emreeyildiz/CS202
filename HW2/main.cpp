#include "DecisionTree.h"
#include <iostream>
int main()
{
    DecisionTree d;
    bool a1[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1};
    bool a2[21] = {0 ,1 ,0 ,0 ,0 ,0 ,0 ,0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1, 0};
    bool a3[21] = {0, 0, 1, 0, 0 ,0 ,0, 0, 1 ,0, 0 ,0 ,0 ,0, 0, 0, 0, 0 ,0 ,1 ,1};
    bool a4[21] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1};
    bool a5[21] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1};
    bool a6[21] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1};
    bool a7[21] = {0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0 ,0 ,1 ,1};
    bool a8[21] = {0 ,1 ,0 ,0 ,0 ,0 ,0, 0, 0, 0 ,0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1};
    bool a9[21] = {0 ,0 ,0 ,0 ,0 ,0 ,0, 0 ,0, 0, 1, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 1 ,1};
    bool a10[21] ={0 ,1 ,0 ,0 ,0 ,0, 0, 0, 0, 0 ,0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1};


//    bool b1[5] = {0,0,0,0,1};
//    bool b2[5] = {0,0,0,0,1};
//    bool b3[5] = {0,0,0,1,0};
//    bool b4[5] = {0,0,0,1,0};
//    bool b5[5] = {0,0,1,0,0};
//    bool b6[5] = {0,0,1,0,0};
//    bool b7[5] = {0,1,0,0,0};
//    bool b8[5] = {0,1,0,0,0};
//    bool b9[5] = {1,0,0,0,0};
//    bool b10[5] = {1,0,0,0,0};
//
//    const bool* bb[10]{b1, b2, b3, b4,b5,b6,b7,b8,b9,b10};
//
//
//
//    const int labelsTmp[10] = {1, 1, 2, 2,3,3,4,4,5,5};
//    const bool usedSamplesTmp[10] = {0, 0, 0,0, 0, 0,0, 0, 0, 0};
//    double result = calculateInformationGain(bb, labelsTmp, 10, 5, usedSamplesTmp, 0);
//    cout << "info gain is: "<<result << endl;

//    const bool* arr[10]{a1, a2, a3, a4,a5,a6,a7,a8,a9,a10};
//    cout << result << endl;
    d.train("train_data.txt",  498, 21);
    //cout << "annen" << endl;
    //d.train(arr, labelsTmp, 10,21);

//    cout << d.test(arr, labelsTmp, 10) << endl;
    d.print();
////
////
//    cout  << "accuracy is: " << d.test("test_data.txt", 473 ) <<"/1" << endl;
////
//    cout <<"predict: " <<d.predict(a10) << endl;

    DecisionTree tree;
//
    tree.train("difftrain_data_test.txt", 30, 10);
////    const bool testDiff[5]{0, 0, 0, 1, 0};
////    const bool testDiff2[5]{1, 0, 0, 1, 0};
////    cout << "My Prediction Diff: " << tree.predict(testDiff) << endl;
////    cout << "My Prediction Diff2: " << tree.predict(testDiff2) << endl;
//
    tree.print();
    return 0;
}

