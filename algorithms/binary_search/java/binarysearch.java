
// Java implementation of Binary Search
public class BinarySearch
{
    //takes index and number to search for
    int binarySearch(int array[], int x){
        
        //where to start and end the search
        int i = 0;
        int end = array.length-1;
		
        while (i <= end){
            int mid = end + i/ 2;
            // Finds element in the middle of the array
            if (array[mid] == x) {
               return mid;
            } else if (array[mid] > x) {
                //limits to beginning of array
               end = mid - 1;
            } else {
                //limits to end of the array
            i = mid + 1;
            }
        }
        // element is not present or array is empty
        return -1;
    }
    // Main method for testing
    public static void main(String args[])
    {
        BinarySearch bs = new BinarySearch();
        int arr[] = {1, 6, 8, 12, 13, 23, 30, 48, 120};
        int x = 12;
        int result = bs.binarySearch(arr, x);
        if (result == -1){
            System.out.println("Element not present");
        }
        else{
            System.out.println("Element found at index " + result);
        }
    }
}
