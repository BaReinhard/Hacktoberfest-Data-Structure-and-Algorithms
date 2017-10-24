//CPP Implementation of Knuth-Morris-Pratt(KMP) algorithm for pattern matching in a given text string.

#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

char text[MAX],pattern[MAX];
int prefix_array[MAX],m,n;

void Compute_Prefix_Array();
int Kmp_Search();

int main(void)
{
    int find_pattern;
	cout<<"Specify Input Text: ";
	cin>>text;
	cout<<"Specify Input Pattern: ";
	cin>>pattern;
	m=strlen(text);
	n=strlen(pattern);
	find_pattern=Kmp_Search();
	if(find_pattern>=0)
	{
		cout<<"\nMatching Pattern FOUND at position "<<find_pattern<<" in the input Text."<<endl;
	}
	else
	{
	    cout<<"\nMatching Pattern NOT found in the input Text!"<<endl;
	}
	return 0;
}

int Kmp_Search()
{
	int i;
	Compute_Prefix_Array();
	int k=-1;
	for(i=0;i<m;i++)
	{
		while(k>-1 && pattern[k+1]!=text[i])
		{
		    k=prefix_array[k];
		}
		if(text[i] == pattern[k+1])
		{
		    k++;
		}
		if(k==n-1)
		{
			return i-k+1;
		}
	}
	return -1;
}

void Compute_Prefix_Array()
{
	int k=-1;
	int i=1;
	prefix_array[0]=k;
	for(i=1;i<n;i++)
	{
		while(k>-1&&pattern[k+1]!=pattern[i])
		{
		    k=prefix_array[k];
		}
		if(pattern[i]==pattern[k+1])
		{
            k++;
		}
		prefix_array[i]=k;
	}
}

/*
SAMPLE OUTPUT:
Specify Input Text: ababdabacdababcabab
Specify Input Pattern: ababcabab

Matching Pattern FOUND at position 11 in the input Text.
*/
