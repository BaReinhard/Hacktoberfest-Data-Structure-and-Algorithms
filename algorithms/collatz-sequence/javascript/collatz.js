let collatz = (n) => {
  if (n < 1) {
    console.log('Enter a positive prime number!')
    return null
  }
  while (n != 1) {
    if (!(n % 2)) {
      n /= 2
    } else {
      n = 3 * n + 1
    }
    console.log(n)
  }
  console.log(n)

}
