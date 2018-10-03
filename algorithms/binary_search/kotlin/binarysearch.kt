
fun main(args: Array<String>) {
    print(searchBinary(listOf(6, 5, 9, 12, 7, 4, 0), 4))
}

fun searchBinary(numberList: List<Int>, numToFind: Int): String {
    val sortedList = numberList.sorted()
    var start = 0
    var end = sortedList.size
    while(start < end) {
        val mid = start + (end - start) / 2
        val current = sortedList[mid]
        if (current == numToFind) {
            val countIndex = numberList.indexOf(current) + 1
            return "$numToFind is the #$countIndex element of the list"
        }
        if (current < numToFind) {
            start = mid + 1
        } else {
            end = mid
        }
    }
    return "The list does not contain $numToFind"
}
