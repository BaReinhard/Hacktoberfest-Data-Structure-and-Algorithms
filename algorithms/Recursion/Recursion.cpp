#include <iostream>
using namespace std; 


int result=1;
//Must use cout 
void fact(int N){
for(int i=1; i<=N; i++ )
{
result*=i; 
}
cout << “Factorial” << result << ‘\n’; 
}
//This must return an int
int factorial(int n){
//two blocks
//first block: answer in the simplest instance
// base case or anchor value
if(n==1){
return 1;
}
else{
//second block: formally established the repetition of underlying pattern
//”recursive step”
//it should be reducing the original instance to the base case
return factorial(N-1)*N; 
}
}


int main(){
	//figuring out the factorial 
int x;
cout << “GIve me a number. I’ll give you it’s factorial” << ‘\n’;
cin > x; 
return 1;
fact(x); 
cout <<”Recursion answer: “ << factorial(x) << ‘\n’; 

}
