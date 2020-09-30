
// CPP code to generate first 'n' terms 
// of the Moser-de Bruijn Sequence 
#include <bits/stdc++.h> 
using namespace std; 

// Function to generate nth term 
// of Moser-de Bruijn Sequence 
int gen(int n) 
{ 
	// S(0) = 0 
	if (n == 0) 
		return 0; 
	
	// S(1) = 1 
	else if (n == 1) 
		return 1; 
	
	// S(2 * n) = 4 * S(n) 
	else if (n % 2 == 0) 
		return 4 * gen(n / 2); 
	
	// S(2 * n + 1) = 4 * S(n) + 1 
	else if (n % 2 == 1) 
		return 4 * gen(n / 2) + 1; 
} 

// Generating the first 'n' terms 
// of Moser-de Bruijn Sequence 
void moserDeBruijn(int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << gen(i) << " "; 
	cout << "\n"; 
} 

// Driver Code 
int main() 
{ 
	int n = 15; 
	cout << "First " << n << " terms of "
		<< "Moser-de Bruijn Sequence : \n"; 
	moserDeBruijn(n); 
	return 0; 
} 
