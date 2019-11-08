/**
 * Java implementation of Euclidean Algorithm.
 * Used to find Greatest Common Divider(GCD) of two numbers.
 */
public class Euclidean {
    public static void main(String[] args) {
        gcd(4, 24);  // 4
        gcd(10, 15); // 5
        gcd(34, 12); // 2
    }

    private static void gcd(int first, int second) {
        while (second != 0) {
            // for gcd(4, 24) => first = 4 % 24 = 4; first = 24 % 4 = 0
            first %= second;

            // swap values
            int tmp = first;
            first = second;
            second = tmp;
        }
        System.out.println(first);
    }
}
