// https://www.geeksforgeeks.org/gold-mine-problem/
    public static int GoldMine_Memoization(int sr, int sc, int[][] grid, int[][] dp) 
    {
        if (sc == grid[0].length - 1) 
        {
            return dp[sr][sc] = grid[sr][sc];
        }

        if (dp[sr][sc] != 0) 
        {
            return dp[sr][sc];
        }

        int[][] dir = { { -1, 1 }, { 0, 1 }, { 1, 1 } };
        int maxCoins = 0;
        for (int d = 0; d < 3; d++) 
        {
            int x = sr + dir[d][0];
            int y = sc + dir[d][1];

            if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length) 
            {
                maxCoins = Math.max(maxCoins, GoldMine_Memoization(x, y, grid, dp));
            }
        }

        return dp[sr][sc] = maxCoins + grid[sr][sc];
    }
    public static int GoldMine_Tabulation(int sr, int sc, int[][] grid, int[][] dp) 
    {
        for (sc = grid[0].length - 1; sc >= 0; sc--) 
        {
            for (sr = grid.length - 1; sr >= 0; sr--) 
            {
                if (sc == grid[0].length - 1) 
                {
                    dp[sr][sc] = grid[sr][sc];
                    continue;
                }

                int[][] dir = { { -1, 1 }, { 0, 1 }, { 1, 1 } };
                int maxCoins = 0;
                for (int d = 0; d < 3; d++) 
                {
                    int x = sr + dir[d][0];
                    int y = sc + dir[d][1];

                    if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length) 
                    {
                        maxCoins = Math.max(maxCoins, dp[x][y]);
                    }
                }

                dp[sr][sc] = maxCoins + grid[sr][sc];
            }
        }

        int max = 0;
        for (int i = 0; i < grid.length; i++) 
        {
            max = Math.max(max, dp[i][0]);
        }

        return max;
    }
    public static void GoldMine_Problem()
    { 
        int[][] grid = { 
                        {1, 3, 1, 5}, 
                        {2, 2, 4, 1}, 
                        {5, 0, 2, 3},
                        {0, 6, 1, 2} 
        }; 
        int n = grid.length; int m = grid[0].length; 
        int[][] dp = new int[n][m]; 
        int maxCoin = 0; 
        for(int i = 0; i < n; i++) 
        { 
            maxCoin = Math.max(maxCoin, GoldMine_Memoization(i, 0, grid, dp)); 
        } 
        System.out.println("Memoization :- " + maxCoin); 
        display_2D(dp);
        System.out.println("Tabulation :- " + GoldMine_Tabulation(0, 0, grid, dp));
        display_2D(dp);
    }
