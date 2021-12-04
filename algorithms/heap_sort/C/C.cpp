void lerVet( int *p, int t ){

	int i;

	for ( i=0; i 0 ) {

          i--;
          t = a[i];

      }
      else {

          n--;
          if (n == 0)
             return;

          t = a[n];
          a[n] = a[0];

      }
     
      father = i;
      son = i*2 + 1;
 
      while (son < n) {

          if (( son + 1 < n )  &&  ( a[son + 1] > a[son] ))
              son++;

          if (a[son] > t) {

             a[father] = a[son];
             father = son;
             son = father*2 + 1;

          }
          else
             break;

      }
      a[father] = t;

   }
}


int main(){

	int *p, tam;

	printf("Number of elements in the vector? ");
	scanf("%d",&tam);

	p = (int*) malloc(tam * sizeof(int));
	
	printf("\nContent of the vector:\n");
	lerVet(p, tam);

	printf("\nContent for the vector:\n");
	mostrarVet(p, tam);

	printf("\nOrdering the vector...\n");
	heapSort(p, tam);

	printf("\nOrdered content of the vector:\n");
	mostrarVet(p, tam);

	free(p);

	return 0;

}
