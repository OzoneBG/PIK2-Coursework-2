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
//int save_to_disk(struct Vector* products, FILE* db);
