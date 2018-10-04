function removePunctuation(stringToStrip) {
  return stringToStrip.replace(/[^A-z0-9_]/g,"");
}
function reversedString(string) {
  let lettersAsArray = string.split("");
  return lettersAsArray.reverse().join("");
}
function palindromeCheck(string) {
  let cleanString = removePunctuation(string);
  let original = cleanString;
  let reversed = reversedString(cleanString);
  if (original === reversed) {
    return true;
  } else if (original != reversed) {
    return false;
  }
}
