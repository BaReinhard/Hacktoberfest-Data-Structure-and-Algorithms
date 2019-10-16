// Takes an Array, arr, and returns an Array of all permutations of arr

const permutations = function(arr) {
  let result = [];

  permute(arr, [], result);

  return result;
};

const permute = (arr, m = [], result) => {
  if (arr.length === 0) {
    result.push(m);

  } else {
    for (let i = 0; i < arr.length; i++) {
      let current = arr.slice();
      let next = current.splice(i, 1);

      permute(current.slice(), m.concat(next), result);
    };
  };
};
