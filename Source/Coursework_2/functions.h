#pragma once
#include "declarations.h"

// Print menu
void print_menu(int menu, int selected);

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