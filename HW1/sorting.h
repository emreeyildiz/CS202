/*
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Emre YILDIZ
* ID: 21702825
* Section: 2
* Assignment: 1
* Description: sorting h file
*/

#ifndef __SORTING_H
#define __SORTING_H
#endif // __SORTING_H

void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int &compCount, int &moveCount);
void partition(int theArray[], int first, int last,
			int &pivotIndex, int &compCount, int &moveCount);

void mergeSort( int* arr, int first, int last, int &compCount, int &moveCount) ;
void merge( int theArray[], int first, int mid, int last,int &compCount, int &moveCount);
void quickSort(int* arr, int first, int last, int &compCount, int &moveCount);
void swap(int &a, int &b);
void performanceAnalysis();
