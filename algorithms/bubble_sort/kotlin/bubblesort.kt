public class bubbleSort : Algorithm{

    public override fun sort(arr: Array<Long>): Array<Long> {
        var swappedElements : Boolean;
        do {
            swappedElem = false;
            for (i in 0..arr.size - 2){
                if (arr[i] > arr[i + 1]){
                    swap(arr, i, i + 1);
                    swappedElem = true;
                }
            }
        } while (swappedElem);
        return arr;
    }

    public override fun getName(): String {
        return "BubbleSort Algorithm";
    }
}
