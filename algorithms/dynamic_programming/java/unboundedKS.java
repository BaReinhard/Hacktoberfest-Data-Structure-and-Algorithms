import java.util.*;

public class unboundedKS
{
    public static int knapsack(int[] wt, int[] prices, int cap)
    {
        int[] strg = new int[cap + 1];

        for(int i = 1; i < strg.length; i++)
        {   
            int max = 0;
            for(int j = 0; j < wt.length; j++)
            {
                if(i >= wt[j])
                {
                    max = Math.max(max, strg[i - wt[j]] + prices[j]);
                }
            }
            strg[i] = max;
        }
        return strg[cap];
    }
    public static void main(String[] args)
    {
        int[] wt = {2, 5, 1, 3, 4};
        int[] prices = {15, 14, 10 ,45, 30};
        int cap = 7;

        int res = knapsack(wt, prices, cap);
        System.out.println(res);
    }
}