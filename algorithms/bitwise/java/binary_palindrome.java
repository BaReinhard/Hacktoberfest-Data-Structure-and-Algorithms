public class BinaryPalidrome {
    // check if binary representation of a number is palidrome
    public static void main(String[] args) {
        int n = 153;
        if (new BinaryPalidrome().isPalidrome(n)) {
            System.out.println("Yes, the binary representation of the number " + n + " is palidrome.");
        } else {
            System.out.println("No, the binary representation of the number " + n + " is not a palidrome.");
        }
    }

    private boolean isPalidrome(int n) {
        int m = getTotalBits(n) - 1;
        int i = 0;
        while (i <= m) {
            if (kthBit(n, i) != kthBit(n, m)) {
                return false;
            }
            i++;
            m--;
        }
        return true;
    }

    private int kthBit(int n, int kthBit) {
        return (n & 1 << kthBit) > 0 ? 1 : 0;
    }

    private int getTotalBits(int n) {
        int totalBits = 0;
        while (n != 0) {
            totalBits++;
            n = n >> 1;
        }
        return totalBits;
    }
}
