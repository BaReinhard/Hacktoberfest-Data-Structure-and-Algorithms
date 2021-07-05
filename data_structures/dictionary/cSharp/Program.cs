using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<string, int> myDictionary = new Dictionary<string, int>();
            myDictionary.Add("one", 1);
            myDictionary.Add("twenty", 20);

            Dictionary<int, Dictionary<string, int>> nestedDictionary = new Dictionary<int, Dictionary<string, int>>();
            List<string> keyList = new List<string>(myDictionary.Keys);
            for (int i = 0; i < keyList.Count; i++)
            {
                int myInt = myDictionary[keyList[i]];
                Console.WriteLine(myInt.ToString());

            }
            Console.Read();
        }
    }
}
