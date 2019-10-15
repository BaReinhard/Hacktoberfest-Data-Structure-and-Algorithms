using System;

namespace BubbleSort
{
    class Program
    {
        static void Main(string[] args)
        {
            var random = new Random();
            int[] randomNumbers = new int[10];
            for (int i = 0; i < randomNumbers.Length; i++)
                randomNumbers[i] = random.Next(0, 20);

            Console.WriteLine("Current Array: {0}", string.Join(", ", randomNumbers));

            var sorted = randomNumbers.BubbleSort();
            Console.WriteLine("Bubble Sorted Array: {0}", string.Join(", ", sorted));
            Console.WriteLine("Hello World!");
        }
    }

    static class BubbleSortExtensions
    {
        public static T[] BubbleSort<T>(this T[] arr) where T : IComparable
        {
            int size = arr.Length;
            bool swapped = false;
            T temp;
            for (int i = 0; i < size - 1; i++)
            {
                swapped = false;
                for (int j = 0; j < size - 1 - i; j++)
                {
                    if (arr[j].CompareTo(arr[j + 1]) > 0)
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        swapped = true;
                    }
                }

                if (!swapped) break;
            }
            return arr;
        }
    }
}
