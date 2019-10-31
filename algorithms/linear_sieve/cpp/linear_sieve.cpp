#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

vector <int> primes,divisores(MAX), power(MAX);
bitset<MAX> is_prime;

void crivo(){
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    divisores[1] = 1;

    for(int i = 2; i < MAX; i++){
        if(is_prime[i]){
            primes.push_back(i);
            power[i] = 1;
            divisores[i] = 2;
        }

        for(int  j = 0; j < primes.size() && i*primes[j] < MAX; j++){
            is_prime[i*primes[j]] = 0;
            if(i%primes[j] == 0){
                power[i*primes[j]] = power[i] + 1;
                divisores[i*primes[j]] = divisores[i]/(power[i]+1) *(power[i*primes[j]]+1);
                break;
            }
            else{
                power[i*primes[j]] = 1;
                divisores[i*primes[j]] = divisores[i]*2;
            }
        }
    }
}

int main(){
    crivo();
    int n;

    cin >> n;
    printf("%d\n", divisores[n]);
    return 0;
}
