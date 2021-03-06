#pragma once
#include "declarations.h"

// Print menu
void print_menu(int menu, int selected, struct ColorConfig* cfg);

// Clear the console
void clear_cons();

// Get maximium options of menu layer
int get_max_options(int menuLayer);

// Helper to fix menu navigation for up arrow key
int fix_for_up(int selectedOp, int max);

// Helper to fix menu navigation for down arrow key
int fix_for_down(int selectedOp, int max);

// Set the text to a specific color
void set_text_color(WORD Color, char* text);

// Load default color set
struct ColorConfig load_default_colors();

// Load custom color set by file
void load_custom_colors(struct ColorConfig* config, char* path);

// Save value from the vector to database file on the disk
int save_to_disk(struct Vector* products);

// Check if id is unique number
int is_unique(int id, struct Vector* products);

// Creates new merchandise object by user input
struct Merchandise make_new_merchandise(struct Vector* list);

// Generates a new DateTime object by string
void get_time_by_string(struct DateTime* date, char* date_string);

// Gets new line input to clear the input stream
void get_empty_input();

// Prints all products
void print_all_values(struct Vector* merch_list);

// Prints specified amount of specified character on one line
void print_char(int count, char ch);

// Finds a product by id and prints it
void print_product_by_id(struct Vector* list, int id);

// Prints a single product
void print_single_product(struct Merchandise product);

// Finds all expired products and prints them
void print_all_expired_products(struct Vector* list);

// Has the products expired
int has_expired(struct Merchandise product);

// Copies DateTime struct to tm struct
void cpy_time(struct DateTime* time, struct tm* str_time);

// Gets total days in a month
int get_days_in_months(int months);

// Edit record by id
void edit_by_id(int id, struct Vector* list, struct Vector* temp);

// Find all producers and sorts them in descending order by total amount of product quantity
void sort_producers(struct Vector* list);

// Checks if target name exists in array
int check_if_exists(struct Producer * producers, int size, char * curr_name);

// Swaps two objects
void swap_producers(struct Producer * a, struct Producer * b);