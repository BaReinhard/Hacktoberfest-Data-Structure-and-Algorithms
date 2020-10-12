
#include <bits/stdc++.h> 
using namespace std; 

int gen(int n) 
{ 

	if (n == 0) 
		return 0; 

	else if (n == 1) 
		return 1; 
	
 
	else if (n % 2 == 0) 
		return 4 * gen(n / 2); 
 
	else if (n % 2 == 1) 
		return 4 * gen(n / 2) + 1; 
} 

void moserDeBruijn(int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << gen(i) << " "; 
	cout << "\n"; 
} 


int main() 
{ 
	int n;
  cin>>n;
	cout << "First " << n << " terms of "
		<< "Moser-de Bruijn Sequence : \n"; 
	moserDeBruijn(n); 
	return 0; 
} 
