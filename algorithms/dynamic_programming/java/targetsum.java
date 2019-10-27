import java.util.*;

public class targetsum
{
    static void printtarsum(boolean[][] strg, int i, int j, int[] arr, String asf)
    {
        if(i == 0)
        {
            if(j == 0)
            {
                System.out.println(asf);
            }
            if(j == arr[0]) 
            {
                System.out.println(asf + arr[0] + " ");
            }
        }
        else
        {
            if(strg[i - 1][j] == true)
            {
                printtarsum(strg, i - 1, j, arr, asf);
            }
            if(j >= arr[i])
            {
                if(strg[i - 1][j - arr[i]] == true)
                {
                    printtarsum(strg, i - 1, j - arr[i], arr, asf + arr[i] + " ");
                }
            }
        }
    }
    static boolean tarsum(int[] arr, int target)
    {
        boolean[][] strg = new boolean[arr.length][target + 1]; //rows = arr.length, cols = target + 1

        strg[0][0] = true;
        for(int i = 0; i < strg.length; i++)
        {
            for(int j = 0; j < strg[0].length; j++)
            {
                if(i == 0 && j == 0)
                {
                    strg[i][j] = true;
                }
                else if(i == 0)
                {
                    if(j == arr[i])
                    {
                        strg[i][j] = true;
                    }
                }
                else if(j == 0)
                {
                    strg[i][j] = true;
                }
                else 
                {
                    if(strg[i - 1][j] == true)
                    {
                        strg[i][j] = true;
                    }
                    else
                    {
                        if(j >= arr[i])
                        {
                            if(strg[i - 1][j - arr[i]] == true)
                            {
                                strg[i][j] = true;
                            }
                        }
                    }
                }
            }
        }
        printtarsum(strg, arr.length - 1, target, arr, "");
        return strg[arr.length - 1][target];
    }
    public static void main(String[] args)
    {
        int[] arr = {3, 2, 1, 5, 8};
        int target = 9;
        long start = System.currentTimeMillis();
        boolean res = tarsum(arr, target);
        long end = System.currentTimeMillis();
        long duration = end - start;
        System.out.println(res + " in " + duration + " ms");
    }
}