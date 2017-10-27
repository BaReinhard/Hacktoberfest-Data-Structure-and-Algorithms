#include<bits/stdc++.h>
using namespace std;

bool isPoss(vector<int> pages,int current_min,int number,int stu){

    int s=1;
    int current=0;

    for (int i = 0; i < pages.size() ; ++i) {

        if(pages[i]>current_min){
            return false;
        }

        if (pages[i]+current <= current_min){
            current+=(pages[i]);
        }
        else{
            s++;
            if(s>stu){
                return false;
            }
            current=pages[i];
        }
    }


    return true;

}

void AssignPages(vector<int> pages,int numberOfBooks,int students){

    int s=0;
    int sum=0;
    int ans;
    for (int i = 0; i < pages.size() ; ++i) {
        sum+=pages[i];
    }
    int e=sum;
    while(s<=e){
        int mid=(s+e)>>1;
        if (isPoss(pages,mid,numberOfBooks,students)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    cout<<ans<<endl;

}

//Main function
int main(){

    vector<int> pages;
    int numberOfBooks;
    int students;
    cin>>numberOfBooks>>students;
    for (int i = 0; i < numberOfBooks ; ++i) {
        int a;
        cin>>a;
        pages.push_back(a);
    }

    AssignPages(pages,numberOfBooks,students);

}