/*
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Emre YILDIZ
* ID: 21702825
* Section: 2
* Assignment: 1
* Description: sorting file including Insertion, Quick, Merge Sort and performance analysis of them
To compile it, c++11 should be used in order to use high_resolution_clock chrono
*/

#include <ctime>
#include <iostream>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "auxArrayFunctions.h"
#include "sorting.h"
#ifndef __SORTING_H
#define __SORTING_H
#endif // __SORTING_H


using namespace std;

void insertionSort(int *arr, int n, int &compCount, int &moveCount)
{
   for (int unsorted = 1; unsorted < n; ++unsorted) {
    int nextItem = arr[unsorted];
    int loc = unsorted;
    moveCount = moveCount + 2;
    for (  ;(loc > 0) &&(++compCount)&& (arr[loc-1] > nextItem); --loc){
       arr[loc] = arr[loc-1];
       moveCount++;
    }
    arr[loc] = nextItem;
  }
}
void quickSort(int *arr, int size, int &compCount, int &moveCount)
{
    quickSort(arr, 0, size-1,compCount,moveCount);
}

void quickSort(int theArray[], int first, int last, int &compCount, int &moveCount)
{
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex,compCount,moveCount);

      // sort regions S1 and S2
      quickSort(theArray, first, pivotIndex-1,compCount,moveCount);
      quickSort(theArray, pivotIndex+1, last,compCount,moveCount);
   }
}

void partition(int theArray[], int first, int last,
			int &pivotIndex,int &compCount, int &moveCount) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

	// place pivot in theArray[first]

   int pivot = theArray[first]; // copy pivot

       // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if ((++compCount)&&theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
    	  moveCount = moveCount +3;
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   moveCount = moveCount + 3;
   pivotIndex = lastS1;
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount)
{
    mergeSort(arr, 0, size-1, compCount, moveCount);
}



void mergeSort( int theArray[], int first, int last, int &compCount, int &moveCount) {

	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint
void swap(int* a, int* b);
      mergeSort(theArray, first, mid,compCount,moveCount);

      mergeSort(theArray, mid+1, last,compCount,moveCount);

      // merge the two halves
      merge(theArray, first, mid, last, compCount, moveCount);
   }
}  // end mergesort


const int MAX_SIZE = 100000;

void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount) {

	int tempArray[MAX_SIZE]; 	// temporary array

	int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {

      if ((++compCount)&&(theArray[first1] < theArray[first2])) {
         tempArray[index] = theArray[first1];
         ++first1;
         moveCount++;
      }
      else {
          tempArray[index] = theArray[first2];
          ++first2;
          moveCount++;
      }
   }
   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index){
      tempArray[index] = theArray[first1];
      moveCount++;
   }
   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index){
      tempArray[index] = theArray[first2];
      moveCount++;
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index){
      theArray[index] = tempArray[index];
      moveCount++;
   }
}  // end merge


void swap(int& a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}



void performanceAnalysis()
{
    using namespace std::chrono;
    int *arr1, *arr2, *arr3;
    int compCount1 = 0;
    int moveCount1 = 0;
    double* elapsed = new double[18];
    int* compCount = new int[18];
    int* moveCount = new int[18];
    int j = 0;

    for(int i = 5000; i <= 30000; i = i + 5000)
    {
        int compCount1 = 0;
        int moveCount1 = 0;
        createRandomArrays(arr1, arr2, arr3, i);
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        insertionSort(arr1,i, compCount1, moveCount1);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

        elapsed[j] = 1000*time_span.count();
        compCount[j] = compCount1;
        moveCount[j] = moveCount1;

        compCount1 = 0;
        moveCount1 = 0;
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        mergeSort(arr2,i, compCount1, moveCount1);
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        duration<double> time_span2 = duration_cast<duration<double>>(t4 - t3);

        elapsed[j+6] = 1000*time_span2.count();
        compCount[j+6] = compCount1;
        moveCount[j+6] = moveCount1;

        compCount1 = 0;
        moveCount1 = 0;
        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        quickSort(arr3,i, compCount1, moveCount1);
        high_resolution_clock::time_point t6 = high_resolution_clock::now();
        duration<double> time_span3 = duration_cast<duration<double>>(t6 - t5);

        elapsed[j+12] = 1000*time_span3.count();
        compCount[j+12] = compCount1;
        moveCount[j+12] = moveCount1;
        j++;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

    }

    cout << "Part c - Time analysis of Insertion Sort (Random Array)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout <<"Array Size" << setw(20) << "Time Elapsed" << setw(19) << "compCount" << setw(20) << "moveCount" << endl;
    for (int k = 1; k < 7; k++)
    {
        if(k == 1)
            cout << 5000*k << setw(21) << elapsed[k-1] << "ms." << setw(20) << compCount[k-1] << setw(20) << moveCount[k-1] << endl;
        else
            cout << 5000*k << setw(20) << elapsed[k-1] << "ms." << setw(20) << compCount[k-1] << setw(20) << moveCount[k-1] << endl;
    }
    cout << endl;
    cout << "Part c - Time analysis of Merge Sort (Random Array)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout <<"Array Size" << setw(20) << "Time Elapsed" << setw(19) << "compCount" << setw(20) << "moveCount" << endl;
    for (int k = 1; k < 7; k++)
    {
        if(k == 1)
            cout << 50000*k << setw(21) << elapsed[k+5] << "ms." << setw(20) << compCount[k+5] << setw(20) << moveCount[k+5] << endl;
        else
            cout << 50000*k << setw(20) << elapsed[k+5] << "ms." << setw(20) << compCount[k+5] << setw(20) << moveCount[k+5] << endl;
    }

    cout << endl;
    cout << "Part c - Time analysis of Quick Sort (Random Array)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout <<"Array Size" << setw(20) << "Time Elapsed" << setw(19) << "compCount" << setw(20) << "moveCount" << endl;

    for (int k = 1; k < 7; k++)
    {
        if (k == 1)
            cout  <<5000*k << setw(21) << elapsed[k+11] << "ms." << setw(20) << compCount[k+11] << setw(20) << moveCount[k+11] << endl;
        else
            cout << 5000*k << setw(20) << elapsed[k+11] << "ms." << setw(20) << compCount[k+11] << setw(20) << moveCount[k+11] << endl;
    }
        delete[] compCount;
        delete[] moveCount;
        delete[] elapsed;

compCount1 = 0;
moveCount1 = 0;
elapsed = new double[18];
compCount = new int[18];
moveCount = new int[18];
j = 0;


for(int i = 5000; i <= 30000; i = i + 5000)
    {
        int compCount1 = 0;
        int moveCount1 = 0;
        createAlreadySortedArrays(arr1, arr2, arr3, i);
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        insertionSort(arr1,i, compCount1, moveCount1);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

        elapsed[j] = 1000*time_span.count();
        compCount[j] = compCount1;
        moveCount[j] = moveCount1;

        compCount1 = 0;
        moveCount1 = 0;
        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        mergeSort(arr2,i, compCount1, moveCount1);
        high_resolution_clock::time_point t4 = high_resolution_clock::now();
        duration<double> time_span2 = duration_cast<duration<double>>(t4 - t3);

        elapsed[j+6] = 1000*time_span2.count();
        compCount[j+6] = compCount1;
        moveCount[j+6] = moveCount1;

        compCount1 = 0;
        moveCount1 = 0;
        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        quickSort(arr3,i, compCount1, moveCount1);
        high_resolution_clock::time_point t6 = high_resolution_clock::now();
        duration<double> time_span3 = duration_cast<duration<double>>(t6 - t5);

        elapsed[j+12] = 1000*time_span3.count();
        compCount[j+12] = compCount1;
        moveCount[j+12] = moveCount1;

        j++;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

    }

    cout << "Part c - Time analysis of Insertion Sort (Sorted Array)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout <<"Array Size" << setw(20) << "Time Elapsed" << setw(19) << "compCount" << setw(20) << "moveCount" << endl;
    for (int k = 1; k < 7; k++)
    {
        if(k == 1)
            cout << 5000*k << setw(21) << elapsed[k-1] << "ms." << setw(20) << compCount[k-1] << setw(20) << moveCount[k-1] << endl;
        else
            cout << 5000*k << setw(20) << elapsed[k-1] << "ms." << setw(20) << compCount[k-1] << setw(20) << moveCount[k-1] << endl;
    }
    cout << endl;
    cout << "Part c - Time analysis of Merge Sort (Sorted Array)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout <<"Array Size" << setw(20) << "Time Elapsed" << setw(19) << "compCount" << setw(20) << "moveCount" << endl;
    for (int k = 1; k < 7; k++)
    {
        if(k == 1)
            cout << 50000*k << setw(21) << elapsed[k+5] << "ms." << setw(20) << compCount[k+5] << setw(20) << moveCount[k+5] << endl;
        else
            cout << 50000*k << setw(20) << elapsed[k+5] << "ms." << setw(20) << compCount[k+5] << setw(20) << moveCount[k+5] << endl;
    }

    cout << endl;
    cout << "Part c - Time analysis of Quick Sort (Sorted Array)" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout <<"Array Size" << setw(20) << "Time Elapsed" << setw(19) << "compCount" << setw(21) << "moveCount" << endl;

    for (int k = 1; k < 7; k++)
    {
        if (k == 1)
            cout  <<5000*k << setw(22) << elapsed[k+11] << "ms." << setw(20) << compCount[k+11] << setw(20) << moveCount[k+11] << endl;
        else
            cout << 5000*k << setw(21) << elapsed[k+11] << "ms." << setw(20) << compCount[k+11] << setw(20) << moveCount[k+11] << endl;
    }
        delete[] compCount;
        delete[] moveCount;
        delete[] elapsed;

}


