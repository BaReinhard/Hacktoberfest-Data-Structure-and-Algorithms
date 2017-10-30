//
// Created by Jonatan Witoszek on 21.10.2017.
//

#include <iostream>

int euclidean(int num1, int num2) {
    int a = num1;
    int b = num2;

    if (a && b == 0) {
        return 0; // returns 0 when both values are 0 too
    }

    int rem = 0;

    while(b!=0) {
        rem = b;
        b = a % b;
        a = rem;
    }

    return rem;

}

int main() {
    std::cout << "Specify two numbers to calculate greatest common divisor: ";

    int a, b;
    std::cin >> a >> b;

    std::cout << "gcd(" << a << ", " << b << ") = " << euclidean(a,b);

    std::cin.get();
    std::cin.get();
    return 0;
}
