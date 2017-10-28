//C program to find GCD of two numbers

#include <stdio.h>

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0 || b == 0)
       return 0;

    // base case
    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);

    return gcd(a, b-a);
}

int main()
{
    int a=102, b=7;

    printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
    return 0;
}
