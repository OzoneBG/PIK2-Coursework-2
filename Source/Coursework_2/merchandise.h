#pragma once
#include "declarations.h"

// Merchandise model
typedef struct Merchandise {

	// Unique identifier
	int id;

	// Merchandise name
	char merch_name[60];

	// Price of the merchandise
	float price;

	// Quantity of the merchandise
	unsigned short quantity;

	// Date when merchandise was created
	struct DateTime date_created;

	// In how many days does the merchandise expire
	int expire_days;

	// Producer name of the merchandise
	char producer[40];

	// Tax number 
	char taxNumber[10];
};

// Read all merchandise from a database file
void read_all_merchandise(FILE* db, struct Vector* vec);
