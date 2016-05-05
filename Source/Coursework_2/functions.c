#include "functions.h"

void print_menu(int menu, int selected)
{
	
	/* Main menu text */
	char mainMenu_first[] = "1. Mechandise management\n";
	char mainMenu_second[] = "2. Select color scheme\n";
	char mainMenu_third[] = "3. Exit\n";

	/* Manage menu text */
	char manageMenu_1[] = "1. Add new merchandise\n";
	char manageMenu_2[] = "2. Edit merchandise\n";
	char manageMenu_3[] = "3. Expired merchandise\n";
	char manageMenu_4[] = "4. All producers\n";
	char manageMenu_5[] = "5. Find all by id\n";
	char manageMenu_6[] = "6. All eligable merchandise\n";
	char manageMenu_7[] = "7. Back\n";

	/* Select color scheme menu text */
	char colorMenu_1[] = "1. Select file\n";
	char colorMenu_2[] = "2. Back\n";

	if(menu == MAIN_MENU)
	{
		if (selected == 1)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, mainMenu_first);
		}
		else 
		{
			printf(mainMenu_first);
		}
		if (selected == 2)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, mainMenu_second);
		}
		else
		{
			printf(mainMenu_second);
		}
		if (selected == 3)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, mainMenu_third);
		}
		else
		{
			printf(mainMenu_third);
		}

	} // Main Menu
	else if (menu == MANAGE_MENU)
	{
		if (selected == 1)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, manageMenu_1);
		}
		else
		{
			printf(manageMenu_1);
		}
		if (selected == 2)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, manageMenu_2);
		}
		else
		{
			printf(manageMenu_2);
		}
		if (selected == 3)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, manageMenu_3);
		}
		else
		{
			printf(manageMenu_3);
		}
		if (selected == 4)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, manageMenu_4);
		}
		else
		{
			printf(manageMenu_4);
		}
		if (selected == 5)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, manageMenu_5);
		}
		else
		{
			printf(manageMenu_5);
		}
		if (selected == 6)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, manageMenu_6);
		}
		else
		{
			printf(manageMenu_6);
		}
		if (selected == 7)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, manageMenu_7);
		}
		else
		{
			printf(manageMenu_7);
		}
	}
	else if (menu == COLOR_MENU)
	{
		if (selected == 1)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, colorMenu_1);
		}
		else
		{
			printf(colorMenu_1);
		}
		if (selected == 2)
		{
			set_text_color(FOREGROUND_RED | BACKGROUND_BLUE, colorMenu_2);
		}
		else
		{
			printf(colorMenu_2);
		}
	}
}

void clear_cons()
{
	system(CLEAR_COMMAND);
}

int GetKey()
{
	int ch;
	ch = getch();
	if (ch == 0 || ch == 224) {
		ch = getch();
	}
	return ch;
}

int get_max_options(int menuLayer)
{
	int count = 0;
	if (menuLayer == MAIN_MENU)
	{
		count = 3;
	}
	else if(menuLayer == MANAGE_MENU)
	{
		count = 7;
	}
	else if (menuLayer == COLOR_MENU)
	{
		count = 2;
	}
	return count;
}

int fix_for_up(int selectedOp, int max)
{
	if (selectedOp == 1)
	{
		selectedOp = max;
	}
	else
	{
		selectedOp--;
	}

	return selectedOp;
}

int fix_for_down(int selectedOp, int max)
{
	if (selectedOp == max)
	{
		selectedOp = 1;
	}
	else
	{
		selectedOp++;
	}

	return selectedOp;
}