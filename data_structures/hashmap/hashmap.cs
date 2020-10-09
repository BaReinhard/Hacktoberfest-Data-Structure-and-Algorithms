using System;
using System.Collections.Generic;

namespace hashmap
{
    class hashmap
    {
        static void Main(string[] args)
        {
            Dictionary<string, int> hm = new Dictionary<string, int>();

            hm.Add("one", 1);
            hm.Add("two", 2);
            hm.Add("three", 3);
            hm.Add("ONE", 1);
            hm.Add("four", 4);

            foreach (var item in hm.Keys)
            {
                Console.WriteLine(hm[item]);
            }
        }
    }
}
