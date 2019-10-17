const binarySearch = (arr, x, start, end) => { 
       
    if (start > end) return false; 
   
    let mid=Math.floor((start + end)/2); 
   
    if (arr[mid]===x) return true; 
          
    if(arr[mid] > x)  
        return binarySearch(arr, x, start, mid-1); 
    else
  
        return binarySearch(arr, x, mid+1, end); 
} 

const checkValue = (value, arr) => {
    if (binarySearch(arr, value, 0, arr.length - 1)) {
        console.log('Element found!');
    } else {
        console.log('Begone from my sight, peasent!');
    }
}  
// Driver code 
const arr = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]; 
let valueToCheckFor = 5; 
   
checkValue(valueToCheckFor, arr)