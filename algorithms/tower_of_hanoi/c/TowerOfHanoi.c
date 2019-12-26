/*Tower Of Hanoi is a game where n is number of inputs 
& source , destination , via are 3 pegs
this program will give you steps to solve game*/

/*The complexity of this algorithm is exponential i.e. O(2^n)*/

#include<stdio.h>
//move function
int move(int n, char source, char destination, char via)
{
/*NOTE: if there are 3 disk then 
the steps require  will be 2^n-1 
i.e. 2^3-1=7 so 7 
steps will be required*/
	if(n==0)
	{
	   printf("Please Enter The Number Of Rings\n");
	   return 0;
	}	
	else if(n==1)
	{
	   printf("move %c to %c\n", source , destination);
	}
	else
	{
	  move(n-1, source, via, destination);
	  move(1, source, destination, via);
	  move(n-1, via, destination, source);	
	}
}//move function ends here
int main()
{
	int n;
	char s,d,v;
	//inputs
	printf("Enter The Number Of Rings\n");
	scanf("%d",&n);
	//function calling	
	move(n,'s','d','v');
	return 0;
}//main function ends here
