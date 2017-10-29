#include<iostream>
#include<stdio.h>
using namespace std;
 int main()
 {  int n=1;
 	do
 {
 	int n,m;
 	cin>>n;
 	if(n!=0)
 {	cin>>m;		
 	int A[n][m];
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<m;j++)
 			cin>>A[i][j];
 	}	
 	int i=n-1,j=m-1;int cost=A[n-1][m-1];
 	while(i!=0 || j!=0){
 		if(i==0){j=j-1;
 			cost+=A[i][j];
 		}
 		else if(j==0)
 			{i=i-1;
 			cost+=A[i][j];
 		}
 		else if(A[i][j-1]<A[i-1][j])
 	    {
 			j=j-1;
 			cost+=A[i][j];
 		}
 		else
 		{
 			i=i-1;
 			cost+=A[i][j];
 		}

 	}
 	cout<<"\n"<<cost;
 }
}while(n!=0);
 	return 0;
 }
 
