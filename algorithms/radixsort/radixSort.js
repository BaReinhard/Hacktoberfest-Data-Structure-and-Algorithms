function radixSort(arr) {

    const max = getMax(arr); // length of the max digit in the array

    for (let i = 0; i < max; i++) {

        let buckets = Array.from({ length: 10 }, () => [ ])

        for (let j = 0; j < arr.length; j++) {

          buckets[getPosition(arr[ j ], i)].push(arr[ j ]); // pushing into buckets

        }

        arr = [ ].concat(...buckets);

    }

    return arr

} 
