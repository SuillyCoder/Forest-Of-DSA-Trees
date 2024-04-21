#ifndef HEADER_H
#define HEADER_H

void heapify(int numArray[], int arrSize, int i);
void insertNode(int numArray[], int newNum, int arrSize);
void swapNodes(int *a, int *b);

void printArray(int numArray[], int arrSize);
void searchTreePrint(int numArray[], int arrSize);

void deleteRoot (int numArray[], int arrSize);

#endif
