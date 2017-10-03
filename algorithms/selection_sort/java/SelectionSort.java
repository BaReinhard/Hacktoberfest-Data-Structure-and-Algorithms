// Java program for implementation of Selection Sort
class SelectionSort
{
    // Implementation of Selection Sort
    void sort(int ar[])
    {
        int n = ar.length;
        for (int i = 0; i < n-1; i++)
        {
            int min = i, temp;
            for (int j = i+1; j < n; j++)
                if (ar[j] < ar[min]){
                    min = j;
            }
            temp = ar[min];
            ar[min] = ar[i];
            ar[i] = temp;
        }
    }
    // Prints the array
    void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }
    // Main function to test
    public static void main(String args[])
    {
        SelectionSort ob = new SelectionSort();
        int arr[] = {79, 34, 7, 23, 11, 10, 99, 1, 15, 11};
        ob.sort(arr);
        System.out.println("Sorted array:");
        ob.printArray(arr);
    }
}
