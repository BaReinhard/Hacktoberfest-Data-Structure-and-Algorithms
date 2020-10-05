#include<stdio.h>

/*
A dynamic approach to solve fibonacci number series which have -
 time complexity = O(n)
 space complexity = O(1)

*/


int iterFibo(int n){
	int prev = 1;
	int curr = 0;
	int next;
	for(int i=1;i<n;i++){
		next = curr + prev;
		prev = curr;
		curr = next;
	}
	return curr;
}


int main(){
	int num;
	printf("Which fibonacci number you want to get? - ");
	scanf("%d",&num);
	int fib = iterFibo(num);
	printf("%dth fibonacci number is %d\n",num,fib);
}