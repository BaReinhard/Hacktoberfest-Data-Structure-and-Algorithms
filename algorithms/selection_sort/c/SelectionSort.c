#include<stdio.h>

const int SIZE=100;

void SelectionSort(int arr[SIZE]){
  int i,j,temp,min=999999,index;
  for (i = 0; i < SIZE; i++) {
    for (j = i; j < SIZE; j++) {
      if(arr[j]<min){
        min=arr[j];
        index=j;
      }
    }
    temp=arr[i];
    arr[i]=arr[index];
    arr[index]=temp;
    index=0;
    min=999999;
  }

}

void main(){
	int i;
	int arr[SIZE];
	printf("Enter the unsorted array\n");
	for(i=0;i<SIZE;i++)
		scanf("%d",&arr[i]);
	SelectionSort(arr);	
	printf("Sorted array is\n");
	for(i=0;i<SIZE;i++)
		printf("%d ",arr[i]);
}
