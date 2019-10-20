using System;

public class binary_search
{
    public binary_search()
    {
        int[] a = { 45, 64, 68, 46, 70, 6, 46, 4, 6, 48 };

        int[] BubbleSort(int[] array)
        {
            bool sorted = false;
            while (!sorted)
            {
                for (int x = 0; x < array.Count() - 1; x++)
                {
                    if (array[x] > array[x + 1])
                    {
                        int temp = a[x];
                        array[x] = array[x + 1];
                        a[x + 1] = temp;
                    }
                }
                int last = array[0];
                foreach (int item in array)
                {
                    if (item >= last)
                        sorted = true;
                    else
                    {
                        sorted = false;
                        break;
                    }
                }
            }
            return array;
        }

        bool BinarySearch(int[] array, int Target)
        {
            BubbleSort(array);
            int start = 0, end = array.Count() - 1, middle = end / 2;
            while (start <= end)
            {
                if (Target == array[middle])
                    return true;
                if (Target < array[middle])
                {
                    end = middle - 1;
                    middle = end / 2;
                }
                if (Target > array[middle])
                {
                    start = middle + 1;
                    middle = (end + start) / 2;
                }
            }
            return false;
        }
    }
}
