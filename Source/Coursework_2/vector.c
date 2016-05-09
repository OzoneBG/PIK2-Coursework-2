#include "vector.h"

void vector_init(Vector* vector)
{
	vector->size = 0;
	vector->capacity = INITIAL_CAPACITY;

	vector->data = malloc(sizeof(struct Merchandise) * vector->capacity);
}

void vector_append(Vector* vector, struct Merchandise* value)
{
	vector_resize_if_full(vector);
	int index = vector->size++;
	vector->data[index] = *value;
}

struct Merchandise vector_get(Vector* vector, int index)
{
	if (index >= vector->size || index < 0)
	{
		printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
		exit(1);
	}

	return vector->data[index];
}

void vector_resize_if_full(Vector* vector)
{
	if (vector->size >= vector->capacity)
	{
		vector->capacity *= 2;
		vector->data = realloc(vector->data, sizeof(struct Merchandise) * vector->capacity);
	}
}

void vector_free(Vector* vector)
{
	free(vector->data);
}