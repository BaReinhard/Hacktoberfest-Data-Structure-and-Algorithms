- (NSArray *)bubbleSort:(NSArray *)unsortedArray {
    //create mutable copy of the array
    NSMutableArray *unsortedMutableArray = [unsortedArray mutableCopy];
    
    for (int i = 0; i < unsortedMutableArray.count; ++i) {
        for (int j = 0; j < (unsortedMutableArray.count - i - 1); ++j) {
            //reading integer values of the current and the next elements in the array
            NSInteger currElement = [unsortedMutableArray[j] integerValue];
            NSInteger nextElement = [unsortedMutableArray[j + 1] integerValue];
            
            //comparing the elements
            if (currElement > nextElement) {
                NSNumber *temp = unsortedMutableArray[j]; //keeping the current element in a temp
                //swapping the elements
                unsortedMutableArray[j] = unsortedMutableArray[j + 1];
                unsortedMutableArray[j + 1] = temp;
            }
        }
    }
    //return the sorted array
    return [NSArray arrayWithArray:unsortedMutableArray];
}
