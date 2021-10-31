#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a.compare(b)==0)
        return true;
    return false;
}

vector<int> findAnagrams(string arr[], int n)
{
    vector<int> v;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(isAnagram(arr[i], arr[j]))
            {
                v.push_back(i+1);
                v.push_back(j+1);
                cout<<arr[i]<<"-->"<<arr[j]<<endl;
            }
        }
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return v;
}

int main(int argc, char const *argv[])
{
    string arr[] = {"cat","dog","god","tca"};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ress = findAnagrams(arr, n);
    for(int i=0;i<ress.size()-1;i+=2)
    {
        cout<<"["<<ress[i]<<" "<<ress[i+1]<<"] ";
    }
    cout<<endl;
    return 0;
}
