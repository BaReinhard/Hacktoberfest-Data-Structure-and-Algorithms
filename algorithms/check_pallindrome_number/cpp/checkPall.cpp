#include <iostream>
#include <cstring>
#include <string>
using namespace std;
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
	cin >> str;
	if(checkPall(str))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
