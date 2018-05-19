#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll result;

ll fast_expo(ll i, ll j, ll q){
    if (j==1) return i; 
    ll x = fast_expo(i, j/2, q);
    
    if (j%2==0) result = x * x;
    else result = (x * x) * i;
    
    return result%q;
}


int main(){

    ll a, b, c, n;
           
    while (scanf("%lld",&n) == 1){
        if (n == 0) break;
          
        while (n--){
            scanf("%lld%lld%lld",&a,&b,&c);                
            printf("%lld\n",fast_expo(a,b,c));
        
        }
    }
        
    return 0;
}