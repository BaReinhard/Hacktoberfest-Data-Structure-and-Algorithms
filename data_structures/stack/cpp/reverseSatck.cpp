#include<iostream>
#include<stack>
using namespace std;


void insertAtButtom(stack<int> &st,int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }
    int topel= st.top();
    st.pop();
    insertAtButtom(st,elem);

    st.push(topel);

}

void reversestack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int elem=st.top();
    st.pop();
    reversestack(st);
    insertAtButtom(st,elem);
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reversestack(st);

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
        
    }cout<<endl;
    
    return 0;
}