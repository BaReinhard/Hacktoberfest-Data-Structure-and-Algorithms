vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    // DO STUFF HERE AND POPULATE result
    
    int t,b,l,r,dir,i ;
    t = 0;
    b = A.size() - 1;
    l = 0;
    dir = 0 ;
    r = A[0].size() - 1;
    while ( t<=b && l<=r)
    {
        if (dir == 0)
        {
            for (i=l;i<=r;i++)
                result.push_back(A[t][i]) ;
            t++;
        }
        else if (dir == 1)
        {
            for (i=t;i<=b;i++)
                result.push_back(A[i][r]) ;
            r--;
        }
        else if (dir == 2)
        {
            for (i=r;i>=l;i--)
                result.push_back(A[b][i]) ;
            b--;
        }
        else if (dir == 3)
        {
            for (i=b;i>=t;i--)
                result.push_back(A[i][l]) ;
            l++;
        }
        dir = ( dir + 1 )%4 ;
    }
    
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
