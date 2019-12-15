#include<iostream>
#include<algorithm>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//#include<heap>
#include<vector>


using namespace std;

vector <int> v1;

void init_vals(){
    int n;
    int x;
    cout<<"Enter the number element for the insertion in the heap"<<endl;
    cin>>n;
    for(int i = 0; i<n;++i){
        v1.push_back(x);
    }
}
inline void make_heap(){
    make_heap(v1.begin(),v1.end());
}

inline void sortheap(){
    sort_heap(v1.begin(),v1.end());
}

inline void popheap(){
    pop_heap(v1.begin(),v1.end(),v1.pop_back())
}



int main(){
    auto static i;

    cout<<"Below are the elements that are present in the heap"
    cout<<"The resultance heap is displayed below"<<endl;
    for (i = 0;<v1.size(),++i){
        cout<<v1[i]<<endl;
    }
}