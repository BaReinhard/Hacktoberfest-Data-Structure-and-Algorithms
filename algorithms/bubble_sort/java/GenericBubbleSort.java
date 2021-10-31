
class GenericBubbleSort {

    public static <T extends Comparable<T>> void bubble_sort(T array[]){
        boolean swapped;
        int indexOfLastUnsortedElement =  array.length;
        do{
            swapped = false;
            for(int i=0; i < indexOfLastUnsortedElement - 1; i++){
                if(array[i].compareTo(array[i+1]) > 0){
                    swap(i, array);
                    swapped = true;
                }
            }
            indexOfLastUnsortedElement--;
            printArray(array);
        }while(swapped);
    }

    private static <T> void swap(int index, T[] array){
        T temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
    }

    private static <T> void printArray(T[] input){
        for(int i  = 0; i < input.length; i++){
            System.out.print(input[i] + " ");
        }
        System.out.print("\n");
    }

    public static void main(String[] args){
        bubble_sort(new Integer[] {4, 2, 9, 6, 23, 12, 34, 0, 1});
        bubble_sort(new String[] { "c", "a", "e", "d", "b" });
    }
}