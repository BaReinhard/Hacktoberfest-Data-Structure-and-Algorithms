// Problem Statement: https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space/0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Enter number of test cases
	int T=0;
	cin>>T;

  // Enter the size of 2d array and then its elements.
	for(int cases=0; cases<T; cases++){
	    int N=0;
	    cin>>N;

	    int mat[N][N];

	    for(int j=0; j<N; j++){
	        for(int k=0; k<N; k++){
	            int temp = 0;
	            cin>>temp;
	            mat[j][k] = temp;
	        }
	    }


	    for(int i=0; i<N; i++){
	        for(int j=i; j<N; j++){
	            swap(mat[i][j], mat[j][i]);
	        }
	    }

	    for(int i=0; i<N; i++){
	        for(int j=0, k=N-1; j<k; j++, k--){
	            swap(mat[i][j], mat[i][k]);
	        }
	    }


	    for (int i=0; i<N; i++){ 
	        for (int j=0; j<N; j++){
	            cout<<mat[i][j]<<" ";
	        }
	    }
	    cout<<endl;

	}
	return 0;
}
