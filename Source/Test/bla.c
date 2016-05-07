#include <stdio.h>
#include "vector.h"
#include "merch.h"

int main()
{
	Vector tk;

	Merchandise product;

	//suzdavam nov obekt
	product.id = 1;
	strcpy(product.merch_name, "Nvidia GTX 960");
	product.price = 360.f;
	product.quantity = 25;
	//product.date_created = dt;
	product.expire_days = 100;
	strcpy(product.producer, "PALIT");
	strcpy(product.taxNumber, "253hdshad");

	vector_init(&tk);

	vector_append(&tk, &product);

	Merchandise merch = vector_get(&tk, 0);

	getch();
}