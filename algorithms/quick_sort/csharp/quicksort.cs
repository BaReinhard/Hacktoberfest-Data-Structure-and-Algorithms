using System;
using System.Collections.Generic;

/// <summary>
/// Class for QuickSort
/// </summary>
public class QuickSort
{
    /// <summary>
    /// Main Function
    /// </summary>
    /// <param name="args"></param>
    private static void Main(string[] args)
    {
        // array declaration
        var arr = new[] { 9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 6 };

        // printing original array
        Console.Write('\n');
        Console.WriteLine("Array before Sorting with Bubble Sort");
        foreach (var entry in arr)
        {
            Console.Write(entry + "   ");
        }

        // Sorting Array and printing the sorted array
        Qsort(arr, 0, arr.Length - 1);
        Console.Write('\n');
        Console.WriteLine("Array after Sorting with Bubble Sort");
        foreach (var entry in arr)
        {
            Console.Write(entry + "   ");
        }
        Console.Read();
    }

    /// <summary>
    /// Method for sorting an array
    /// </summary>
    /// <param name="list">Takes the array</param>
    /// <param name="left">Left key</param>
    /// <param name="right">Right Key</param>
    private static void Qsort(IList<int> list, int left, int right)
    {
        if (left >= right)
        {
            return;  // no sorting for array having either one or zero elements
        }

        var teiler = Partition(list, left, right);
        Qsort(list, left, teiler - 1);
        Qsort(list, teiler + 1, right);
    }

    private static int Partition(IList<int> list, int left, int right)
    {
        var i = left;
        var j = right - 1;
        var pivot = list[right];
        do
        {
            while (list[i] <= pivot && i < right)
            {
                i++;
            }
            while (list[j] >= pivot && j > left)
            {
                j--;
            }
            if (i < j)
            {
                Swap(list, i, j);
            }
        } while (i < j);
        if (list[i] > pivot)
        {
            Swap(list, i, right);
        }
        return i;
    }

    /// <summary>
    /// Swapping of two elements
    /// </summary>
    /// <param name="arr">Array to be swapped</param>
    /// <param name="i">i th index</param>
    /// <param name="j">j th index</param>
    private static void Swap(IList<int> arr, int i, int j)
    {
        var tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
