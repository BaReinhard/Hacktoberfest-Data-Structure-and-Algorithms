#include <iostream>
#include "cstack.h"

using namespace std;

int main()
{
    char input; 
    CStack stack;

    // Prompt user for expression
    cout << "Please Enter an expression (must end with the EOF character) : ";      //EOF is CTRL^D (Linux) or CTRL^Z (Windows)
    
    // Fill stack with char values
    while(cin >> input) {
        stack.Push(input);
    }

    // Show LIFO
    cout << endl;
    while(!stack.IsEmpty()){
        cout << stack.Top();
        stack.Pop();
    }
    cout << endl;
    return 0;
}
