def addBitwise(x, y):

    while y != 0:
        carry = x & y
        x = x ^ y
        y = carry << 1
    return x

print "11 + 22 =", addBitwise(11, 22)
