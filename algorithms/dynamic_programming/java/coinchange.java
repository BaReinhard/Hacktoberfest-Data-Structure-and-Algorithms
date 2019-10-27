import java.util.*;

public class coinchange {
    static int countccPerm(int[] coins, int amt) {
        int[] strg = new int[amt + 1];
        strg[0] = 1;

        for (int i = 1; i <= amt; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (i >= coins[j]) {
                    strg[i] += strg[i - coins[j]];
                }
            }
        }
        return strg[amt];
    }

    static int countccComb(int[] coins, int amt) {
        int[] strg = new int[amt + 1];
        strg[0] = 1;
        for (int j = 0; j < coins.length; j++) {
            for (int i = 1; i <= amt; i++) {

                if (i >= coins[j]) {
                    strg[i] += strg[i - coins[j]];
                }
            }

        }
        return strg[amt];
    }

    public static void main(String[] args) {
        int[] coins = { 2, 3, 5, 6 };
        int amt = 7;
        long start = System.currentTimeMillis();
        // int res = countccPerm(coins, amt);
        int res = countccComb(coins, amt);
        long end = System.currentTimeMillis();
        long duration = end - start;
        System.out.println(res + " in " + duration + " ms");

        // System.out.println(res);
    }
}