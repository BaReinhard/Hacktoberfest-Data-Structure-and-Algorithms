#include<iostream>
#include<algorithm>
using namespace std;
int main(){

    int a[50], n,i,j;
    cout<<"Enter the length of array: ";
    cin>>n;
    cout<<"Enter the values:\n";

    for(i=0; i<n; i++) cin>> a[i];

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(a[i] > a[j]) swap(a[i],a[j]);
        }
    }

     cout<<"Sorted Array\n";
     for(i=0; i<n; i++)
           cout<< a[i]<<" ";
}