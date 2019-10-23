public class Fibonacci {
    public static void main(String[] args) {
        int first = recursiveFibo(10);
        System.out.println(first);
    }

    // returns n+1th fibonacci
    public static int recursiveFibo(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        return recursiveFibo(n-1) + recursiveFibo(n-2);
    }
}