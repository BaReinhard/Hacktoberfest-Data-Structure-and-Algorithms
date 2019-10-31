vector<vi> multiply(vector<vi>& A, vector<vi>& B) {
  int n = A.size(), m = A[0].size(), k = B[0].size();
  vector<vi> C(n, vi(k, 0));
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++)
      for(int l = 0; l < m; l++)
        C[i][j] += A[i][l] * B[l][j];

  return C;
}

vector<vi> power(vector<vi>& A, int k) {
  int n = A.size();
  vector<vi> resp(n, vi(n)), B = A;

  for(int i = 0; i < n; i++) resp[i][i]=1;

  while(k) {
    if(k & 1) resp = multiply(resp, B);
    B = multiply(B, B); k >>= 1; 
  }
  return resp;
}

vector<vi> resp = power(A, k);
