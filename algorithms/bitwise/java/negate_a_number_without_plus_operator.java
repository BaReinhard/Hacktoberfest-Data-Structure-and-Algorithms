public class NegateANumberWithoutPlusOperator {
    public static void main(String[] args) {
        NegateANumberWithoutPlusOperator number = new NegateANumberWithoutPlusOperator();
        int n = 54;
        System.out.println("Negation of number " + n + " is " + number.negate(n));
    }

    private int negate(int n) {
        n = ~n;
        return add(n, 1);
    }
    private int add(int a, int b) {
        int carry;
        while (b != 0) {
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
}
