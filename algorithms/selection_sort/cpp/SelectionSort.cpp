#include<bits/stdc++.h>
using namespace std;

#define SIZE 5

void SelectionSort(int arr[]){
    for(int i=0; i<SIZE-1; i++){
        int min = i;
        for(int j=i+1; j<SIZE; j++){
            if(arr[j] < arr[min])
                min = j;
            swap(arr[min],arr[i]);
        }
    }
}

int main(){
	int arr[SIZE];

    cout << "Enter the unsorted array:\n";

	for(int i=0; i<SIZE; i++)
        cin >> arr[i];

	SelectionSort(arr);

	cout << "Sorted array is:\n";

	for(int i=0; i<SIZE; i++)
		cout << arr[i] << " ";
}
