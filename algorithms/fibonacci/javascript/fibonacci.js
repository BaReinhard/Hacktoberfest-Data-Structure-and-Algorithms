// return nth term in fibonacci series
function fibonacciNthTerm (n) {
  if (n === 0) return 0
  if (n === 1) return 1
  return fibonacciNthTerm(n - 1) + fibonacciNthTerm(n - 2)
}

// generate fibonacci series of n terms
function fibonacciSeries (n) {
  for (let i = 0; i < n; i++) {
    console.log(fibonacciNthTerm(i))
  }
}

fibonacciSeries(5)
