#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "GVector.h"


struct gvector_t {
    unsigned size;              // number of elements in generic vector
    unsigned el_size;           // size of each element, in bytes
    unsigned capacity;          // Capacity of vector, larger than size to prevent continuous reallocs
    unsigned increments;        // Capacity increments/decrements on realloc

    void * array;
};

GVector * new_gvector(unsigned el_size) {

    if (0 == el_size)
        return NULL;

    GVector * self = (GVector *) malloc(sizeof(GVector));
    if (NULL == self)
        return NULL;

    self->size = 0;
    self->increments = 10;
    self->capacity = self->increments;
    self->el_size = el_size;

    self->array = malloc(self->capacity * self->el_size);

    return self;
}

void delete_gvector(GVector * self) {
    free(self->array);
    free(self);
}

unsigned gvector_get_size(GVector * self) {
    return self->size;
}

// Private Method
static void gvector_check_capacity(GVector * self) {
    if ( (self->capacity - self->size) > self->increments ) {
        self->capacity -= self->increments;
        self->array = realloc(self->array, self->capacity * self->el_size);
    } else if ( self->capacity == self->size ) {
        self->capacity += self->increments;
        self->array = realloc(self->array, self->capacity * self->el_size);
    }
}


// Returns void pointer, result must be cast to proper type
void * gvector_at(GVector * self, unsigned index) {
    return index < self->size ? self->array + index * self->el_size : NULL;
}


void * gvector_push_back(GVector * self, void * elem) {
    gvector_check_capacity(self);
    memcpy(self->array + self->el_size * self->size++, elem, self->el_size);

    return gvector_at(self, self->size - 1);
}

void gvector_pop_back(GVector * self) {
    if (0 == self->size) {
    	printf("GVector::pop_back tried to pop empty vector\n");
    	return;
    } else {
    	--(self->size);
    	gvector_check_capacity(self);
	}
}

void gvector_erase(GVector * self, unsigned index) {
	if (self->size <= index) {
		printf("GVector::erase tried to erase out_of_range index\n");
		return;
	}

	--(self->size);
	memmove(self->array + index * self->el_size, self->array + (index + 1) * self->el_size, (self->size - index) * self->el_size);

	gvector_check_capacity(self);
}

void gvector_clear(GVector * self) {
    self->size = 0;

    gvector_check_capacity(self);
}



