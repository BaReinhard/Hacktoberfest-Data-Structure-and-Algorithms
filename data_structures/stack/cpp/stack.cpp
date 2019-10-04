#include <iostream>
using namespace std;

class stack{
  public:
    char arr[10];
    int top;

    stack(){
      top = -1;
    }

    void push(char x){
      if(top<10){
        top+=1;
        arr[top] = x;
      }
      else{
        cout<<"Stack is full\n";
      }
    }

    char pop(){
      if(isEmpty()){
        cout<<"Stack is Empty\n";
      }
      char a = arr[top];
      top-=1;
      return a;
    }

    char topel(){
      return arr[top];
    }

    bool isEmpty(){
      if(top==-1){
        return true;
      }
      return false;
    }

    void print(){
      for(int i=0; i<=top; i++){
        cout<<arr[i]<<" ";
      }
      cout<<"\n";
    }
};
