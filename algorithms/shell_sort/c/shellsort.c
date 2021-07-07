#include <stdio.h>
#define SIZE 3 //array size

int * shellSort(int nums[SIZE]){
	int gap = 1;
	int aux, i, j;
	while(gap > 0){
		for(i = gap; i < SIZE; i++){
			aux = nums[i];
			j = i;
			while((j >= gap) && (aux < nums[j - gap])){
				nums[j] = nums[j - gap];
				j -= gap;
				nums[j] = aux;
			}
		}
		gap = (int)(gap/2.2);
	}
	return nums;
}

int main(){
	int array[SIZE] = {3, 1, 2};
	
	for(int l = 0; l < SIZE; l++) printf("array[%d]: %d ", l, array[l]);
	printf("\n");
	
	shellSort(array);
	
	for(int l = 0; l < SIZE; l++) printf("array[%d]: %d ", l, array[l]);
	printf("\n");
	
	return 0;
}
