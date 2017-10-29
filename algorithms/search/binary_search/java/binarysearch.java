// Java implementation of Binary Search
class BinarySearch
{
    // Returns index of x if it is present in arr[l..r], else return -1
    int binarySearch(int ar[], int l, int r, int x){
		if(ar.length == 0) {
    		return -1;
    	}
		
        if (r >= l){
            int mid = l + (r - l) / 2;
            // If the search is present at the mid postion
            if (ar[mid] == x){
               return mid;
            }
            // If element is smaller than mid, then it can only be in left subarray
            if (ar[mid] > x){
               return binarySearch(ar, l, mid - 1, x);
            }
            // Else the element can only be present in right subarray
            return binarySearch(ar, mid + 1, r, x);
        }
        // We reach here when element is not present in array
        return -1;
    }
    // Main method for testing
    public static void main(String args[])
    {
        BinarySearch ob = new BinarySearch();
        int arr[] = {1, 4, 5, 10, 11, 27, 36, 67, 90};
        int n = arr.length;
        int x = 10;
        int result = ob.binarySearch(arr, 0, n - 1, x);
        if (result == -1){
            System.out.println("Element not present");
        }
        else{
            System.out.println("Element found at index " + result);
        }
    }
}
