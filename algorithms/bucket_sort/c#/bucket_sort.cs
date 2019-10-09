using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace Sorting_Algorithms_In_C_Sharp
{
    public static class BucketSort
    {
        public static List<int> BucketSort1(params int[] x)
        {
            List<int> result = new List<int>();
 
            int numOfBuckets = 10;
 
            //Create buckets
            List<int>[] buckets = new List<int>[numOfBuckets];
            for (int i = 0; i < numOfBuckets; i++)
                buckets[i] = new List<int>();
 
            //Iterate through the passed array and add each integer to the appropriate bucket
            for (int i = 0; i < x.Length; i++)
            {
                int buckitChoice = (x[i] / numOfBuckets);
                buckets[buckitChoice].Add(x[i]);
            }
 
            //Sort each bucket and add it to the result List
            //Each sublist is sorted using Bubblesort, but you could substitute any sorting algo you would like
            for (int i = 0; i < numOfBuckets; i++)
            {
                int [] temp = BubbleSortList(buckets[i]);
                result.AddRange(temp);
            }
            return result;
        } 
    }
}