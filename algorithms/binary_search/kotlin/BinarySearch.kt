// Kotlin implementation of Binary Search
internal class BinarySearch {
    // Returns index of x if it is present in arr[l..r], else return -1
    fun binarySearch(ar: IntArray, l: Int, r: Int, x: Int): Int {
        if (ar.isEmpty()) {
            return -1
        }

        if (r >= l) {
            val mid = l + (r - l) / 2
            // If the search is present at the mid position
            if (ar[mid] == x) {
                return mid
            }
            // If element is smaller than mid, then it can only be in left subarray
            return if (ar[mid] > x) {
                binarySearch(ar, l, mid - 1, x)
            } else binarySearch(ar, mid + 1, r, x)
            // Else the element can only be present in right subarray
        }
        // We reach here when element is not present in array
        return -1
    }
}

fun main() {
    val ob = BinarySearch()
    val arr = intArrayOf(1, 4, 5, 10, 11, 27, 36, 67, 90)
    val n = arr.size
    val x = 10
    val result = ob.binarySearch(arr, 0, n - 1, x)
    if (result == -1) {
        println("Element not present")
    } else {
        println("Element found at index $result")
    }
}