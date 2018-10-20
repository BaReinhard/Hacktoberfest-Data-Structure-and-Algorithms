function isPalindrome (num) {
  let reverse = 0
  for (let i = num; i > 0; i = parseInt(i / 10)) {
    reverse = reverse * 10 + parseInt(i % 10)
  }
  if (num === reverse) console.log('Palindrome')
  else console.log('Not Palindrome')
}

isPalindrome(23432)
