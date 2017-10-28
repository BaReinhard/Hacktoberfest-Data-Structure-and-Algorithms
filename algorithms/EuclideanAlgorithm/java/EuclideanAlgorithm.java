public class EuclideanAlgorithm {

    public static void main(String[] args) {
        System.out.println(gcd(20, 5));
        System.out.println(gcd(5, 15));
    }


    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}