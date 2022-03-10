// C++ program to find longest common prefix
// of given array of words.
#include<iostream>
#include<algorithm>
using namespace std;
string longestCommonPrefix(string ar[], int n)
{
	if (n == 0)
		return "";

	if (n == 1)
		return ar[0];
	sort(ar, ar + n);

	int en = min(ar[0].size(),
				ar[n - 1].size());

	string first = ar[0], last = ar[n - 1];
	int i = 0;
	while (i < en && first[i] == last[i])
		i++;

	string pre = first.substr(0, i);
	return pre;
}

// Driver Code
int main()
{
	string ar[] = {"geeksforgeeks", "geeks",
						"geek", "geezer"};
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << "The longest common prefix is: "
		<< longestCommonPrefix(ar, n);
	return 0;
}

// This code is contributed by Abhishek
