#include <stdio.h>
// linear search function
int linear(int a[], int n, int x){
  for(int i = 0; i < n; i++){
    // if element found return its position
    if(a[i] == x){
      return i + 1;
    }
  }
  // If element not in array
  return -1;
}
int main(){
  // Sample array
  int a[] = {1, 2, 5, 10, 7, 11, 8, 9, 22, 3};
  //Size of array
  int n = sizeof(a) / sizeof(a[0]);
  // Element to be searched
  int x = 7;
  // Return value after search
  int c = linear(a, n, x);
  if(c == -1)
    printf("Element not present in list");
  else
    printf("Element is at position %d", c);
  return 0;
}
