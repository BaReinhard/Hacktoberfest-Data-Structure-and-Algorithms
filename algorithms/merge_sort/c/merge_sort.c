#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int start,int middle,int end){
	int* temp;
	int p1, p2, len, i, j, k, end1 = 0, end2 = 0;
	len = end - start + 1;
	p1 = start;
	p2 = middle+1;
	temp = (int*)malloc(sizeof(int)*len);
	if(temp != NULL){
		for(i=0;i<len;i++){
			if(!end1 && !end2){
				if(arr[p1] < arr[p2]){
					temp[i] = arr[p1];
					p1++;
				}
				else{
					temp[i] = arr[p2];
					p2++;
				}
				if(p1 > middle){
					end1 = 1;
				}
				if(p2 > end){
					end2 = 1;
				}
			}
			else{
				if(!end1){
					temp[i] = arr[p1];
					p1++;
				}
				else{
					temp[i] = arr[p2];
					p2++;
				}
			}
		}
	}
	k = start;
	for(j=0;j<len;j++){
		arr[k] = temp[j];
		k++;
	}
	free(temp);
}

void mergesort(int arr[],int start, int end){
	int middle;
	if(start < end){
		middle = (start+end)/2;
		mergesort(arr,start, middle);
		mergesort(arr,middle+1, end);
		merge(arr,start,middle,end);
	}
}

void showVector(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[10] = {7,2,3,1,8,9,6,5,4,10};
	mergesort(arr,0,9);
	showVector(arr,10);
	return 0;
}