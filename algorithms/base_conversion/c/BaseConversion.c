#include <stdio.h>
#include <stdlib.h>
#define LEN 20

void convert(int num, int base);

int main()
{
    int num, base;
    printf("Enter a decimal integer : ");
    scanf("%d", &num);
    printf("Enter a base to convert to (>1) : ");
    scanf("%d", &base);

    printf("%d in base %d is ", num, base);
    convert(num, base);

    return 0;
}

void convert(int num, int base) {
    const char digits[] = "0123456789ABCDEF";
    char res[LEN], *result;
    int digit, index = LEN - 1;
    // Tackle negative numbers first
    if (num < 0) {
        num = -num;
        putchar('-');
    }
    if (num == 0) {
        puts("0\n");
        return;
    }
    res[index] = '\0';
    while (num > 0) {
        digit =  num % base;
        res[--index] = digits[digit];
        num /= base;
    }
    // Extract that portion of the string which is necessary.
    result = res;
    result += index;
    printf("%s\n", result);
}
