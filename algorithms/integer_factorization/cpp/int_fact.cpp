//This algorithm do the factorization from a number in O(sqrt(Number) * log(Number))
#include <bits/stdc++.h>

using namespace std;

int main(){
	vector< long long > fact;

	long long number;

	cin >> number;//Read the number

	long long tmp = number;

	if(number == 1LL){
		fact.push_back(number);
	}

	for(long long i = 2LL ; i * i <= number ; i++){
		while(number % i == 0LL){
			fact.push_back(i);
			number /= i;
		}
	}

	if(number > 1){
		fact.push_back(number);
	}

	cout << tmp << " = ";

	for(int i = 0 ; i < fact.size() ; i++){
		cout << fact[i];

		if(i == int(fact.size()) - 1){
			cout << "\n";
		}else{
			cout << '*';
		}
	}

	return 0;
}