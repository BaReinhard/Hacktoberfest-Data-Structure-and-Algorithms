#!/usr/bin/python3

from functools import reduce

# returns x where (a * x) % b == 1
# using Extended Euclidean algorithm
def mul_inv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1: return 1
    while a > 1:
        q = a // b
        a, b = b, a%b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0: x1 += b0
    return x1#!/usr/bin/perl 

def chinese_remainder(n, a):
    sum = 0
    prod = reduce(lambda a, b: a*b, n)
    for n_i, a_i in zip(n, a):
        p = prod // n_i
        sum += a_i * mul_inv(p, n_i) * p
    return sum % prod
 
if __name__ == '__main__':
    n = [1, 3, 5]
    a = [5, 7, 3]
    print(chinese_remainder(n, a)) # prints 13
