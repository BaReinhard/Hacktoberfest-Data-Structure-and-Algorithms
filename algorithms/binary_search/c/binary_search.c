#include <stdio.h>

int binarySearch(int arr[], int l, int r, int key) {
  if (r >= l) {
       int mid = l + (r - l)/2;

       // If the element is present at the middle
       if (arr[mid] == key)  return mid;

       // If element is smaller than mid, then it can only be present in left subarray
       else if (arr[mid] > key) return binarySearch(arr, l, mid-1, key);

       // Else the element can only be present in right subarray
       return binarySearch(arr, mid+1, r, key);
  }
  // When element is not present in array
  return -1;
}

int main(void) {
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr)/ sizeof(arr[0]);
  int key = 10;
  int result = binarySearch(arr, 0, n-1, key);
  (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);
  return 0;
}