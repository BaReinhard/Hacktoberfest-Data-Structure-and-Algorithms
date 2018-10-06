import java.util.Scanner

class TowersOfHanoi {

    fun solve(n: Int, start: String, auxiliary: String, end: String) {
        if (n == 1) {
            println("$start -> $end")
        } else {
            solve(n - 1, start, end, auxiliary)
            println("$start -> $end")
            solve(n - 1, auxiliary, start, end)
        }
    }

    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            val towersOfHanoi = TowersOfHanoi()
            print("Enter number of discs: ")
            val scanner = Scanner(System.`in`)
            val discs = scanner.nextInt()
            towersOfHanoi.solve(discs, "A", "B", "C")
        }
    }
}