#include <stdio.h>
//Initialize variables used in programs.
int a, b, c, amount = 0;
//Main function
int main() {
b = 1;
printf("Enter number of steps: ");
scanf("%d", &amount);
//ARRAYS START AT 0 ALWAYS !!!
for (int i = 0; i < amount; i++) {
c = a + b;
b = a;
a = c;
//Print resoults
printf("%d\n", c);
};
return 0;
}


