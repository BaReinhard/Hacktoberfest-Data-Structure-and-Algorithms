#include<stdio.h>
#define pegs 5

int src_array[pegs],aux_array[pegs],des_array[pegs];
int s,a,d;

void print_array(){
	printf("+----+----+----+\n");
	int max=s;
	if(max<a)max=a;
	if(max<d)max=d;
	for(int i=max;i>=0;i--){
		if(i<=s)printf("| %2d ",src_array[i]);
		else printf("|    ");

		if(i<=a)printf("| %2d ",aux_array[i]);
		else printf("|    ");

		if(i<=d)printf("| %2d ",des_array[i]);
		else printf("|    ");

		printf("|\n");
	}
}
void main(){

	// formulae for optimal number of step is 2^(n)-1
	unsigned long sum = 1;
	for(int i=0;i<pegs;i++)sum*=2;
	sum -= 1;

	//initializing array
	for(s=0;s<pegs;s++)src_array[s]=pegs-s;

	//initializing headers
	s=pegs-1,a=-1,d=-1;

	int smallest=0,r,l;

	int *structure_array[]={src_array,aux_array,des_array};
	int *structure[]={&s,&a,&d};

	unsigned long count=0;
	print_array();
	while(1){

		if(pegs%2 == 0){ //shift to right SRC->AUX->DES

			//moving the smallest element

			r = smallest+1;
			if(r==3)r=0;

			if((*(structure[r])) == -1 || structure_array[r][(*(structure[r]))] > structure_array[smallest][(*(structure[smallest]))]){
				structure_array[r][++(*(structure[r]))] = structure_array[smallest][(*(structure[smallest]))--];
				smallest = r;
			}
			else{
				r = smallest+2;
				if(r==3)r=0;

				structure_array[r][++(*(structure[r]))] = structure_array[smallest][(*(structure[smallest]))--];
				smallest = r;
			}

			count++;
			print_array();
			if(d == pegs-1)break;

			//moving the second smallest element

			r = smallest+1;
			if(r==3)r=0;

			l = smallest-1;
			if(l==-1)l=2;

			if((*(structure[r])) == -1 || ((*(structure[l]))!= -1 && structure_array[r][(*(structure[r]))] > structure_array[l][(*(structure[l]))])){
				structure_array[r][++(*(structure[r]))] = structure_array[l][(*(structure[l]))--];
			}
			else{
				structure_array[l][++(*(structure[l]))] = structure_array[r][(*(structure[r]))--];
			}

			count++;
			print_array();

		}
		else{//shift to left SRC<-AUX<-DES

			//moving the smallest element

			r = smallest-1;
			if(r<0)r+=3;

			if((*(structure[r])) == -1 || structure_array[r][(*(structure[r]))] > structure_array[smallest][(*(structure[smallest]))]){
				structure_array[r][++(*(structure[r]))] = structure_array[smallest][(*(structure[smallest]))--];
				smallest = r;
			}
			else{
				r = smallest-2;
				if(r<0)r+=3;

				structure_array[r][++(*(structure[r]))] = structure_array[smallest][(*(structure[smallest]))--];
				smallest = r;
			}
			count++;
			print_array();
			if(d == pegs-1)break;

			//moving the second smallest element

			r = smallest+1;
			if(r==3)r=0;

			l = smallest-1;
			if(l==-1)l=2;

			if((*(structure[r])) == -1 || ((*(structure[l]))!= -1 && structure_array[r][(*(structure[r]))] > structure_array[l][(*(structure[l]))])){
				structure_array[r][++(*(structure[r]))] = structure_array[l][(*(structure[l]))--];

			}
			else{
				structure_array[l][++(*(structure[l]))] = structure_array[r][(*(structure[r]))--];
			}
			count++;
			print_array();
		}

	}
	printf("+----+----+----+\n");

	if(sum == count)printf("Optimal state :");
	else printf("Not optimal state : ");
	printf("%ld\n",count);
}
