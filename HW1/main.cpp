/*
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Emre YILDIZ
* ID: 21702825
* Section: 2
* Assignment: 1
* Description: Main function
*/

#include "sorting.h"
#include "auxArrayFunctions.h"
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
int main(){
using namespace std::chrono;
    int arr[] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int arr1[] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int arr2[] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    int size = 16;

    cout << "--------------------------------------------------Calling insertion sort--------------------------------------------------" << endl;
    int compCount = 0;
    int moveCount = 0;
    insertionSort(arr2, size, compCount, moveCount);
    displayArray(arr2, size);
    cout <<"CompCount for InsertionSort is: " << compCount << endl;
    cout <<"MoveCount for quickSort is: " << moveCount << "\n"<< endl;

    cout << "----------------------------------------------------Calling Merge sort----------------------------------------------------" << endl;
    compCount = 0;
    moveCount = 0;
    mergeSort(arr1, size, compCount, moveCount);
    displayArray(arr1, size);
    cout << "CompCount for MergeSort is:" << compCount << endl;
    cout << "MoveCount for quickSort is: " << moveCount <<"\n"<< endl;

    cout << "----------------------------------------------------Calling Quick sort----------------------------------------------------" << endl;
    compCount = 0;
    moveCount = 0;
    quickSort(arr, size, compCount, moveCount);
    displayArray(arr, size);
    cout <<"CompCount for QuickSort is:" << compCount << endl;
    cout <<"MoveCount for quickSort is: " << moveCount << endl;
    //performanceAnalysis();

    return 0;


}

