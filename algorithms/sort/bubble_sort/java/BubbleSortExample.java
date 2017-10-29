import java.util.Scanner;

public class BubbleSortExample {

    private static void bubbleSort(int[] arr) {
        int n = arr.length;
        int temp = 0;
        for(int i=0; i < n; i++){
            for(int j=1; j < (n-i); j++){
                if(arr[j-1] > arr[j]){
                    //swap elements
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }

            }
        }

    }
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        System.out.println("Input the size of array");
        int n = in.nextInt();
        int[] arr = new int[n];

        System.out.println("Input the elements of array");
        for(int i=0; i<n; i++){
            arr[i] = in.nextInt();
        }

        System.out.println("Array Before Bubble Sort");
        for (int anArr : arr) {
            System.out.print(anArr + " ");
        }
        System.out.println();

        bubbleSort(arr);//sorting array elements using bubble sort

        System.out.println("Array After Bubble Sort");
        for (int anArr : arr) {
            System.out.print(anArr + " ");
        }

    }
}
