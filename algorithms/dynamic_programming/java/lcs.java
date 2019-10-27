import java.util.*;

public class lcs
{
    public static int lcsq(String s1, String s2)
    {
        int[][] strg = new int[s1.length() + 1][s2.length() + 1];
        
        for(int i = strg.length - 2; i >= 0; i--)
        {
            for(int j = strg[0].length - 2; j >= 0; j--)
            {
                if(s1.charAt(i) == s2.charAt(j))
                {
                    strg[i][j] = 1 + strg[i + 1][j + 1];
                }
                else
                {
                    strg[i][j] = Math.max(strg[i][j + 1], strg[i + 1][j]);
                }
            }
        }
        return strg[0][0];
    }
    public static void main(String[] args)
    {
        long start = System.currentTimeMillis();
        int res = lcsq("abcd", "aebd");
        long end = System.currentTimeMillis();
        long duration = end - start;
        System.out.println(res + " in " + duration + " ms");
    }
}