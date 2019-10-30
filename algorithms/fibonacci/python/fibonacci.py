# Return the nth fibonaci number using fast doubling. O(logn n) complexity
def fibonaci(n):
  if n == 0:
    return 0, 1
  else:
    a, b = fibonaci(n // 2)
    c = a * (b * 2 - a)
    d = a * a + b * b
    if n % 2 == 0:
      return c, d
    return d, c + d

# Fibonaci sequence is 1,1,2,3,5,8,13,21,34,55,...
print("1st Fibonaci Element: {}".format(fibonaci(1)[0]))
print("2nd Fibonaci Element: {}".format(fibonaci(2)[0]))
print("3rd Fibonaci Element: {}".format(fibonaci(3)[0]))
print("4th Fibonaci Element: {}".format(fibonaci(4)[0]))
print("5th Fibonaci Element: {}".format(fibonaci(5)[0]))
print("6th Fibonaci Element: {}".format(fibonaci(6)[0]))
print("7th Fibonaci Element: {}".format(fibonaci(7)[0]))
print("8th Fibonaci Element: {}".format(fibonaci(8)[0]))
print("9th Fibonaci Element: {}".format(fibonaci(9)[0]))
print("10th Fibonaci Element: {}".format(fibonaci(10)[0]))
