/* Fibonacci implementation in Scala */

def fibonacci: Stream[Int] = {
    def loop(a: Int, b: Int): Stream[Int] = (a + b) #:: loop(b, b + a)
    loop(0, 1)
}
