#include <bits/stdc++.h>
#define MAX 1007

using namespace std;

int k[MAX][MAX];
int n;  // quantidade de valores disponiveis
int W; // tamanho da mochila
int v[MAX]; // valor
int wt[MAX];// peso

int knap() {
   for(int i = 1; i <= n; i++) { 
       for(int w = 1; w <= W; w++) {
           if (wt[i-1] <= w) {
                 k[i][w] = max(v[i-1] + k[i-1][w-wt[i-1]],  k[i-1][w]); 
           }else k[i][w] = k[i-1][w]; 
       } 
   }
    return k[n][W];
}

int main(){
    return 0;
}
