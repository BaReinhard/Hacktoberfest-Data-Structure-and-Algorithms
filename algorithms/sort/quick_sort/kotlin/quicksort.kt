class QuickSort {
    private fun quickSort(arr: IntArray, start: Int, end: Int) {
        if (start < end) {
            val pivot_pos = partition(arr, start, end)
            quickSort(arr, start, pivot_pos - 1)
            quickSort(arr, pivot_pos + 1, end)
        }
    }

    private fun partition(arr: IntArray, start: Int, end: Int): Int {
        val pivot = arr[end]
        var i = start
        var j = end - 1
        while (i <= j) {
            if (arr[j] <= pivot && arr[i] > pivot) {
                swap(arr, i, j)
            }
            if (arr[i] <= pivot) {
                i++
            }
            if (arr[j] > pivot) {
                j--
            }
        }
        swap(arr, i, end)
        return i
    }

    private fun swap(arr: IntArray, i: Int, j: Int) {
        val tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp
    }

    private fun print(arr: IntArray) {
        for (i in arr.indices) {
            print(arr[i].toString() + " ")
        }
        print('\n')
    }

    fun main() {
        val arr = intArrayOf(9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 6)
        print("Before: ")
        print(arr)
        quickSort(arr, 0, arr.size - 1)
        print("After: ")
        print(arr)
    }
}
