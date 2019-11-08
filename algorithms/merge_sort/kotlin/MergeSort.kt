fun merge_sort(A: Array<Int>, p: Int, r: Int) {
    if (p < r) {
        val q = (p + r) / 2
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)
    }
}

fun main(arg: Array<String>) {
    print("Enter no. of elements :")
    val n = readLine()!!.toInt()

    println("Enter elements : ")
    val A = Array(n) { 0 }
    for (i in 0 until n)
        A[i] = readLine()!!.toInt()

    merge_sort(A, 0, A.size - 1)

    println("Sorted array is : ")
    for (i in 0 until n)
        print("${A[i]}  ")
}
