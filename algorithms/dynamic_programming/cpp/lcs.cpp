//Tabularization
#include<iostream>
#include<string.h>
using namespace std;

void lcs(char a[],char b[],int table1[100][100],int table2[100][100])
{
	int i,j;
	int n = strlen(a),m=strlen(b);
	for(i=0;i<=n;i++)
		table1[i][0] = 0;
	for(i=0;i<=m;i++)
		table1[0][i] = 0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
			{
				table1[i][j] = table1[i-1][j-1]+1;
				table2[i][j] = 1;						//diagonally
			}
			else if(table1[i-1][j]>table1[i][j-1])
			{
				table1[i][j] = table1[i-1][j];
				table2[i][j] = 2;						//up
			}
			else
			{
				table1[i][j] = table1[i][j-1];			//right
				table2[i][j] = 3;	
			}

		}
	}
}

int main()
{
	char a[100],b[100];
	cin>>a>>b;
	int table1[100][100],table2[100][100];
	lcs(a,b,table1,table2);
	int i,j;
	int n = strlen(a),m=strlen(b);

	cout<<"Ans is : "<<table1[n][m]<<" and string:";
	char string[100];
	int x = table1[n][m];
	string[x] = '\0';
	i=n,j=m;
	while(i>0&&j>0)
	{
		if(table2[i][j]==1)
			{
				string[--x] = a[i-1];
				i--;
				j--;
			}
		else if(table2[i][j]==2)
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	cout<<string;
	return 0;

}