def collatz (n):
  if (n < 1):
    print('Enter a positive integer!')
    return None
  else:
    while (n != 1):
      if (not n % 2):
        n /= 2
      else:
        n = 3 * n + 1
      print(int(n))
  print(int(n))
