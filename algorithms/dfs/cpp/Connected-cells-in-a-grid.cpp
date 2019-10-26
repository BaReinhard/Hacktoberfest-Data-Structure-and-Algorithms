#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int dfs(vector<vector<int> > &v, int r,int c)
    {
    int count = 0;
    v[r][c] = 0;
    count++;
    for(int i = r-1; i <= r+1 ; i++)
        {
        for(int j = c - 1; j <= c+1; j++)
            {
            if(i >= 0 && i < v.size()  && j >= 0 && j < v[0].size() && v[i][j] == 1)
                {
                count += dfs(v ,i ,j );
            }
        }
    }
    return count;
}




int function(vector<vector<int> >&v,int row,int col)
    {
    int largest = 0;
    for(int i = 0 ; i < row; i++)
        {
        for(int j = 0 ; j < col ; j++)
            {
            if(v[i][j] )
                {
                int size = dfs(v,i,j);
                largest = max(largest, size);
            }
        }
    }
    return largest;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int r,c;
    cin >> r;
    cin >> c;
//    vector<int>a(c);
    vector< vector<int> > v(r,vector<int>(c));
    for(int i = 0 ; i < r ; i++)
        {
        for(int j = 0 ; j < c ; j++)
            {
            cin >> v[i][j];
        }
    }
   int result = function(v,r,c);
    cout<<result <<endl;
 /*    for(int i = 0 ; i < r ; i++)
        {
        for(int j = 0 ; j < c ; j++)   // to print the adjacency matrix
            {
            cout << v[i][j]<<" ";
        }
         cout<<endl;
    }
    */
    return 0;
}

