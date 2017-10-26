
public class AddTwoNumbersWithoutPlusOperator {
    public static void main(String[] args) {
        int a = 10;
        int b = 90;
        add(a, b);
    }

    private static void add(int a, int b) {
        int carry;
        while (b != 0) {
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        System.out.println("The sum  " + a);
    }
}
