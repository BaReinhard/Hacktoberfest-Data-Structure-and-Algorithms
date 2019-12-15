#include <iostream>
#include <conio.h>
#include <algorithm>
#include <stack>


using namespace std;
stack <int> s1; // global var for the stack


int main(){
    int key;
    int x;
    while(1){
        cout<<"1 -> push in the stack"<<endl;
        cout<<"2 --> pop from the stack"<<endl;
        cout<<"3 --> display the stack"<<endl;
        cin>>key;
        switch (key){
        case 1:/* constant-expression */
            /* code */
            cout<<"Enter the element for the insertion in the stack"<<endl;
            cin>> x;
            s1.push(x);
            break;
        case 2:/* constant-expression */
            /* code */
            s1.pop();
            break;
        case 3:/* constant-expression */
            /* code */
            while(s1.empty() != NULL){
                cout<<s1.top()<<endl;
            }
            break;
        default:
            exit(1);
            break;
        }
    }
getch();
return 0;
}