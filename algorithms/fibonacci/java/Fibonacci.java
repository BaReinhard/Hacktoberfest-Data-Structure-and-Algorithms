import java.util.Arrays;

class Fibonacci {

    /**
     * Recursive way to get the nth number in fibonacci
     * @param n place
     * @return Number based on n
     */
    static int recursiveFib(int n){
        if(n == 0 || n == 1) // Base Case
            return 1;
        else
            return recursiveFib(n-1) + recursiveFib(n-2);
    }

    /**
     * The dynamic (efficient) way of getting fibonacci
     * @param n place
     * @return Number based on n
     */
    static int dynamicFib(int n){
        // Keep track of fib numbers
        int[] fib = new int[n+1];
        // What we don't know, fill with -1s
        Arrays.fill(fib, -1);
        // The base case
        fib[0] = 1;
        fib[1] = 1;

        return dynamicFib(n, fib);
    }

    private static int dynamicFib(int n, int[] fib){
        if(n < 0) return 0; // Just in case we call a number less than 0

        if(fib[n] == -1) // If we don't know the nth place of fib
            fib[n] = dynamicFib(n-1,fib) + dynamicFib(n-2, fib); // Find it with what we know so far

        return fib[n]; // Return the final value

    }

    public static void main(String[] args) {
        int[] numbersToCheck = {10, 25, 40};

        // Use recursive fib method
        for(Integer n : numbersToCheck){
            long startTime = System.currentTimeMillis();
            System.out.println(recursiveFib(n));
            System.out.println("Execution time: " + (System.currentTimeMillis() - startTime));
        }

        // Use Dynamic fib method
        for(Integer n : numbersToCheck){
            long startTime = System.currentTimeMillis();
            System.out.println(dynamicFib(n));
            System.out.println("Execution time: " + (System.currentTimeMillis() - startTime));
        }
    }
}