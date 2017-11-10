#include<bits/stdc++.h>

using namespace std;

int main()
{
    int j, shift;
    string s, cipher;
    srand(time(NULL)); // Generates a random number with the current time as seed.
    cout<<"Input string: ";
    cin>>s;
    cout<<"Shift (enter 0 for random shift): ";
    cin>>shift;
    while (shift == 0) // Generate a random shift until shift > 0.
        shift = rand() % 26;
    for (int i=0; s[i]; i++)
    {
        j = int(s[i]);
        if (isupper(s[i]))
            cipher += char(((j + shift - 65) % 26) + 65);
        else
            cipher += char(((j + shift - 97) % 26) + 97);
    }
    cout<<"Cipher: "<<cipher<<endl;
    return 0;
}
