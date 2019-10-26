#include <iostream>
using namespace std;
int matrixChain(int n, int dim[])
{
    int i, j, k;
    int temp;
    int M[n+1][n+1];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j || i<j)
                M[i][j]=0;
        }
    }
    for(int s=2; s<=n; s++)
    {
        for(i=1; i<=(n-s+1); i++)
        {
            j = i+s-1;
            M[i][j] = 9999;
            for(k=i; k<j; k++)
            {
                temp = M[i][k] + M[k+1][j] + dim[i-1] * dim[k] * dim[j];
                if(temp < M[i][j])
                {
                    M[i][j] = temp;
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        for(int k=1; k<i; k++)
            cout<<'\t';
        for(j=i; j<=n; j++)
        {
            cout << M[i][j] << '\t';
        }
        cout << "\n";
    }
    return M[1][n];
}
int main()
{
    int i,j;
    int n;
    cout << "Enter the number of matrices in the chain (greater than 1): ";
    cin >> n;
    int * dim = new int[n+1];
    cout << "Enter the dimension of array in order: \n";
    for(i=0; i<=n; i++)
    {
        cin >> dim[i];
    }
    int ans = matrixChain(n, dim);
    cout << "The minimum number of multiplication operations required to multiply the matrix chain is " << ans;
    return 0;
}
