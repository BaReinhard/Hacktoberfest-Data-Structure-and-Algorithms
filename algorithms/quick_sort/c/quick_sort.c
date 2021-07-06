#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

bool array_is_valid(int *a, unsigned int length) {
    return ((length == 0 && a == NULL) || (length != 0 && a != NULL));
}

bool array_is_sorted(int *a, unsigned int length) {
  bool sorted = true;
  unsigned int i = 0;
  while( (i+1) < length && sorted){
    if(a[i] > a[i+1]){
      sorted = false;
      break;
    }
    i++;
  }
  return sorted;
}

void swap(int *a, unsigned int i, unsigned int j) {
  unsigned int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
  return;
}

int pivot(int *a, int izq, int der){
  int piv, i, j;
  piv = izq;
  i = izq + 1;
  j = der;

  while ( i <= j) {
    if ( a[i] <= a[piv]) {
      i++;
    } else if (a[j] > a[piv]) {
      j--;
    } else if (a[i] > a[piv] && a[j] <= a[piv]){
      swap(a,i,j);
      i++;
      j--;
    }
  }
  swap(a,piv,j);
  piv = j;
  return (piv);
}

void quick_sort_rec(int *a, int izq, int der){
    int piv;

    if ( der > izq) {
      piv = pivot(a,izq,der);
      quick_sort_rec(a,izq,piv-1);
      quick_sort_rec(a,piv+1,der);
    }
    return;
}


void quick_sort(int *a, unsigned int length) {

    quick_sort_rec(a,0,length-1);
    /* Check postconditions */
    assert(array_is_sorted(a, length));
}

void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
