def is_power_of_two(n):
  return (n != 0) and not (n & (n - 1))
  