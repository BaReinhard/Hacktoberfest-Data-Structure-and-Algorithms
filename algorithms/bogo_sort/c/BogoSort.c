#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Checks if the array is sorted by comparing every consecutive pair
bool is_sorted(int *a, int n) {
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ){
      return false;
    }
  }
  return true;
}
 
//Shuffles array by swapping every element within the array with a random element
void shuffle(int *a, int n) {
  int i, temp, r;

  for(i=0; i < n; i++) {
    temp = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = temp;
  }
}
 
//Main bogosort function calls shuffle and checks if sorted by calling is_sorted
void bogosort(int *a, int n) {
  while ( !is_sorted(a, n) ){ 
    shuffle(a, n);
  }
}
 
int main() {
  int i, length;
  //Prompts user to enter num of elements and elements to initialize array.
  printf("Enter in number of elements:\n");
  scanf("%d", &length);
  int numbers[length];

  printf("Enter ");
  printf("%d", length);
  printf(" elements :\n");
  for (i=0; i<length; i++) {
    scanf("%d", &numbers[i]);
  }
 
  //Calls bogosort.
  bogosort(numbers, length);

  //Prints array.
  for (i=0; i < length; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  return 0;
}
