using System;
using System.Collections.Generic;

public class QuickSort {
    private static void Main(string[] args) { 
                  var arr = new[] {9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 6};

            Console.Write('\n');
            Console.WriteLine("Array before Sorting with Bubble Sort");
            foreach (var entry in arr) {
                Console.Write(entry + "   ");
            }
            QuickSort(arr, 0, arr.Length - 1);
            Console.Write('\n');
            Console.WriteLine("Array after Sorting with Bubble Sort");
            foreach (var entry in arr) {
                Console.Write(entry + "   ");
            }
            Console.Read();
        }

        private static void QuickSort(IList<int> list, int left, int right) {
            if (left >= right) {
                return;
            }
            var teiler = Partition(list, left, right);
            QuickSort(list, left, teiler - 1);
            QuickSort(list, teiler + 1, right);
        }

        private static int Partition(IList<int> list, int left, int right) {
            var i = left;
            var j = right - 1;
            var pivot = list[right];
            do {
                while (list[i] <= pivot && i < right) {
                    i++;
                }
                while (list[j] >= pivot && j > left) {
                    j--;
                }
                if (i < j) {
                    Swap(list, i, j);
                }
            } while (i < j);
            if (list[i] > pivot) {
                Swap(list, i, right);
            }
            return i;
        }


        private static void Swap(IList<int> arr, int i, int j) {
            var tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }