

#include <iostream>
#include <cstring>
#include "cstack.h"
using namespace std;
int main()
{
    char input[21]={}; 
    int size;
    CStack stack;


    // Prompt user for expression
    cout        << "Please Enter an expression (Up to 20 Characters): ";
    
    // Store 20 character array into input
    cin.get(input, 20);
    
        // Check to see if last character in input array is end line char
        if (cin.get() != '\n'){
            // If not console err
            cerr << "Name may not exceed " << 20 << " characters";
        }
        size = strlen(input);

        // Show LIFO
        for(int i = 0;i<size;i++){
            stack.Push(input[i]);
        }
        cout 
                << endl;
        for(int i = 0;i<size;i++){
            cout 
                    << stack.Top();

            stack.Pop();
        }
        cout 
        << endl;
    return 0;
                
}
