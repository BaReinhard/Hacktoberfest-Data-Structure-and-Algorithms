#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <heap.h>

HEAP *init(int d){
	HEAP *heap = (HEAP *) malloc(sizeof(HEAP));
	heap->d = d;
	heap->size = 0;
	heap->items = NULL;

	return heap;
}

int parent_index(int n, int d){
	return (n-1)/d;
}

int child_index(int n, int d, int i){
	return n*d+i+1;
}

void push(HEAP *heap, int value){
	int i;

	heap->size++;
	heap->items = (int *) realloc(heap->items, sizeof(int)*heap->size);
	i = heap->size - 1;
	heap->items[i] = 0;

	while(i >= 1 && heap->items[parent_index(i, heap->d)] > value){
		heap->items[i] = heap->items[parent_index(i, heap->d)];
		i = parent_index(i, heap->d);
	}
	heap->items[i] = value;
}

void min_heapify(int n, HEAP *heap){
	int i, current, aux, smallest;

	smallest = n;
	for(i = 0; i < heap->d; i++){
		current = child_index(n, heap->d, i);
		if(current <= heap->size  && heap->items[current] < heap->items[smallest]){
			smallest = current;
		}
	}
	if(smallest != n){
		aux = heap->items[n];
		heap->items[n] = heap->items[smallest];
		heap->items[smallest] = aux;
		min_heapify(smallest, heap);
	}
}

int pop(HEAP *heap){
	int removed;

	if(heap->size == 0)
		return -1;
	else{
		removed = heap->items[0];
		heap->items[0] = heap->items[heap->size -1];
		heap->size--;
		min_heapify(0, heap);
		return removed;
	}
}

void short_print(HEAP *heap){
	int i;

	for(i = 0; i < heap->size; i++){
		printf("%d ", heap->items[i]);
	}
}

void print(HEAP *heap){
	int i, j;

	printf("size = %d\n", heap->size);
	for(i = 0; i < heap->size; i++){
		printf("Index = %d Elemento = %d\n", i, heap->items[i]);
		printf("Pai = %d\n", parent_index(i, heap->d));
		for(j = 0; j < heap->d; j++){
			printf("Filho %d = %d\n", j+1, child_index(i, heap->d, j));
		}
		printf("\n");
	}
	printf("\n\n");
}

void destroy(HEAP *heap){
	if(heap->items != NULL){
		free(heap->items);
	}
	free(heap);
}
