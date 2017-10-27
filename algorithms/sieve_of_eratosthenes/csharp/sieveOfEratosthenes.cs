using System;

public class SieveOfEratosthenes
{
    private bool[] arr;

    public SieveOfEratosthenes(int max)
    {
        arr = new bool[max+1];
        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = true;
        }
    }

    public void sieve()
    {
        for (int i = 2; i * i <= arr.Length; i++)
        {
            if (arr[i])
            {
                for (int j = i * 2; j <= arr.Length; j += i)
                {
                    arr[j] = false;
                }
            }
        }
    }

    public bool[] getSieve()
    {
        return this.arr;
    }


    static void Main(string[] args)
    {
        Console.WriteLine("Please type in the number up to which you want to know the prime numbers:");
        int max = Int32.Parse(Console.ReadLine());
        SieveOfEratosthenes sieve = new SieveOfEratosthenes(max);
        sieve.sieve();
        bool[] arr = sieve.getSieve();
        for (int i = 2; i < max; i++)
        {
            if (arr[i])
            {
                Console.WriteLine($"Prime: { i.ToString() }");
            }
        }
    }
}
