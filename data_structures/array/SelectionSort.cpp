#include <iostream>

using namespace std;

void selectionSort(int array[], int sizeOfArray){
    
    int minIndex,temp; // Declare the variables.
    // Implement Selection Sort.
    for(int i=0; i<sizeOfArray-1; i++){
            minIndex = i;
            for(int j=i+1; j<sizeOfArray; j++){
                if(array[j]<array[minIndex]){
                    minIndex = j;
                }
            }
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    
}

int main()
{
    int sizeOfArray; // Declare the variable.
    cout<<"Enter the size of an array: "; // Message for user.
    cin>>sizeOfArray; // Take input from user.
    
    int array[sizeOfArray]; // Declare array.
    cout<<"Enter the elements of an array: "; // Message for user.
    for(int index=0; index<sizeOfArray; index++){
        cin>>array[index]; // Take input from user.
    }
    
    selectionSort(array,sizeOfArray); // Call the selectionSort function.
    
    for(int index=0; index<sizeOfArray; index++){
        cout<<array[index]<<" "; // Display the sorted array.
    }

    return 0;
}
