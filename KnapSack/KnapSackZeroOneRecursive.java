package com.company.KnapSack;

public class KnapSackZeroOneRecursive {

    public static void main(String[] args) {
        int[] weight = {1,3,4,5};
        int[] values = {1,4,5,7};
        int max_weight = 7;
        int n = weight.length;
        KnapSack obj = new KnapSack();
        System.out.println(obj.knapSackRecursive(weight, values,max_weight,n));
        System.out.println(obj.KnapSackMemoization(weight, values,max_weight,n));
    }
}

class KnapSack {
    public int knapSackRecursive(int[] weights, int[] values, int max_weight, int n) {

        //Base condition
        if (n == 0 || max_weight == 0) {
            return 0;
        }

        //choice diagram
        if (weights[n-1] <= max_weight) {
           return Math.max(values[n-1] + knapSackRecursive(weights, values, max_weight - weights[n-1], n-1), knapSackRecursive(weights, values,max_weight, n-1));
        } else {
            return knapSackRecursive(weights, values, max_weight, n - 1);
        }
    }

    public int KnapSackMemoization(int[] weights, int[] values, int max_weight, int n) {
        int[][] t = new int[102][102];
        for (int  i =0; i<t.length; i++) {
            for (int j = 0; j < t.length; j++) {
                t[i][j] = -1;
            }
        }
        //Base condition
        if (n == 0 || max_weight == 0) {
            return 0;
        }
        if (t[n][max_weight] != -1) {
            return t[n][max_weight];
        }
        //choice diagram
        if (weights[n-1] <= max_weight) {
            return t[n][max_weight] =  Math.max(values[n-1] + knapSackRecursive(weights, values, max_weight - weights[n-1], n-1),
                    knapSackRecursive(weights, values,max_weight, n-1));
        } else {
            return t[n][max_weight] = knapSackRecursive(weights, values, max_weight, n - 1);
        }
    }
}
