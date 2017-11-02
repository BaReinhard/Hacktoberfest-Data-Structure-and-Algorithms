// Insert the following numbers into the heap, printing the heap after each insert:
//  2  3  7 22  5 21  1 28  4 16  0 17 12 18 20 25

// deleteMin() the numbers in the heap, into a new list (array or vector is fine), printing the heap after each deleteMin() (I want to see how your heap structure changes after each deleteMin).
// Print the new sorted list of numbers.
#include "minHeap.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

int main(){
    int unsortedNums[] = {2, 3, 7, 22, 5, 21, 1, 28, 4, 16, 0, 17, 12, 18, 20, 25};
    int sortedNums[16];
    MinHeap heap;
    
    cout << "Printing unsorted List: \n";
    for(int k = 0;k<16;k++){
        cout << unsortedNums[k] << ", ";
    }
    cout << "\n\n========================================================\nInserting to min heap: \n";
    for(int i = 0;i<16;i++){
        heap.insert(unsortedNums[i]);
        heap.printSelf();
        cout << endl;
    }
    cout << "========================================================\nSorting List: \n";
    for(int j = 0;j<16;j++){
        int min = heap.deleteMin();
        sortedNums[j] = min;
        heap.printSelf();
        cout << endl;
    }
    cout << "========================================================\nPrinting Sorted List: \n";
    for(int k = 0;k<16;k++){
        cout << sortedNums[k] << ", ";
    }
    cout << endl;
}
