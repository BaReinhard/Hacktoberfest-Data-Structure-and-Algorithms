
// Binary Search implementation in Kotlin
class BinarySearch {

    fun search(list: MutableList<Int>, item: Int): Int {
        list.sort()
        println("After sorting => $list")
        var start = 0
        var end = list.size - 1

        while (start <= end) {
            val mid = start + ((end - start) / 2)
            when {
                list[mid] == item -> return mid
                list[mid] < item -> start = mid + 1
                else -> end = mid - 1
            }
        }

        return -1
    }
}

// Main test cases to test the implementation
class BinarySearchTest {

    private fun testElementExists() {
        val idx = BinarySearch().search(mutableListOf(1,3,5,8,3,1,2,3,6),5)

        if(idx == 6) {
            println("Test Passed")
        }
    }

    private fun testElementDoesNotExist() {
        val idx = BinarySearch().search(mutableListOf(1,3,5,8,3,1,2,3,6),77)
        if(idx == -1) {
            println("Test Passed")
        }

    }

    private fun testEmptyList() {
        val idx = BinarySearch().search(mutableListOf(),8)
        if(idx == -1) {
            println("Test Passed")
        }
    }


    fun runTests() {
        testElementDoesNotExist()
        testElementExists()
        testEmptyList()
    }


}

// Driver method
fun main() {
    BinarySearchTest().runTests()
}
