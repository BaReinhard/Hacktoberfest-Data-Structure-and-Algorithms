#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];

    //kadane's algorithm
    int sum = 0,max_sum = INT_MIN,start,end,s;
    for(int i=0;i<A.size();i++){
        sum += A[i];
        if(sum>max_sum){
            max_sum = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }

    cout<<max_sum<<endl;

    return 0;

}
