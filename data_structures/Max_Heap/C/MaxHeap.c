#include <stdio.h>
#include <stdlib.h>
void heapsort(int *arr, int i);
void heapify(int* arr,int n);
void percolateDown(int* arr, int i, int n);
void percolateUp(int* arr, int i);
void print(int* arr, int n);
int main(){
	int num=0;
	int *ptr;
	scanf("%d",&num);
	int p = num+51;
	ptr = (int*) calloc(p,4);
	int j=1;
	for(j=1;j<=num;j++){
		scanf("%d",ptr+j);
	}
	heapify(ptr , num);
	int test=0;
	scanf("%d",&test);
	for(int k=0;k<test;k++){
		int curr;
		scanf("%d",&curr);
		if (curr==0){
			print(ptr,num);
		}
		else if (curr==1){
			heapsort(ptr,num);//do heap sort and the print 
		}
		else if (curr==2){
			int number=0;
			scanf("%d",&number);
			num++;
			ptr[num]=number;//add i.e. percolate up then print
			percolateUp(ptr, num);
			print(ptr, num);
		}
		else if (curr==3){
			ptr[1]=ptr[num];
			num--;
			percolateDown(ptr, 1, num);
			print(ptr, num);
			//remove max and then percolate down
		}
		else{
			printf("%d\n",ptr[1]);
		}
	}
	free(ptr);
	return 0;
}

void heapify(int* arr,int n){
	for(int i=n/2;i>0;i--){
		percolateDown(arr , i, n);
	}
}

void percolateDown(int* arr, int i, int n){
	while(2*i<=n){
		int val = *(arr+i);
		int left = 2*i;
		int right=2*i +1;
		int target;
		if (right<=n && *(arr + right) > *(arr + left)){
			target=right;
		}
		else 
			target = left;
		if (*(arr+target)>*(arr+i)){
			arr[i]=*(arr+target);
			arr[target] =val;
			i=target;
		}
		else break;
	}
}

void print(int *arr, int n){
	for (int k=1;k<=n;k++){
		printf("%d ",*(arr+k));
	}
	printf("\n");
}
void percolateUp(int *arr, int i){
	int number = arr[i];
	int parent = i/2;
	//printf("%d\n",parent);
	while (parent>0){
		if (number>arr[parent]){
			//printf("%d\n",arr[parent]);
			arr[i]=arr[parent];

			arr[parent]=number;
			i=parent;
			parent = parent/2;

			//printf("%d\n",parent);
		}
		else break;
	}
}
void heapsort(int *arr, int n){
	int temp[n+1];
	int numb=n;
	for(int k=1;k<=n;k++){
		temp[k]=arr[k];
	}
	int temp2[n+1];
	while(numb>0){
		temp2[numb] = temp[1];
		temp[1]=temp[numb];
		numb--;
		percolateDown(temp, 1 , numb);
	}
	print(temp2,n);
}
