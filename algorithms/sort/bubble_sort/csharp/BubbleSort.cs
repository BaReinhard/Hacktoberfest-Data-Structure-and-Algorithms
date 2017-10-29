using System;
using System.Collections.Generic;


public class BubbleSort {
    private static void Main(string[] args) {
         Console.WriteLine("Input the elements of the array");
            var isNumber = true;
            var userInput = new List<int>();
            while (isNumber) {
                var input = Console.ReadLine();
                if (int.TryParse(input, out var temp )) {
                    userInput.Add(temp);
                } else {
                    isNumber = false;
                }
            }
            Console.Write('\n');
            Console.WriteLine("Array before Sorting with Bubble Sort");
            foreach (var entry in userInput) {
                Console.Write(entry + "   ");
            }
            BubbleSort(userInput);
            Console.Write('\n');
            Console.WriteLine("Array after Sorting with Bubble Sort");
            foreach (var entry in userInput) {
                Console.Write(entry + "   ");
            }
            Console.Read();
        }
        
        private static void BubbleSort(IList<int> list) {
            var n = list.Count;
            do {
                var newn = 1;
                for (var i = 0; i < n - 1; i++) {
                    if (list[i] <= list[i + 1]) {
                        continue;
                    }
                    var temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                    newn = i + 1;
                }
                n = newn;
            } while (n > 1);
        }
    }
