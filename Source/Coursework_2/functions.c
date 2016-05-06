#include "functions.h"

void print_menu(int menu, int selected, struct ColorConfig* cfg)
{
	
	/* Main menu text */
	char mainMenu_1[] = "1. Mechandise management\n";
	char mainMenu_2[] = "2. Select color scheme\n";
	char mainMenu_3[] = "3. Exit\n";

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
			set_text_color(cfg->text_color | cfg->background_color, mainMenu_1);
		}
		else 
		{
			printf(mainMenu_1);
		}
		if (selected == 2)
		{
			set_text_color(cfg->text_color | cfg->background_color, mainMenu_2);
		}
		else
		{
			printf(mainMenu_2);
		}
		if (selected == 3)
		{
			set_text_color(cfg->text_color | cfg->background_color, mainMenu_3);
		}
		else
		{
			printf(mainMenu_3);
		}

	} // Main Menu
	else if (menu == MANAGE_MENU)
	{
		if (selected == 1)
		{
			set_text_color(cfg->text_color | cfg->background_color, manageMenu_1);
		}
		else
		{
			printf(manageMenu_1);
		}
		if (selected == 2)
		{
			set_text_color(cfg->text_color | cfg->background_color, manageMenu_2);
		}
		else
		{
			printf(manageMenu_2);
		}
		if (selected == 3)
		{
			set_text_color(cfg->text_color | cfg->background_color, manageMenu_3);
		}
		else
		{
			printf(manageMenu_3);
		}
		if (selected == 4)
		{
			set_text_color(cfg->text_color | cfg->background_color, manageMenu_4);
		}
		else
		{
			printf(manageMenu_4);
		}
		if (selected == 5)
		{
			set_text_color(cfg->text_color | cfg->background_color, manageMenu_5);
		}
		else
		{
			printf(manageMenu_5);
		}
		if (selected == 6)
		{
			set_text_color(cfg->text_color | cfg->background_color, manageMenu_6);
		}
		else
		{
			printf(manageMenu_6);
		}
		if (selected == 7)
		{
			set_text_color(cfg->text_color | cfg->background_color, manageMenu_7);
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
			set_text_color(cfg->text_color | cfg->background_color, colorMenu_1);
		}
		else
		{
			printf(colorMenu_1);
		}
		if (selected == 2)
		{
			set_text_color(cfg->text_color | cfg->background_color, colorMenu_2);
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

void set_text_color(WORD Color, char* text)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	GetConsoleScreenBufferInfo(h, &consoleInfo);
	wOldColorAttrs = consoleInfo.wAttributes;

	SetConsoleTextAttribute(h, Color);

	printf("%s", text);

	SetConsoleTextAttribute(h, wOldColorAttrs);
}

struct ColorConfig load_default_colors()
{
	// Default values:
	// Background Color: Red
	// Text Color: Yellow

	struct ColorConfig config;
	config.background_color = BACKGROUND_RED;
	config.text_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

	return config;
}

void load_custom_colors(struct ColorConfig* config, char* path)
{
	struct ColorConfig buffer;
	strcat(path, ".bin");
	FILE* fp = fopen(path, "r");

	if (fp != NULL)
	{
		fread(&buffer, sizeof(struct ColorConfig), 1, fp);

		config->background_color = buffer.background_color;
		config->text_color = buffer.text_color;

		fclose(fp);
	}
	else
	{
		*config = load_default_colors();
	}

	
}
