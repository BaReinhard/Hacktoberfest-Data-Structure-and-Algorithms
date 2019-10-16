#include <stdio.h>
#include <stdlib.h>

int checkPall(char str[])
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] != str[strlen(str)-i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	char str[10000];
	gets(str);
	if(checkPall(str))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}
