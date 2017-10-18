/**
 * @author Shrikrushna Atkalikar
 */
public class TernarySearch {

    /**
     * Method for ternary search
     *
     * @param arr         collection of elements
     * @param searchValue element to be searched
     * @param start       start index
     * @param end         end index
     * @return index of element or -1 if element not found.
     */
    public static int ternarySearch(int[] arr, int searchValue, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid1 = start + (end - start) / 3;
        int mid2 = start + 2 * (end - start) / 3;

        if (arr[mid1] == searchValue) {
            return mid1;
        } else if (arr[mid2] == searchValue) {
            return mid2;
        } else if (searchValue < arr[mid1]) {
            return ternarySearch(arr, searchValue, start, mid1 - 1);
        } else if (searchValue > arr[mid2]) {
            return ternarySearch(arr, searchValue, mid2 + 1, end);
        } else {
            return ternarySearch(arr, searchValue, mid1, mid2);
        }
    }
}
