#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
bool st (const pair<int,int> &a,const pair<int,int> &b){
       if(a.first!=b.first)
        return(a.first<b.first);
        else
            return(a.second>b.second);
}


int main()
{
    // declaring vector of pairs
    vector< pair <int, int> > vect;

    // Initialising 1st and 2nd element of pairs
    // with array values
    int arr[] = {10, 80,80,70, 5, 40,70,80 ,70,70,70};
    int arr1[] = {30, 60,37,47, 20, 50,70,90,19,56,28};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Entering values in vector of pairs
    for (int i=0; i<n; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );

    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;

    }

    // Using sort() function to sort by 2nd element
    // of pair
    sort(vect.begin(), vect.end(),st);



    // Printing the sorted vector(after using sort())
    cout << "The vector after sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
    pair<int,int>k = {4,20}, p = vect[0];
   cout<<"new"<<p.first<<p.second;
   if(p==k)
    cout<<"hey";
    return 0;
}
 cout << "The vector after sort operation is:\n" ;
       for (int i=0; i<row.size(); i++)
    {
        cout << col[i].first << " "
             << col[i].second << endl;
    }
    cout << "The vector after sort operation is:\n" ;
       for (int i=0; i<row.size(); i++)
    {
        cout << row[i].first << " "
             << row[i].second << endl;
    }
