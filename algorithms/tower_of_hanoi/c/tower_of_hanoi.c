#include<stdio.h>
int moves;
void hanoi(char from, char intermediate, char to, int n){

	if(n==1){
		printf("Move disc from %c to %c\n",from,to);
		moves++;
	}
	else{ 
		hanoi(from,to,intermediate,n-1);
		hanoi(from,intermediate,to,1);
		hanoi(intermediate,from,to,n-1);
	}

}
void main(){
	int n;
	scanf("%d",&n);
	hanoi('1','2','3',n);
	printf("No of moves required: %d\n", moves);
}




