// https://www.geeksforgeeks.org/friends-pairing-problem/
    public static int Friends_Pairing_Problem_Memoization(int n, int[] dp) 
    {
        if (n <= 1) 
        {
            return dp[n] = 1;
        }

        if (dp[n] != 0) 
        {
            return dp[n];
        }

        int single = Friends_Pairing_Problem_Memoization(n - 1, dp);
        int pairup = Friends_Pairing_Problem_Memoization(n - 2, dp) * (n - 1);

        int ans = single + pairup;
        return dp[n] = ans;
    }
    public static int Friends_Pairing_Problem_Tabulation(int n, int[] dp) 
    {
        int N = n;
        for (n = 0; n <= N; n++) 
        {
            if (n <= 1) 
            {
                dp[n] = 1;
                continue;
            }

            int single = dp[n - 1];
            int pairup = dp[n - 2] * (n - 1);

            int ans = single + pairup;
            dp[n] = ans;
        }
        return dp[N];
    }
    public static void Friends_Pairing_Problem()
    {
        int n = 10;
        int[] dp = new int[n+1];
        System.out.println("Memoization :- " + Friends_Pairing_Problem_Memoization(n,dp));
        display_1D(dp);
        System.out.println("Tabulation :- " + Friends_Pairing_Problem_Tabulation(n,dp));
        display_1D(dp);
    }
