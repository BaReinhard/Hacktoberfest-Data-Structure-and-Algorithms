//Ibrahimmushtaq98
using System;

namespace BinarySearch{
    class Program{
        static void Main(string[] args){
            int[] arr = new int [] {3,5,7,11,12,14,15,17,19,20};
            int n = arr.Length;
            int x = 11;
            int elem = BinarySearch(arr,0, n-1, x);

            if(elem == -1){
                Console.WriteLine("Could Not Find Element");
            }else{
                Console.WriteLine("Elements found at " + elem);
            }
        }

        //This function will return the indexed value of x if x is in the array[l...r]
        static int BinarySearch(int[] arr, int l, int r, int x){

            if(arr.Length == 0){
                return -1;
            }

            if(r >= 1){
                int mid = l + (r-1)/2;
                //Checks if x is in the middle of the array
                if(arr[mid] == x){
                    return mid;

                //Checks if the element is smaller that mid, then it would be in the left subarray
                }else if(arr[mid] > x){
                    return BinarySearch(arr, l, mid -1 , x);

                //Else, the element is bigger that mid, then it would be in the right subarray
                }else{
                    return BinarySearch(arr, mid + 1, r, x);
                }
            }

            //The value x is not present in the array
            return -1;
        }
    }
}
