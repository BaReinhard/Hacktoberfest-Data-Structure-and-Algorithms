#ifndef __GVECTOR_H
#define __GVECTOR_H


/** @defgroup GVector GVector
 * @{
 * Functions for the usage of a GVector - Generic Vector
 */

/**
 * Struct for Generic Vector Container
 */
struct gvector_t;
typedef struct gvector_t GVector;

/**
 * @brief Constructs a new GVector
 *
 * @param el_size Size, in bytes, of the type being stored in this instance of GVector
 *
 * @return Pointer to the the newly created GVector
 */
GVector * new_gvector(unsigned el_size);

 /**
  * @brief Deletes a GVector, freeing all the allocated memory
  *
  * @param ptr Pointer to the GVector to be deleted
  */
void delete_gvector(GVector * self);

/**
 * @brief Gets the size (number of elements) of a GVector
 *
 * @param self Pointer to the GVector
 *
 * @return The number of elements in the GVector
 */
unsigned gvector_get_size(GVector * self);

/**
 * @brief Access to an element at a given index
 *
 * @param self The GVector to access
 * @param idx The element's index
 *
 * @return Pointer to the element at index idx, must be cast to the appropriate type
 */
void * gvector_at(GVector * self, unsigned idx);

/**
 * @brief Pushes back a new element to the GVector.
 * Memory reallocation may happen.
 *
 * @param self The GVector to access
 * @param elem Pointer to the element to be copied
 *
 * @return Pointer to the newly added element
 */
void * gvector_push_back(GVector * self, void * elem);

/**
 * @brief Erases an element at a given index.
 * Memory reallocation may happen.
 *
 * @param self The GVector to access
 * @param idx The index of the element to be erased
 */
void gvector_erase(GVector * self, unsigned idx);

/**
 * @brief Erases the last element of GVector.
 * Memory reallocation may happen.
 *
 * @param self The GVector to access
 */
void gvector_pop_back(GVector * self);

/**
 * @brief Erases all elements of GVector.
 * Memory reallocation may happen.
 *
 * @param self The GVector to access
 */
void gvector_clear(GVector * self);

/**@}*/

#endif /* __GVECTOR_H */
