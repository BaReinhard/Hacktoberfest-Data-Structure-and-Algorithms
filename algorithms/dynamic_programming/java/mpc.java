import java.util.*;

public class mpc
{
    public static int mpc1(String s)
    {
        int[][] strg = new int[s.length()][s.length()];

        for(int gap = 0; gap < s.length(); gap++)
        {
            for(int i = 0; i < s.length() - gap; i++)
            {
                int j = gap + i;
                
                

                if(gap == 0)
                {
                    strg[i][j] = 0;
                }
                else if(gap == 1)
                {
                    strg[i][j] = s.charAt(i) == s.charAt(j)? 0:1;
                }
                else 
                { 
                    if(s.charAt(i) == s.charAt(j) && strg[i + 1][j - 1] == 0)
                    {
                        strg[i][j] = 0;
                    }
                    else 
                    {  
                        int mymin = s.length(); 

                        for(int k = 0; k < gap; k++)
                        {
                            int left = strg[i][i + k];
                            int right = strg[i + 1 + k][j];

                            if(left + right < mymin)
                            {
                                mymin = left + right;
                            }
                        }
                        strg[i][j] = mymin + 1;
                    }
                }
            }
        }
        return strg[0][s.length() - 1];
    }
    public static void main(String[] args)
    {
        long start = System.currentTimeMillis();
        int res = mpc1("abccbc");
        long end = System.currentTimeMillis();
        long duration = end - start;

        System.out.println(res + " in " + duration + " ms");
    }
}