#include "vector.h"
#include "stdio.h"
#include "merch.h"

void vector_init(Vector* vector)
{
	vector->size = 0;
	vector->capacity = INITIAL_CAPACITY;

	vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector_append(Vector* vector, int value)
{
	vector_resize_if_full(vector);
	int index = vector->size++;
	vector->data[index] = value;
	/*vector->data[index].id = value->id;
	strcpy(vector->data[index].merch_name, value->merch_name);
	vector->data[index].price = value->price;
	vector->data[index].quantity = value->quantity;
	vector->data[index].expire_days = value->expire_days;
	strcpy(vector->data[index].producer, value->producer);
	strcpy(vector->data[index].taxNumber, value->taxNumber);*/
}

int vector_get(Vector* vector, int index)
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
		vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
	}
}

void vector_free(Vector* vector)
{
	free(vector->data);
}