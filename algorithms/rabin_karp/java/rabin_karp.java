import java.math.BigInteger;
import java.util.Random;
public class RabinKarp {
private long patHash;
    private int M;
    private long Q;
    private int R;
    private long RM;
    public RabinKarp(String pat)
    {
        M=pat.length();
        R=256;
        Q=longPrimeNumber();
        RM=1;
        for (int i=1;i<=M-1;i++)
        {
            RM=(R*RM)%Q;
        }
    }
    private long hash(String key,int M)
    {
        long h=0;
        for (int i=0;i<M;i++)
        {
            h=(R*h+key.charAt(i))%Q;
        }
        return h;
    }
    public int search(String txt)
    {
        int N=txt.length();
        long txtHash=hash(txt,M);
        for (int i=M;i<N;i++)
        {
            txtHash=(txtHash+Q-RM*txt.charAt(i-M)%Q)%Q;
            txtHash=(R*txtHash+txt.charAt(i))%Q;
            if (patHash==txtHash)
                return i+M-1;
        }
        return N;
    }
    private static long longPrimeNumber()
    {
        BigInteger prime=BigInteger.probablePrime(31,new Random());
        return prime.longValue();
    }

}
