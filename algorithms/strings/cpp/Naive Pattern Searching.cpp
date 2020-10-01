/*
Time Complexity: Best Case: O(n)
                 Worst Case: O(n*m)

*/


#include <bits/stdc++.h>
using namespace std;

void pattern_search(string str, string pat)
{

    int string_len = str.length();
    int pattern_len = pat.length();
    int i,j;

    for (i = 0; i <= string_len - pattern_len; i++)
    {
        for (j = 0; j < pattern_len; j++)
            if (str[i + j] != pat[j])
                break;

        if (j == pattern_len)
            cout << "Pattern found at index "<< i << '\n';
    }
}

int main()
{

    string str = "AABAACAAABBBABABAADAABAAABAA";
    string pat = "AAB";

    pattern_search(str,pat);
    return 0;
}
