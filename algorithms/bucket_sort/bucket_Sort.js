function bucketSort(arr){
 let obj = {};
 for(let i=0;i<arr.length; i++){
     obj[i] = [];
 }
 for(let i=0;i<arr.length ;i++){
     obj[Math.floor(arr.length * arr[i])].push(arr[i]);
 }
    for(let i in obj){
     if(obj[i].length){
         insertionSort(obj[i]);
     }
    }
    let k=0;
    for(let i in obj) {
        if (obj[i].length) {
            for (let j = 0; j < obj[i].length; j++) {
                arr[k] = obj[i][j];
                k += 1;
            }
        }
    }
    console.log(arr);

}
function insertionSort(arr){
    for(let i=1 ;i<arr.length; i++){
        let key = arr[i];
        let j =i-1;
        while(j>=0 &&arr[j]> key){
            arr[j+1] =arr[j];
            j-=1;
        }
        arr[j+1] = key;
    }
}
let arr = [];
bucketSort(arr);