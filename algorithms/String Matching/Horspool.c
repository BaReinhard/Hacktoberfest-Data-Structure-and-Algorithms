#include <stdio.h>
#include <string.h>

int comparisons = 0;

void bad_shift_table(int c[],char b[])
{
	int n = strlen(b);
	int i;

	for(i=0;i<256;i++)
	{
		c[i] = n;
	}

	for(i=0;i<n-1;i++)
	{
		c[(int)b[i]] = n - i - 1;
	}

}

void horspool_matching(char a[],char b[],int c[])
{
	int m = strlen(a);
	int n = strlen(b);
	int i = n-1;
	while(i <= m)
	{
		int j = n-1;
		int k = i;
		int count = 0;
		while(j >= 0)
		{
			comparisons++;
			if(a[k] == b[j]){
				j--;
				k--;
				count++;
			}else{
				break;
			}
		}
		if(count == n){
			printf("Substring found at %d\n",(k+1 ));
			printf("Comparisons = %d",comparisons);
			return;
		}
		i += c[(int)a[i]];
	}
	printf("Substring Not found\n");
	printf("Comparisons = %d",comparisons);
}

void main()
{
	char a[100],b[100];
	printf("Enter the String:");
	gets(a);
	printf("Enter the substring to search:");
	gets(b);
	int c[256];
	bad_shift_table(c,b);
	horspool_matching(a,b,c);
}
