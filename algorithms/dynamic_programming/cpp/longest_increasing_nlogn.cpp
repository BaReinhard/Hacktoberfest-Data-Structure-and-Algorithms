#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> a;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	a.push_back(v[0]);
	for(int i=1;i<v.size();i++)
	{
		int pos = upper_bound(a.begin(), a.end(), v[i]) - a.begin();
		if(pos == a.size())
			a.push_back(v[i]);
		else
			a[pos] = v[i];
	}
	cout<<a.size()<<"\n";
}
