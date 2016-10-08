#include "TSorter.h"

#include <iostream>
using namespace std;

	
template <class T>
void TSorter<T>::swap(int i, int j) {
	T tmp; 
	typename vector<T>::iterator iter = array.begin();
	tmp = *(iter + i);
	*(iter + i) = *(iter + j);
	*(iter + j)= tmp; 
	return; 
}

template <class T>
TSorter<T>::TSorter() {
	numElements = 0;
	capacity = 0;
	array = vector<T>();
}

template <class T>
bool TSorter<T>::insert(T element) {
	if(numElements >= capacity) 
		return false;
	cout << "element: "<< element << endl;
	typename vector<T>::iterator iter = array.begin(); 
	*(iter + numElements++)= element;  
	return true;
}
template <class T>
TSorter<T>::TSorter(unsigned int initialCapacity) {
	capacity = initialCapacity; 
	numElements = 0;
	array = vector<T>(capacity); 
}

template <class T>
void TSorter<T>::clear() {
	numElements = 0;
	return; 
}

template <class T>
TSorter<T>::~TSorter() {
	if (!array.empty()) {
		array.clear(); 
		numElements = 0; 
	}
}

template <class T>
unsigned int TSorter<T>::makeSpace(unsigned int newCapacity) {
	if (newCapacity > capacity) {
		array.resize(newCapacity);
		capacity = newCapacity;
	}
	return capacity;
}

// Shuffle array elements
template <class T>
void TSorter<T>::shuffle() {
	unsigned int j; 
	for (unsigned int i=1; i<numElements; i++) {
		j = rand() % i; 
		swap(i, j); 
	}
}

template <class T>
void TSorter<T>::show(unsigned int n , unsigned int k) {
	typename vector<T>::iterator iter = array.begin();
	unsigned int toShow = ((n < numElements) ? n : capacity); 
	for (unsigned int i=0; i < toShow; i++) {
		if (!(i%k)) cout << endl;
		cout << *(iter + i) << " "; 
	}
	cout << endl << endl;
} 

// Iterative Insertion Sort
template <class T>
void TSorter<T>::insertionSortI() {
	cout << "Sorter::insertionSortI()" << endl << endl;
	int i, j;
	T currentNumToInsert;
	typename vector<T>::iterator iter = array.begin();
	for(i = 1; i < numElements; i ++){
		currentNumToInsert = *(iter + i);
		j = i;
		while((j > 0) && (*(iter + j - 1) > currentNumToInsert)){
			*(iter + j) = *(iter + j - 1);
			j = j -1;   
		}
	*(iter + j) = currentNumToInsert;
	}
}

// Iterative Selection Sort
template <class T>
void TSorter<T>::selectionSortI() {
	cout << "Sorter::selectionSortI()" << endl << endl;
	int i, j, min;
	typename vector<T>::iterator iter = array.begin();
	for(i = 0; i < numElements - 1; i++){
		min = i;
		for(j = i + 1; j < numElements; j++){
			if(*(iter + j) < *(iter + min)){
				min = j;            
			}           
		}
	swap(i, min);
	}
}

// Iterative Bubble Sort
template <class T>
void TSorter<T>::bubbleSortI() {
	cout << "Sorter::bubbleSortI()" << endl << endl;
	int i, j;
	typename vector<T>::iterator iter = array.begin();
	for(i = (numElements - 1); i >= 0; i--){
		for(j = 1; j <= i; j++){
			if(*(iter + j - 1) > *(iter + j)){
				swap(j-1, j);
			}
		}
	}
}
		 
// Recursive Insertion Sort
template <class T>
void TSorter<T>::insertionSortR() {
	cout << "Sorter::insertionSortI()" << endl << endl; 
	recursiveInsertionSort(0, this->array.size() - 1, this->array);
}

// Helper function for recursive insertion sort
template <class T>
void TSorter<T>::recursiveInsertionSort(int first, int end, vector<T>& elements){
	if(first < end){
		typename vector<T>::iterator iter = elements.begin();
		recursiveInsertionSort(first, end - 1, elements);
		insertionHelper2(*(iter + end), elements, first, end - 1);
	}
}
// Helper function for recursive insertion sort
template <class T>
void TSorter<T>::insertionHelper2(T element, vector<T>& elements, int first, int end){
	typename vector<T>::iterator iter = elements.begin();
	if(element > *(iter + end)){
		//Base case to stop 
		*(iter + end + 1) = element;
	}else if(first < end){
		*(iter + end + 1)  = *(iter + end) ;
		insertionHelper2(element, elements, first, end - 1);
	}else{
		//Swap case
		*(iter + end + 1)  = *(iter + end) ;
		*(iter + end) = element;
	}
}

// Recursive Selection Sort
template <class T>
void TSorter<T>::selectionSortR() {
	cout << "Sorter::selectionSortR()" << endl << endl;
	recursiveSelectionSort(0, 0, this->capacity, this->array, false);
}

// Helper function for recursive selection sort
template <class T>
void TSorter<T>::recursiveSelectionSort(int i,int j, int total, vector<T>& elements, bool done){
	T temp;
	typename vector<T>::iterator iter = elements.begin();
	if(i < total - 1){
		if(!done){
			j = i + 1;
		}
		if(j < total){
			if(*(iter + i) > *(iter + j) ){
				temp = *(iter + i);
				*(iter + i) = *(iter + j);
				*(iter + j) = temp;
			}
		recursiveSelectionSort(i, j + 1,total, elements, true);
		}
	recursiveSelectionSort(i + 1, 0, total, elements, false);
	}
}
// Recursive Bubble Sort
template <class T>
void TSorter<T>::bubbleSortR() {
	 cout << "Sorter::bubbleSortR()" << endl << endl;
	 recursiveBubbleSort(0, this->capacity, this->array);
}

template <class T>
void TSorter<T>::recursiveBubbleSort(int startInd, int total, vector<T>& elements){
	typename vector<T>::iterator iter = elements.begin();
	if(startInd > total){
			return;
	}
	if(startInd == total - 1){
			recursiveBubbleSort(0, total - 1, elements);
	}else if(*(iter + startInd) > *(iter + startInd + 1)){
			T tempNum = *(iter + startInd);
			*(iter + startInd) =*(iter + startInd + 1);
			*(iter + startInd + 1) = tempNum;
			recursiveBubbleSort(startInd + 1, total, elements);
	}else{
			recursiveBubbleSort(startInd + 1, total, elements);
	}
}
