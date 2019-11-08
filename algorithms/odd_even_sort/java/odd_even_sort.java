/* Java program for Odd Even Sort */
class OddEvenSort {

  // Main function that sorts arr[l..r] usind
  // odd even sort()
  private static void sort(int arr[])
  {

    boolean sorted = false;
    while (!sorted) {
         sorted = true;
         for (int i = 1; i < array.length - 1; i += 2) {
              if (array[ i ] > array[ i + 1 ]) {
                   swapKeys( array , i , i + 1 );
                   sorted = false;
              }
         }

         for (int i = 0; i < array.length - 1; i += 2) {
              if (array[ i ] > array[ i + 1 ]) {
                   swapKeys( array , i , i + 1 );
                   sorted = false;
              }
         }
    }
  }

  /* A utility function to swap two keys at the Array */
  public static void swapKeys(int[] array, int i, int j) {
    int temp;
    temp = array[ i ];
    array[ i ] = array[ j ];
    array[ j ] = temp;
  }

  /* A utility function to print array of size n */
  public static void printArray(int arr[])
  {
      int n = arr.length;
      for (int i=0; i<n; ++i)
          System.out.print(arr[i] + " ");
      System.out.println();
  }

  // Driver method
  public static void main(String args[])
  {
      int arr[] = {12, 11, 13, 5, 6, 7};

      System.out.println("Given Array");
      printArray(arr);

      MergeSort.sort(arr);

      System.out.println("\nSorted array");
      printArray(arr);
  }


}
