import java.util.*;

public class lps
{
    public static int lpsq(String s)
    {
        int[][] strg = new int[s.length()][s.length()];

        //diagonal traversal loop
        for(int gap = 0; gap < s.length(); gap++)
        {
            for(int i = 0; i < s.length() - gap; i++)
            {
                int j = gap + i;

                if(gap == 0)
                {
                    strg[i][j] = 1;
                }
                else if(gap == 1)
                {
                    strg[i][j] = s.charAt(i) == s.charAt(j)? 2: 1;
                }
                else {
                    if(s.charAt(i) == s.charAt(j))
                    {
                        strg[i][j] = 2 + strg[i + 1][j - 1];
                    }
                    else
                    {
                        strg[i][j] = Math.max(strg[i][j - 1], strg[i + 1][j]);
                    }
                }
            }
        }
        return strg[0][s.length() - 1];
        
    }
    public static void main(String[] args) 
    {
        long start = System.currentTimeMillis();
        int res = lpsq("abckycbc"); 
        long end = System.currentTimeMillis();
        long duration = end - start;
        System.out.println(res + " in " + duration + " ms");   
    }
}
