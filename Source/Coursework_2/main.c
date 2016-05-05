#include "declarations.h"

int main()
{
	//Should the program contninue the main loop
	int should_run = 1;

	//User input
	char option;

	//Currently selected row
	int selectedMenuOption = 1;

	// Current menu layer
	int menuLayer = 1;

	int text_rendered = 1;

	int maxOptions = get_max_options(menuLayer);

	while (should_run)
	{
		if (text_rendered)
		{
			if (menuLayer == MAIN_MENU)
			{
				print_menu(MAIN_MENU, selectedMenuOption);
				text_rendered = 0;
			}
			else if (menuLayer == MANAGE_MENU)
			{
				print_menu(MANAGE_MENU, selectedMenuOption);
				text_rendered = 0;
			}
			else if (menuLayer == COLOR_MENU)
			{
				print_menu(COLOR_MENU, selectedMenuOption);
				text_rendered = 0;
			}
		}

		if (kbhit() != 0)
		{
			text_rendered = 1;
			clear_cons();
			int key = GetKey();
			if (key == 72)//Key up
			{
				selectedMenuOption = fix_for_up(selectedMenuOption, maxOptions);
			}
			else if (key == 80) //key down
			{
				selectedMenuOption = fix_for_down(selectedMenuOption, maxOptions);
			}
			else if (key == 13) //Enter pressed
			{
				//If we are in the main menu, switch which menu to print!
				if (menuLayer == MAIN_MENU) 
				{
					if (selectedMenuOption == 1)
					{
						menuLayer = MANAGE_MENU;
						maxOptions = get_max_options(menuLayer);
						selectedMenuOption = 1;
					}
					else if (selectedMenuOption == 2)
					{
						menuLayer = COLOR_MENU;
						maxOptions = get_max_options(menuLayer);
						selectedMenuOption = 1;
					}
					else if (selectedMenuOption == 3)
					{
						should_run = 0;
					}
				}
				//If we are in the manage menu, call manage functions
				else if (menuLayer == MANAGE_MENU)
				{
					if (selectedMenuOption == 1)
					{
						printf("You wanted to add a new merchandise!\n");
						system("pause");
						clear_cons();
					}
					else if (selectedMenuOption == 2)
					{
						printf("You wanted to edit the merchandise!\n");
						system("pause");
						clear_cons();
					}
					else if (selectedMenuOption == 3)
					{
						printf("Here's a list of all expired merchandise!\n");
						system("pause");
						clear_cons();
					}
					else if (selectedMenuOption == 4)
					{
						printf("Here's a list of all producers!\n");
						system("pause");
						clear_cons();
					}
					else if (selectedMenuOption == 5)
					{
						printf("You wanted to find merchandise by id!\n");
						system("pause");
						clear_cons();
					}
					else if (selectedMenuOption == 6)
					{
						printf("Here's a list of all eligble merchandise!\n");
						system("pause");
						clear_cons();
					}
					else if (selectedMenuOption == 7)
					{
						menuLayer = MAIN_MENU;
						maxOptions = get_max_options(menuLayer);
						selectedMenuOption = 1;
					}
				}
				//If we are in the color menu, swap colors by file
				else if (menuLayer == COLOR_MENU)
				{
					if (selectedMenuOption == 1)
					{
						clear_cons();
						printf("Please enter file to select color scheme!\n");
						system("pause");
					}
					else if (selectedMenuOption == 2)
					{
						menuLayer = MAIN_MENU;
						maxOptions = get_max_options(menuLayer);
						selectedMenuOption = 1;
					}
				}
			}
		}

		//clear_cons();

	}

	return 0;
}
