function sort(array) {
  if (array.length < 2) {
    return array;
  }

  let mid = Math.floor(array.length / 2);
  let left = array.slice(0, mid);
  let right = array.slice(mid);

  return merge(sort(left), sort(right));
}

function merge(left, right) {
  let result = [];
  let indexLeft = 0;
  let indexRight = 0;

  while (indexLeft < left.length && indexRight < right.length) {
    result.push(
      left[indexLeft] < right[indexRight]
        ? left[indexLeft++]
        : right[indexRight++]
    );
  };

  return result
    .concat(left.slice(indexLeft))
    .concat(right.slice(indexRight));
}
