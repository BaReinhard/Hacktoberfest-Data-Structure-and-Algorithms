#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  It finds all prime numbers between one and N.
		
  Steps:

	1- Take all numbers into an array one to N. (We know one is not a prime number)
	2- Remove multiples of every number within one to n square from the array 
	3- Rest will be prime numbers
*/

int main()
{

	int N, *list, N_SQRT;

	printf("Please enter the N: ");
	scanf("%d", &N);

	list = (int *) malloc(sizeof(int) * (N+1));

	for(register int i=1; i<=N; i++)
		list[i] = i;


	N_SQRT = sqrt(N);

	for(register int i=1; i <= N_SQRT; i++)
	{

		if( *(list + i) != 1 )
		{
			for (register int j = i * i; j<= N; j += i)
			{
				*(list + j) = 0;
			}
			
		} else
		{
			*(list + i) = 0;
		}
	}



	for(register int i=1; i <= N; i++)
	{
		if(*(list + i))
		{
			printf("%d\n", *(list + i) );
		}
	}

}