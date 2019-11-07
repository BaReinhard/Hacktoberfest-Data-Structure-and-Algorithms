#include <bits/stdc++.h>
#define MAX 500

using namespace std;

int d[MAX][MAX];
void floyd_warshall(){
  for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
          }
      }
  }
}

int main(){
  return 0;
}
