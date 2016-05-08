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

int save_to_disk(Vector * products)
{
	int success = 0;

	FILE* db = fopen("database.bin", "w");

	if (db != NULL)
	{
		if (products->size > 0)
		{
			int count = 0;
			while (count < products->size)
			{
				fwrite(&products->data[count], sizeof(struct Merchandise), 1, db);
				count++;
			}

			success = 1;
		}
		
	}

	fclose(db);

	return success;
}

int is_unique(int id, Vector * products)
{
	int is_found = 0;

	int i;
	for (i = 0; i < products->size; i++)
	{
		if (products->data[i].id == id)
		{
			is_found = 1;
		}
	}

	return is_found;
}

struct Merchandise make_new_merchandise(struct Vector* list)
{
	struct Merchandise product;

	int id;
	int found = 0;
	do
	{
		if (found)
		{
			printf("The id already exists. Set new ");
		}

		printf("Id: "); scanf("%d", &id);
		found = is_unique(id, list);
	} while (found);

	product.id = id;

	char product_name[100];
	int bigger = 0;
	do 
	{
		if (bigger)
		{
			printf("Name must be less than 60 symbols.\n");
		}

		printf("Set merchandise name [60 symbols]: "); scanf("%s", &product_name);

		if (strlen(product_name) > 60)
		{
			bigger = 1;
		}

	} while (bigger);

	strcpy(product.merch_name, product_name);

	get_empty_input();

	float price;
	printf("Set price: "); scanf("%f", &price);

	product.price = price;

	unsigned short quantity;
	printf("Set quantity: "); scanf("%hu", &quantity);
	product.quantity = quantity;

	char date_string[100];
	printf("Set date in format dd:MM:yyyy:hh:mm:ss or \"now\" for current time:\n ");
	scanf("%s", &date_string);

	struct DateTime date_created;

	if (date_string == "now")
	{
		GetSystemTime(&date_created);
	}
	else
	{
		get_time_by_string(&date_created, &date_string);
	}

	product.date_created = date_created;

	int expire_days;
	printf("In how many days does it expire: "); scanf("%d", &expire_days);
	product.expire_days = expire_days;

	char producer[100];
	bigger = 0;
	do
	{
		if (bigger)
		{
			printf("Name must be less than 40 symbols.\n");
		}

		printf("Set producer name [40 symbols]: "); scanf("%s", &producer);

		if (strlen(producer) > 40)
		{
			bigger = 1;
		}

	} while (bigger);

	strcpy(product.producer, producer);

	get_empty_input();

	char tax[100];
	bigger = 0;
	do
	{
		if (bigger)
		{
			printf("Tax number must be less than 11 symbols.\n");
		}

		printf("Set tax number [10 symbols]: "); scanf("%s", &tax);

		if (strlen(tax) > 60)
		{
			bigger = 1;
		}

	} while (bigger);

	strcpy(product.taxNumber, tax);

	get_empty_input();

	return product;
}

void get_time_by_string(struct DateTime * date, char * date_string)
{
	//Format dd:MM:yyyy:hh::mm:ss
	
	
	struct DateTime now;
	GetSystemTime(&now);

	int count = 0;
	while (count != 5)
	{
		char* current;
		current = strtok(date_string, ":");

		if (count == 0) // Day
		{
			if (current != NULL)
			{
				int day = atoi(current);
				if (day <= 31)
				{
					date->day = day;
				}
				else
				{
					exit(1);
				}
			}
			else
			{
				date->day = now.day;
			}
		}
		else if (count == 1) // Month
		{
			if (current != NULL)
			{
				int month = atoi(current);
				if (month <= 12)
				{
					month--;
					date->month = month;
				}
				else
				{
					exit(1);
				}
			}
			else
			{
				date->month = now.month;
			}
		}
		else if (count == 2) // Year
		{
			if (current != NULL)
			{
				int year = atoi(current);
				if (year <= 2100)
				{
					date->year = year;
				}
				else
				{
					exit(1);
				}
			}
			else
			{
				date->year = now.year;
			}
		}
		else if (count == 3) // Hours
		{
			if (current != NULL)
			{
				int hour = atoi(current);
				if (hour <= 12)
				{
					date->hours = hour;
				}
				else
				{
					exit(1);
				}
			}
			else
			{
				date->hours = now.hours;
			}
		}
		else if (count == 4) // Minutes
		{
			if (current != NULL)
			{
				int mins = atoi(current);
				if (mins < 60)
				{
					date->minutes = mins;
				}
				else
				{
					exit(1);
				}
			}
			else
			{
				date->minutes = now.minutes;
			}
		}
		else if (count == 5) // Seconds
		{
			if (current != NULL)
			{
				int secs = atoi(current);
				if (secs < 59)
				{
					date->seconds = secs;
				}
				else
				{
					exit(1);
				}
			}
			else
			{
				date->seconds = now.seconds;
			}
		}

		count++;
	}
}

void get_empty_input()
{
	while (getchar() != '\n');
}

void print_all_values(Vector * merch_list)
{
	if (merch_list->size > 0)
	{
		int i;
		for (i = 0; i < merch_list->size; i++)
		{
			struct Merchandise product = merch_list->data[i];

			printf("Id: %d\nMerchandise name: %s\nPrice: %f\n", product.id, product.merch_name, product.price);
			printf("Quantity: %hu\nExpires in: %d days\nProducer: %s\n", product.quantity, product.expire_days, product.producer);
			printf("Tax number: %s\n", product.taxNumber);

			print_char(25, '-');
		}
	}
}

void print_char(int count, char ch)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%c", ch);
	}
	printf("\n");
}

void print_product_by_id(Vector* list, int id)
{
	if (list->size > 0)
	{
		int i;
		for (i = 0; i < list->size; i++)
		{
			if (list->data[i].id == id)
			{
				print_single_product(list->data[i]);
				break;
			}
		}
	}
}

void print_single_product(struct Merchandise product)
{
	printf("Id: %d\nMerchandise name: %s\nPrice: %f\n", product.id, product.merch_name, product.price);
	printf("Quantity: %hu\nExpires in: %d days\nProducer: %s\n", product.quantity, product.expire_days, product.producer);
	printf("Tax number: %s\n", product.taxNumber);

	print_char(25, '-');
}

void print_all_expired_products(Vector * list)
{
	if (list->size > 0)
	{
		int i;
		for (i = 0; i < list->size; i++)
		{
			struct Merchandise product = list->data[i];
			if (has_expired(product))
			{

				printf("Id: %d\nMerchandise name: %s\nPrice: %f\n", product.id, product.merch_name, product.price);
				printf("Quantity: %hu\nExpires in: %d days\nProducer: %s\n", product.quantity, product.expire_days, product.producer);
				printf("Tax number: %s\n", product.taxNumber);

				print_char(25, '-');
			}
		}
	}
}

int has_expired(struct Merchandise product)
{
	int has_expr = 0;

	struct DateTime now;
	GetSystemTime(&now);

	int years = now.year - product.date_created.year;
	int months = now.month - product.date_created.month;
	int days = now.day - product.date_created.day;

	int totalDays = 365 * years;

	if (months > 0)
	{
		totalDays += get_days_in_months(months);
	}
	else
	{
		totalDays -= get_days_in_months(months);
	}

	if (days > 0)
	{
		totalDays += days;
	}
	else
	{
		totalDays -= days;
	}

	if (totalDays > product.expire_days)
	{
		has_expr = 1;
	}

	return has_expr;
}

void cpy_time(struct DateTime * time, struct tm * str_time)
{
	str_time->tm_mday = time->day;
	str_time->tm_mon = time->month;
	str_time->tm_year = time->year;
	str_time->tm_hour = time->year;
	str_time->tm_min = time->minutes;
	str_time->tm_sec = time->seconds;
}

int get_days_in_months(int months)
{
	int days = 0;
	int i;
	for (i = 0; i < months; i++)
	{
		if (i % 2 == 0)
		{
			days += 30;
		}
		else
		{
			days += 31;
		}
	}

	return days;
}

void edit_by_id(int id, Vector * list)
{
	//TO DO
	// fix

	/*if (list->size > 0)
	{
		int i = 0;
		for (i; i < list->size; i++)
		{
			if (list->data[i].id == id)
			{
				// found match
				// print quantity
				printf("Current quantity of %s is %d\n", list->data[i].merch_name, list->data[i].quantity);

				// ask for quantity
				int choice;
				printf("Do you want to add or remove quantity 1 or 2: "); scanf("%d", &choice);

				unsigned short new_quantity;
				printf("New quantity: "); scanf("%hu", &new_quantity);

				int can_modify = 0;

				// do chec
				if (choice == 1) // we want to add
				{
					unsigned short old_quantity = list->data[i].quantity;
					list->data[i].quantity = new_quantity + old_quantity;
					break;
				}
				else if (choice == 2) // we want to substract
				{
					while (new_quantity > list->data[i].quantity)
					{
						printf("New quantity: "); scanf("%hu", &new_quantity);

						if (new_quantity > list->data[i].quantity)
						{
							printf("You can't remove more than there is!\n");
						}
						else if (new_quantity == 0)
						{
							//TO DO
							//Remove from file
							printf("Removing from file\n");
						}
						else
						{
							can_modify = 1;
						}
					}

					if (can_modify)
					{
						unsigned short old_quantity = list->data[i].quantity;
						list->data[i].quantity = old_quantity - new_quantity;
						break;
					}
				}
			}
		}
	}*/
}
