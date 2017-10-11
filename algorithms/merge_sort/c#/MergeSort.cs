using System;

namespace MergeSort
{
    class MergeSort
    {
        static void Main(string[] args)
        {
            int[] array = { -2, 5, 3, 8, 9, 9, -8, 5, -4 };
            array = Sort(array);
            foreach (var item in array)
            {
                Console.Write("{0} ", item);
            }
        }

        static int[] Sort(int[] w)
        {
            if(w.Length <= 1)
            {
                return w;
            }
            else
            {
                int n = w.Length;
                int k = n / 2;
                int[] u = new int[k];
                int[] v = new int[n - k];
                for (int i = 0; i < k; i++)
                {
                    u[i] = w[i];
                }                    
                for (int i = k; i < n; i++)
                {
                    v[i - k] = w[i];
                }                   
                u = Sort(u);
                v = Sort(v);
                w = Merge(u, v);
                return w;
            }
        }

        static int[] Merge(int[] u, int[] v)
        {
            int n = u.Length + v.Length;
            int[] t = new int[n];
            int i = 0, j = 0;
            for (int k = 0; k < n; k++)
            {
                if(i < u.Length && (j >= v.Length || u[i] < v[j]))
                {
                    t[k] = u[i];
                    i++;
                }
                else
                {
                    t[k] = v[j];
                    j++;
                }
            }
            return t;
        }
    }
}
