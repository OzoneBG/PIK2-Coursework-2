#pragma once

typedef struct {

	// Unique identifier
	int id;

	// Merchandise name
	char merch_name[60];

	// Price of the merchandise
	float price;

	// Quantity of the merchandise
	unsigned short quantity;

	// In how many days does the merchandise expire
	int expire_days;

	// Producer name of the merchandise
	char producer[40];

	// Tax number 
	char taxNumber[10];
} Merchandise;
