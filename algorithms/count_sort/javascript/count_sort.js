"use strict";
var countSort = (arr, range)=>{
    /**
     * Consider the input is in range of 1 to 9
      */
    // this can vary depending on your input array
    let countArr = [];
    //Initialise count array to 0;
    for(let i=0; i <= range; i++){
        countArr[i] = 0;
    }
    for(let i=0; i < arr.length; i++){
        ++countArr[arr[i]];
    }
    for(let i=1; i<= countArr.length-1; i++){
        countArr[i] += countArr[i-1];
    }
    //Take the sorted array and insert the data of input array based on the count array and
    // decrease the value by 1 every time the element is inserted in sorted array

    let sortedArray = new Array(arr.length -1);
    for(let i=0; i<arr.length; i++){
        sortedArray[countArr[arr[i]]-1] = arr[i];
        --countArr[arr[i]];
    }
 return sortedArray;    
}
let arr = [2,1,3,4,5,4,6,7,6];
let range = 9;
let sortedArray = countSort(arr, range);
console.log(sortedArray);