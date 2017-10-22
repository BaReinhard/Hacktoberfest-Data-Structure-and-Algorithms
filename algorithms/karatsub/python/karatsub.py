def karatsub(x, y):
    if len(str(x)) == 1 or len(str(y)) == 1:
        return x * y
    else:
        mby2 = int(max(len(str(x)), len(str(y))) / 2)
        a = int(x / 10**mby2)
        b = x % 10**mby2
        c = int(y / 10**mby2)
        d = y % 10**mby2
        ac = karatsub(a, c)
        bd = karatsub(b, d)
        adplusbc = karatsub((a + b), (c + d)) - ac - bd
        return ac * 10**(2 * mby2) + adplusbc * 10**mby2 + bd


# print(karatsub(3141592653589793238462643383279502884197169399375105820974944592, 2718281828459045235360287471352662497757247093699959574966967627))

x = int(input("Enter first digit: \n"))
y = int(input("Enter second digit: \n"))

print(karatsub(x, y))
