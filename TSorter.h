#ifndef TSORTER
#define TSORTER
#include <vector>
#include <iostream>
#include <stdbool.h>
#include <cstdlib>
using namespace std;

template <class T>
class TSorter {
	private:
	vector<T> array;
	unsigned int numElements;
	unsigned int capacity;

	void swap(int i, int j); 

public:
	TSorter();

	TSorter(unsigned int initialCapacity);
	~TSorter();

	void clear(); 
	bool insert(T value); 

	// Make sure the array contains at least newCapacity elements.
	// If not, grow it to that size and copy in old values
	unsigned int makeSpace(unsigned int newCapacity); 

	// Show the first n elements, k per line using << 
	void show(unsigned int n, unsigned int k); 

	// "Shuffle" the array elements
	void shuffle(); 

	// These are the functions you should implement for Lab 5
	// You should keep these interfaces the same, but you may add
	// other "helper" functions if necessary.
	void insertionSortI();
	void selectionSortI();
	void bubbleSortI();     
	void insertionSortR(); 
	void recursiveInsertionSort(int total, vector<T>&  elements);
	void insertionHelper2(T element, vector<T>&  elements, int first, int total);
	void recursiveInsertionSort(int first, int total, vector<T>&  elements);
	void selectionSortR();
	void recursiveSelectionSort(int i,int j, int total, vector<T>& elements, bool done);
	void bubbleSortR(); 
	void recursiveBubbleSort(int startInd, int total, vector<T>&  elements);
};
#endif
