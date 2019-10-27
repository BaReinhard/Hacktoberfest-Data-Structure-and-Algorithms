import java.util.*;

public class zoKnapsack
{
    public static int knapsack(int[] wt, int[] prices, int cap)
    {
        int[][] strg = new int[wt.length][cap + 1];

        strg[0][0] = 0;
        for(int i = 0; i < strg.length; i++)
        {
            for(int j = 0; j < strg[0].length; j++)
            {
                if(i == 0 && j == 0)
                {
                    strg[i][j] = 0;
                }
                else if(i == 0)
                {
                    if(j >= wt[i])
                    {
                        strg[i][j] = wt[i];
                    }
                }
                else if(j == 0)
                {
                    strg[i][j] = 0;
                }
                else 
                {
                    if(j >= wt[i])
                    {
                        if(prices[i] >= strg[i-1][j - wt[i]])
                        {
                            //play
                            strg[i][j] += strg[i - 1][j - wt[i]] + prices[i];
                        }
                    }
                    else
                    {
                        //no play
                        strg[i][j] = strg[i - 1][j - wt[i]];
                    }
                }
            }
        }
        return strg[wt.length - 1][cap];
    }

    public static void main(String[] args)
    {
        int[] wt = {2, 5, 1, 3, 4};
        int[] prices = {15, 14, 10 ,45, 30};
        int cap = 7;

        int res = knapsack(wt, prices, cap);
    }
}