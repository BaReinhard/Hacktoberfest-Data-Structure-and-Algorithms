class InsertionSort {

    /*
    This class sorts an array using insertion sort
     */

    public static int[] insertionSort(int[] array) {
        int key,
                previousIndex;

        for (int index = 1; index < array.length; index++) {
            key = array[index];
            previousIndex = index - 1;

            while(previousIndex >= 0 && array[previousIndex] > key){
                array[previousIndex + 1] = array[previousIndex];
                previousIndex -= 1;
                array[previousIndex + 1] = key;
            }
        }
        return array;
    }

    public static void main(String[] args) {
        int[] array = new int[10];


        for (int i = 10; i > 0 ; i--) {
            array[10 - i] = i;
        }

        int[] sortedArray = insertionSort(array);

        for (int i: sortedArray) {
            System.out.print(i + " ");
        }
    }
}
