#include <iostream>
#include <stdbool.h>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Insertion Sort
void Sorter::insertionSortI() {
    cout << "Sorter::insertionSortI()" << endl << endl;
    int i, j , currentNumToInsert;
    for(i = 1; i < numElements; i ++){
        currentNumToInsert = array[i];
        j = i;
        while((j > 0) && (array[j-1] > currentNumToInsert)){
            array[j] = array[j-1];
            j = j -1;	
        }
    array[j] = currentNumToInsert;
    }
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
    cout << "Sorter::selectionSortI()" << endl << endl;
    int i, j, min;
    for(i = 0; i < numElements - 1; i++){
        min = i;
        for(j = i + 1; j < numElements; j++){
            if(array[j] < array[min]){
                min = j;		
            }		
        }
        swap(i, min);
    }
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
    cout << "Sorter::bubbleSortI()" << endl << endl;
    int i, j;
    for(i = (numElements - 1); i >= 0; i--){
        for(j = 1; j <= i; j++){
            if(array[j-1] > array[j]){
                swap(j-1, j);
	}
        }
    }
}
     
// Recursive Insertion Sort
void Sorter::insertionSortR() {
    cout << "Sorter::insertionSortI()" << endl << endl; 
    recursiveInsertionSort(0, this->capacity - 1, this->array);
}

// Helper function for recursive insertion sort
void Sorter::recursiveInsertionSort(int first, int total, int* elements){
    if(first < total){
        recursiveInsertionSort(first, total -1, elements);
        insertionHelper2(elements[total], elements, first, total -1);
    }
}
// Helper function for recursive insertion sort
void Sorter::insertionHelper2(int element, int* elements, int first, int total){
    if(element >= elements[total]){
        elements[total + 1] = element;
    }else if(first < total){
        elements[total + 1] = elements[total];
        insertionHelper2(element, elements, first, total - 1);
    }else{
        elements[total + 1] = elements[total];
        elements[total] = element;
    }
}

// Recursive Selection Sort
void Sorter::selectionSortR() {
   cout << "Sorter::selectionSortR()" << endl << endl;
   recursiveSelectionSort(0, 0, this->capacity, this->array, false);
}

// Helper function for recursive selection sort
void Sorter::recursiveSelectionSort(int i,int j, int total, int* elements, bool done){
    int temp;
    if(i < total - 1){
        if(!done){
            j = i + 1;
        }
        if(j < total){
            if(elements[i] > elements[j]){
                temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
            recursiveSelectionSort(i, j + 1,total, elements, true);
        }
    recursiveSelectionSort(i + 1, 0, total, elements, false);
    }
}
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
   cout << "Sorter::bubbleSortR()" << endl << endl;
   recursiveBubbleSort(0, this->capacity, this->array);
}

void Sorter::recursiveBubbleSort(int startInd, int total, int* elements){
    if(startInd > total){
        return;
    }
    if(startInd == total - 1){
        recursiveBubbleSort(0, total - 1, elements);
    }else if(elements[startInd] > elements[startInd + 1]){
        int tempNum = elements[startInd];
        elements[startInd] = elements[startInd + 1];
        elements[startInd + 1] = tempNum;
        recursiveBubbleSort(startInd + 1, total, elements);
    }else{
        recursiveBubbleSort(startInd + 1, total, elements);
    }
}

