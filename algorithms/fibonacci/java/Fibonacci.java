import java.util.stream.Stream;

/**
 * A Java implementation of Fibonacci
 */
public class Fibonacci {

    public static int fibonacci(final int index){
        int firstOnOld=0;
        int secondOnHold=1;

        if (index == 0){
            return firstOnOld;
        }else if (index == 1) {
            return secondOnHold;
        }

        for (int i=2;i<=index;i++){
            int current = firstOnOld + secondOnHold;
            firstOnOld=secondOnHold;
            secondOnHold=current;
        }

        return secondOnHold;
    }

    /**
     * Test
     * @param args - arg
     */
    public static void main (String[] args) {
        Stream.iterate(0, n -> n<20, n-> n+1).forEach(x-> System.out.println("fibo of " + x +" is " +fibonacci(x)));
    }
}
