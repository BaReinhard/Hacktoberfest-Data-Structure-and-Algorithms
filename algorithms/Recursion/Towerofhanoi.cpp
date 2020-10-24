#include <iostream>
using namespace std; 
void hanoi(int N, char S, char I, char D){
//base case 
	static int count =0;  /* Popular interview questions: 
How do you create a variable that stays alive throughout a function answer create a static variable: its shared throughout copies of the function 
What’s the difference between a variable and static variable
*/ 
if(n==1)
{
cout << ++count << “Move disc” << N << “from “ << S << “ ---- “ << D << ‘\n’;
}
else
{
nanoi(N-1,S,D,I);
cout << ++count << “Move disc” << N << “from “ << S << “ ---- “ << D << ‘\n’;
nanoi(N-1,I,S,D); 
}
}
//global anyone can change it without realising it. Not safe. 
int main(){
Int N; 
char S=’S’m D=’D’, I=’I’;
cout << “Enter a number of discs” << ‘\n’;
cin > N;
hanoi(N,S,I,D); 
return 1; 
}
