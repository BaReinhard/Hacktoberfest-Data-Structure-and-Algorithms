#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> V;
    V.push_back(3);
    V.push_back(4);
    V.push_back(5);
    V.push_back(6);
    V.push_back(7);

    vector <int> :: iterator it;

    for(it = V.begin(); it != V.end(); it++)
         cout<<*it<<" ";
          
    cout<<"\n";
    int ct = 0;
    for(it = V.begin(); it != V.end(); it++)
    {
        ct ++;
        if(*it == 5)
            V.erase(V.begin()+ct-1);
    }

    for(it = V.begin(); it != V.end(); it++)
        cout<<*it<<" ";

    cout<<"\n";

    V.erase(V.begin());
    for(it = V.begin(); it != V.end(); it++)
        cout<<*it<<" ";
    return 0;
}
