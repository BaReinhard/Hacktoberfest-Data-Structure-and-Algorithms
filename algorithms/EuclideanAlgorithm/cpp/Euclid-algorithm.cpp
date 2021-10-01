#include <bits/stdc++.h>
using namespace std;
 

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main(){
	int hcf, a, b;
	cout<<"Enter 2 Numbers";
    cin>>a>>b;
	hcf = gcd(a, b);
	cout<<"Hcf of 2 numbers is "<<hcf<<endl;
    return 0;
}