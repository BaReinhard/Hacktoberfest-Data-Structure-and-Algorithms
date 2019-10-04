#include <iostream>
#include <cstring>
#include "stack.cpp"
using namespace std;

void convert(string exp){
  stack s;
  string out;

  for(int i =0; i<exp.length(); i++){
    if(exp[i]=='+' || exp[i]=='-'){
      if(s.topel()=='*' || s.topel()=='/' || s.topel()=='#'){
        while(!s.isEmpty()){
          out+=s.pop();
        }
      }
      s.push(exp[i]);
    }
    else if(exp[i]=='*' || exp[i]=='/'){
      if(s.topel()=='#'){
        while(!s.isEmpty()){
          out+=s.pop();
        }
      }
      s.push(exp[i]);
    }
    else if(exp[i]=='#' || exp[i]=='('){
      s.push(exp[i]);
    }
    else if(exp[i]==')'){
      while(s.topel()!='('){
        out+=s.pop();
      }
      s.pop();
      while(!s.isEmpty()){
        if(s.topel()=='('){
          break;
        }
        else{
          out+=s.pop();
        }
      }
    }
    else{
      out+=exp[i];
    }
  }
  while(!s.isEmpty()){
    out+=s.pop();
  }
  cout<<out;
}

int main(){
  string exp;
  cin>>exp;
  convert(exp);
  return 0;
}
