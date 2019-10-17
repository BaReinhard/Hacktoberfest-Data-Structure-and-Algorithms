using System;

namespace QuickSort
{
    class QuickSort
    {
        static void Main(string[] args)
        {
            int[] array = { 3, 10, 7, 9, 1, 5, 8 };

            QuickSort qs = new QuickSort();
            qs.Sort(array, 0, array.Length - 1);

            foreach (var item in array)
            {
                Console.Write(item.ToString() + ",");
            }
        }

        void Sort(int[] arr, int low, int high)
        {
            if (low < high)
            {
                int index = Partition(arr, low, high);
                Sort(arr, low, index - 1);
                Sort(arr, index + 1, high);
            }
        }

        int Partition(int[] arr, int low, int high)
        {
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j < high; j++)
            {
                if (arr[j] <= pivot)
                {
                    i++;
                    int aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }

            int temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;

            return i + 1;
        }
    }
}
