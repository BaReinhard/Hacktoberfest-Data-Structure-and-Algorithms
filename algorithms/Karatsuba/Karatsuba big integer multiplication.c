#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


#ifdef DEBUG
#define DBG(fmt, args...) printf("%s:%s:%d "fmt, __FILE__, __FUNCTION__, __LINE__, args)
#else
#define DBG(fmt, args...) 
#endif

int getn(int num)
{
    return (int) log10(num) + 1;
}

int addab(int a, int b)
{
    int sum = 0;

    DBG("a=%d ; b=%d \n", a, b);
    while(b--) 
            sum += a;
    DBG("sum=%d \n", sum);

    return sum;
}

void gethalfs(int num, int * first, int * last)
{
    int n, po;
    
    if (num == 0) return;

    n = getn(num);
    po = (int) pow(10, n/2);

    *first = num / po;
    *last  = num - *first * po;

    return;
}

int multiply(int x, int y)
{
    int a, b, c, d;
    int ac, bd, adbc;
    int n, res;

    a = b = c = d = 0;
    ac = adbc = bd = 0;

    DBG("x = %d : y = %d \n", x, y); 

    /* 
    Base case: if x or y is less than 10 
    then return x*y 
    */
    if (x<10 || y<10) return addab(x, y);

    gethalfs(x, &a, &b);
    DBG("a = %d : b = %d \n", a, b); 

    gethalfs(y, &c, &d);
    DBG("c = %d : d = %d \n", c, d); 

    /* 10^n ac + 10^n/2 (ad+bc) + bd */

    ac = multiply(a, c);
    bd = multiply(b, d);
    adbc = multiply(a+b, c+d) - (ac + bd);
    n = getn(x);

    res = (pow(10, n) * ac) + (pow(10, n/2) * adbc) + bd;
    DBG("result = %d \n", res);

    return res;
}

int main(void)
{
    int x = 1234;
    int y = 9876;

    if (getn(x) != getn(y)) {
            printf("Number of digits for x and y should be the same! \n");
            exit(1);
    }

    printf("%d * %d = %d \n", x, y, multiply(x, y));

    return 0;
}
