#include<stdio.h>
#include<math.h>
int binarytodecimal(int n)
{
    int decimal=0, i=0, rem;
    while(n!=0)
    {
        rem=n%10;
        n/=10;
        decimal+=rem*pow(2,i);
        ++i;
    }
    return decimal;
}
int decimaltobinary (int n)
{
    int i=0, arr[32];
    while(n!=0)
    {
        arr[i]=n%2;
        n/=2;
        i++;
    }
    i--;
    for(;i>=0;i--)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int n, choose;
    char ch;
    Z: printf("Choose one of the following:\n 1. Binary to Decimal\n 2. Decimal to Binary\n\n");
    X: scanf("%d", &choose);
    if (choose==1)
    {printf("\nEnter a binary number: ");
    scanf("%d", &n);
    printf("%d = %d in decimal\n\n", n, binarytodecimal(n));}
    else if (choose==2)
    {
        printf("\nEnter a decimal number: ");
        scanf("%d", &n);
        printf("%d = ", n);
        decimaltobinary(n);
        printf(" in binary\n\n");
    }
    else {printf("\nNot a valid response.\nPlease enter a valid response: ");
        goto X;}
    printf("Want to continue?(Y/N):  ");
    fflush(stdin);
    scanf("%c", &ch);
    switch(ch)
    {
    case 'Y':
    case 'y':
        goto Z;
        break;
    case 'N':
    case 'n':
            break;
    default : printf("Not a valid response... Exiting\n\n");
    }
    return 0;
}
