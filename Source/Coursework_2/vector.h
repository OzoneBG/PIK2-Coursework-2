#pragma once
#include "declarations.h"

#define INITIAL_CAPACITY 16

// Vector - dynamic array
// Hardcoded to work only with Merchandise type
typedef struct {

	// Slots used
	int size;

	// Total available slots
	int capacity;

	// Array of data to store merchandise
	struct Merchandise* data;
} Vector;

// Initialise a new vector
void vector_init(Vector* vector);

// Append new element to the vector
void vector_append(Vector* vector, struct Merchandise* value);

// Get element from the vector by index
struct Merchandise vector_get(Vector* vector, int index);

// Set element to the vector by index
void vector_set(Vector* vector, int index, struct Merchandise* value);

// Resize the vector if it's full
void vector_resize_if_full(Vector* vector);

// Free the vector array
void vector_free(Vector* free);