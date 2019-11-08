fun sort(arr: Array<Long>): Array<Long> {
    var items : Boolean;
    do {
        items = false;
        for (i in 0..arr.size - 2){
            if (arr[i] > arr[i + 1]){
                swap(arr, i, i + 1);
                items = true;
            }
        }
    } while (items);
    return arr;
} 
