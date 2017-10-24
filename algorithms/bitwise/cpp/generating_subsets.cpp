#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(void)
{
    vector<int> v = {1,2,3};
    int numSubsets = 1 << v.size();
    for(int i = 0; i < numSubsets; ++i)
    {
        int pos = v.size() - 1;
        int subsetMask = i;
        cout << "{ ";
        while(subsetMask > 0)
        {
            if(subsetMask & 1)
                cout << v[pos] << " ";
            subsetMask >>= 1;
            pos--;
        }
        cout << "}\n";
    }
    return 0;
}
