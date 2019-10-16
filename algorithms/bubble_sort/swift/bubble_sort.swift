func bubbleSort(unsortedArray: Array<NSNumber>) -> Array<NSNumber> {
    //mutable copy of the initial array
    var mutableArray = unsortedArray
    //double looping through the array
    for i in 0..<mutableArray.count {
        for j in 0..<(mutableArray.count - i - 1) {
            //checking the elements
            if (mutableArray[j] as! Int > mutableArray[j + 1] as! Int) {
                let temp = mutableArray[j] //storing into a temp value
                //swapping the elements
                mutableArray[j] = mutableArray[j + 1]
                mutableArray[j + 1] = temp
            }
        }
    }
    //returning the sorted array
    let sortedArray = mutableArray
    return sortedArray
}
