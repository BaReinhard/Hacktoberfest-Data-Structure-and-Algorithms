//algorithm of bubble sort in c
//start from the first elemnent 
/*1. start comparing it with the next element
  2. swap the element with the first smaller element it encounters.
  3. every traversal pushes the largest element towards the end.
*/
  



#include<stdio.h>
int main()
{
  int i, j, temp, size;
  printf("Enter size of array: ");
  scanf("%d", &size);
  int a[size];
  for(i = 0; i < size; i++) {
    scanf("%d", &a[i]);
  }
  for(i = 0; i < size; i++) {
    for(j = 1; j < size - i; j++) {
      if(a[i] < a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  for(i = 0; i < size; i++) {
    printf("%d", a[i]);
  }
}
