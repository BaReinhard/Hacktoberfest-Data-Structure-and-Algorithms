// Program to generate primes till 100001

#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int main() {
	vector<int> primes;
	bool *arr = new bool[100001];
	for(int i=0;i<100001;i++){
		arr[i] = false;
	}
	arr[0] = true;
	arr[1] = true;
	for(int i=2;i<MAX;i++){
		if(arr[i] == false){
			primes.push_back(i);
		}
		
		for(int j=2;i*j<MAX;j++){
		   arr[i*j] = true;	
		}
	}
	
	for(int i=0;i<primes.size();i++){
		cout<<primes[i]<<" ";
	}
	
	return 0;
}

