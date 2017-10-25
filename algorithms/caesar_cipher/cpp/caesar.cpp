#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    string Input;
    int Key;
    char Operation;

    cout << "Please enter the message (Latin Alphabet): ";
    getline(cin, Input);

    cout << "Please enter the shift number: ";
    cin >> Key;
    Key %= 26;

    InputOperation:
    cout << "(E)ncode or (D)ecode? ";
    cin >> Operation;

    bool way;
    if (Operation == 'E' || Operation == 'e')
        way = true;
    else if (Operation == 'D' || Operation == 'd')
        way = false;
    else goto InputOperation;

    string Result;
    for (int i = 0; i < Input.length(); i++) {
        char C = Input[i];
        int LetterType = 0;

        if (C >= 'A' && C <= 'Z')
            LetterType = 1;
        if (C >= 'a' && C <= 'z')
            LetterType = 2;

        if (LetterType == 0) {
            Result.push_back(C);
            continue;
        }

        if (way) {
            if (LetterType == 1)
                C = (C+Key-'A')%26 + 'A';
            else
                C = (C+Key-'a')%26 + 'a';
        } else {
            if (LetterType == 1)
                C=(C-Key+'A')%26 + 'A';
            else {
                int x = C - Key - 'a';
                if (x < 0)
                    x += 26;
                C = x + 'a';
            }
        }
        Result.push_back(C);
    }

    cout << Result;
}
