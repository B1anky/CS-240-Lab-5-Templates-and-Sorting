#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

#include "TSorter.h"
#include "TSorter.cpp"
#include "Color.h"

#define DEFAULT_NUMVALUES 10
#define MAX_NUMVALUES 1000
#define MIN_NUMVALUES 1

int main (int argc, char **argv) {
    unsigned int numValues = DEFAULT_NUMVALUES; 


    if (argc > 1)
        numValues = atoi(argv[1]);  
    if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
        cerr << "Specify numValues in the range [" << MIN_NUMVALUES; 
        cerr << ", " << MAX_NUMVALUES << endl; 
        cerr << "\nUsage: " << argv[0] << " {numValues}" << endl; 
    }
    if (argc > 2) 
        cerr << "Ignoring extra command line arguments." << endl; 

    cout << endl << "Generating " << numValues << " double values for sorting." << endl; 
    TSorter<int> s;
    s.makeSpace(numValues); 
    TSorter<double> doubleSort;
    doubleSort.makeSpace(numValues); 
    TSorter<string> abcd;
    abcd.makeSpace(numValues);
    TSorter<Color> colors;
    colors.makeSpace(numValues); 

    srand(time(NULL)); // use this line for pseudo-random numbers 
    // srand(23);      // use this line for deterministic "random" numbers

    cout << endl << "---------Testing integer sort with Template---------" << endl << endl;

    int valueInt;
    for (unsigned int i=0; i < numValues; i++) {
        valueInt = rand() % 100;  
        s.insert(valueInt); 
    } 

    cout << "Initial array: ";
    s.show(25, 10); 

    s.insertionSortI();
    cout << "After iterative Insertion Sort:";
    s.show(25, 10); 

    s.shuffle(); 
    cout << "Shuffled: "; 
    s.show(25, 10); 

    s.selectionSortI();
    cout << "After iterative Selection Sort:";
    s.show(25, 10);

    s.shuffle(); 
    cout << "Shuffled: "; 
    s.show(25, 10); 

    s.bubbleSortI();
    cout << "After iterative Bubble Sort:";
    s.show(25, 10); 

    s.shuffle(); 
    cout << "Shuffled: "; 
    s.show(25, 10); 

    s.insertionSortR();
    cout << "After recursive Insertion Sort:";
    s.show(25, 10); 

    s.shuffle(); 
    cout << "Shuffled: "; 
    s.show(25, 10); 

    s.selectionSortR();
    cout << "After recursive Selection Sort:";
    s.show(25, 10); 

    s.shuffle(); 
    cout << "Shuffled: "; 
    s.show(25, 10); 

    s.bubbleSortR();
    cout << "After recursive Bubble Sort:";
    s.show(25, 10); 

    s.shuffle(); 
    cout << "Shuffled: "; 
    s.show(25, 10); 

    cout << endl << "---------Testing double sort with Template---------" << endl << endl;

    double doubleValue;
    for (unsigned int i=0; i < numValues; i++) {
        doubleValue = (static_cast <float> (rand()) / static_cast <float> (10))/1000000;  
        doubleSort.insert(doubleValue); 
    }

    cout << "Initial array: ";
    doubleSort.show(25, 10); 

    doubleSort.insertionSortI();
    cout << "After iterative Insertion Sort:";
    doubleSort.show(25, 10); 

    doubleSort.shuffle(); 
    cout << "Shuffled: "; 
    doubleSort.show(25, 10); 

    doubleSort.selectionSortI();
    cout << "After iterative Selection Sort:";
    doubleSort.show(25, 10);

    doubleSort.shuffle(); 
    cout << "Shuffled: "; 
    doubleSort.show(25, 10); 

    doubleSort.bubbleSortI();
    cout << "After iterative Bubble Sort:";
    doubleSort.show(25, 10); 

    doubleSort.shuffle(); 
    cout << "Shuffled: "; 
    doubleSort.show(25, 10); 

    doubleSort.insertionSortR();
    cout << "After recursive Insertion Sort:";
    doubleSort.show(25, 10); 

    doubleSort.shuffle(); 
    cout << "Shuffled: "; 
    doubleSort.show(25, 10); 

    doubleSort.selectionSortR();
    cout << "After recursive Selection Sort:";
    doubleSort.show(25, 10); 

    doubleSort.shuffle(); 
    cout << "Shuffled: "; 
    doubleSort.show(25, 10); 

    doubleSort.bubbleSortR();
    cout << "After recursive Bubble Sort:";
    doubleSort.show(25, 10); 

    doubleSort.shuffle(); 
    cout << "Shuffled: "; 
    doubleSort.show(25, 10); 


cout << endl << "---------Testing strings sort with Template---------" << endl << endl;
	
    //hard coded this example since it was easier to compare online for accuracy
    abcd.insert("This");
    abcd.insert("is");
    abcd.insert("a");
    abcd.insert("test");
    abcd.insert("and");
    abcd.insert("hope");
    abcd.insert("it");
    abcd.insert("works");
    abcd.insert("well");
    abcd.insert("enough");

    cout << "Initial array: ";
    abcd.show(25, 10); 

    abcd.insertionSortI();
    cout << "After iterative Insertion Sort:";
    abcd.show(25, 10); 

    abcd.shuffle(); 
    cout << "Shuffled: "; 
    abcd.show(25, 10); 

    abcd.selectionSortI();
    cout << "After iterative Selection Sort:";
    abcd.show(25, 10);

    abcd.shuffle(); 
    cout << "Shuffled: "; 
    abcd.show(25, 10); 

    abcd.bubbleSortI();
    cout << "After iterative Bubble Sort:";
    abcd.show(25, 10); 

    abcd.shuffle(); 
    cout << "Shuffled: "; 
    abcd.show(25, 10); 

    abcd.insertionSortR();
    cout << "After recursive Insertion Sort:";
    abcd.show(25, 10); 

    abcd.shuffle(); 
    cout << "Shuffled: "; 
    abcd.show(25, 10); 

    abcd.selectionSortR();
    cout << "After recursive Selection Sort:";
    abcd.show(25, 10); 

    abcd.shuffle(); 
    cout << "Shuffled: "; 
    abcd.show(25, 10); 

    abcd.bubbleSortR();
    cout << "After recursive Bubble Sort:";
    abcd.show(25, 10); 

    abcd.shuffle(); 
    cout << "Shuffled: "; 
    abcd.show(25, 10); 

    cout << endl << "------Testing Color sort with Template (Sorted by distance from black)------" << endl << endl;
	
    //hard coded this example since it was easier to compare online for accuracy
    
    Color white("White", 255, 255, 255);
    colors.insert(white);
    Color pink("Pink", 255, 192, 203);
    colors.insert(pink);
    Color blue("Blue", 0, 0, 255);
    colors.insert(blue);
    Color macNCheese("MacNCheese", 255, 189, 136);
    colors.insert(macNCheese);
    Color seafoamGreen("Seafoam-Green", 10, 153, 114);
    colors.insert(seafoamGreen);
    Color brown("brown", 32, 32, 32);
    colors.insert(brown);
    Color red("Red", 255, 0, 0);
    colors.insert(red);
    Color periwinkle("Periwinkle", 204, 204, 255);
    colors.insert(periwinkle);
    Color CS240("CS240", 240, 240, 240);
    colors.insert(CS240);
    Color black("Black", 0, 0, 0);
    colors.insert(black);

    cout << "Initial array: ";
    colors.show(25, 10); 

    colors.insertionSortI();
    cout << "After iterative Insertion Sort:";
    colors.show(25, 10); 

    colors.shuffle(); 
    cout << "Shuffled: "; 
    colors.show(25, 10); 

    colors.selectionSortI();
    cout << "After iterative Selection Sort:";
    colors.show(25, 10);

    colors.shuffle(); 
    cout << "Shuffled: "; 
    colors.show(25, 10); 

    colors.bubbleSortI();
    cout << "After iterative Bubble Sort:";
    colors.show(25, 10); 

    colors.shuffle(); 
    cout << "Shuffled: "; 
    colors.show(25, 10); 

    colors.insertionSortR();
    cout << "After recursive Insertion Sort:";
    colors.show(25, 10); 

    colors.shuffle(); 
    cout << "Shuffled: "; 
    colors.show(25, 10); 

    colors.selectionSortR();
    cout << "After recursive Selection Sort:";
    colors.show(25, 10); 

    colors.shuffle(); 
    cout << "Shuffled: "; 
    colors.show(25, 10); 

    colors.bubbleSortR();
    cout << "After recursive Bubble Sort:";
    colors.show(25, 10); 

    colors.shuffle(); 
    cout << "Shuffled: "; 
    colors.show(25, 10); 
}

