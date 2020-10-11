const countNumberSort = (x) => {
  let setMin = [];
  let setMax = [];
  let max;
  let min;
  let round = 0;

  while (x.length != 0) {
    if (x.length == 1) {
      min = Math.min(...x);

      setMin = [...setMin, min];
    } else {
      max = Math.max(...x);
      min = Math.min(...x);
      setMin = [...setMin, min];
      setMax = [max, ...setMax];
    }

    x = x.filter((e) => e !== max);
    x = x.filter((e) => e !== min);

    round++;
  }

  const result = setMin.concat(setMax);

  console.log('Result : ' + result);
};

let arr = [20, 81, 30, 60, 35, 56, 15, 1, 7, 23, 11];

let sortedArray = countNumberSort(arr);

console.log(sortedArray);
