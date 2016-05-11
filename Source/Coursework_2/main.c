#include "declarations.h"

int main()
{
	//Should the program contninue the main loop
	int should_run = 1;

	//Currently selected row
	int selectedMenuOption = 1;

	// Current menu layer
	int menuLayer = 1;

	// Was the text actually rendered
	int text_rendered = 1;

	// Current color configuration
	struct ColorConfig colorconf;

	// Open database file, ready for reading and writing operations
	//FILE* db_read = fopen("database.bin", "r");
	//FILE* db_write = fopen("database.bin", "w");

	// Create an empty vector to keep record of all merchandise read from the database
	Vector merch_list;

	vector_init(&merch_list);


	//printf("Size: %d and Capacity: %d\n", merch_list.size, merch_list.capacity);

	// Get user input for color scheme file
	printf("Welcome to the warehouse manager program!\n");

	read_all_merchandise(&merch_list);

	printf("Do you want to load a color scheme file? Y/N\n");
	char ch;
	scanf("%c", &ch);
	if (ch == 'y' || ch == 'Y')
	{
		printf("Please specify filename (only filename): ");
		char* path[100];
		scanf("%s", path);
		load_custom_colors(&colorconf, path);
		clear_cons();
	}
	else
	{
		clear_cons();
		colorconf = load_default_colors();
	}
	
	int maxOptions = get_max_options(menuLayer);

	while (should_run)
	{
		if (text_rendered)
		{
			if (menuLayer == MAIN_MENU)
			{
				print_menu(MAIN_MENU, selectedMenuOption, &colorconf);
				text_rendered = 0;
			}
			else if (menuLayer == MANAGE_MENU)
			{
				print_menu(MANAGE_MENU, selectedMenuOption, &colorconf);
				text_rendered = 0;
			}
			else if (menuLayer == COLOR_MENU)
			{
				print_menu(COLOR_MENU, selectedMenuOption, &colorconf);
				text_rendered = 0;
			}

			printf("Keeping track of %d records..\n", merch_list.size);
		}

		if (kbhit() != 0)
		{
			text_rendered = 1;
			clear_cons();
			int key = getch();

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
						remove("database.bin");
						save_to_disk(&merch_list);
					}
				}
				//If we are in the manage menu, call manage functions
				else if (menuLayer == MANAGE_MENU)
				{
					if (selectedMenuOption == 1)
					{
						printf("Adding new merchandise\n\n");
						
						struct Merchandise product;

						//Create new basic object
						product.id = 13;
						strcpy(product.merch_name, "dsadas");
						product.price = 1200.f;
						product.quantity = 5;
						struct DateTime dt;
						GetSystemTime(&dt);
						//dt.day = 2;
						product.date_created = dt;
						product.expire_days = 5;
						strcpy(product.producer, "ASEM");
						strcpy(product.taxNumber, "asemp");


						/* Uncomment to let user create products */
						//product = make_new_merchandise(&merch_list);

						//printf("Id: %d\nMerchandise name: %s\nPrice: %f\n", product.id, product.merch_name, product.price);
						//printf("Quantity: %hu\nExpires in: %d days\nProducer: %s\n", product.quantity, product.expire_days, product.producer);
						//printf("Tax number: %s\n", product.taxNumber);

						vector_append(&merch_list, &product);

						system("pause");;
						clear_cons();
					}
					else if (selectedMenuOption == 2)
					{
						printf("You wanted to edit the merchandise!\n");

						int id;
						printf("Select id: "); scanf("%d", &id);

						Vector temp;
						vector_init(&temp);
						edit_by_id(id, &merch_list, &temp);

						if (temp.size > 0)
						{
							vector_free(&merch_list);
							vector_init(&merch_list);

							int i;
							for (i = 0; i < temp.size; i++)
							{
								struct Merchandise tmp = vector_get(&temp, i);
								vector_append(&merch_list, &tmp);
							}
						}

						system("pause");;
						clear_cons();
					}
					else if (selectedMenuOption == 3)
					{
						printf("Here's a list of all expired merchandise!\n");

						print_all_expired_products(&merch_list);

						system("pause");
						clear_cons();
					}
					else if (selectedMenuOption == 4)
					{
						printf("Here's a list of all producers!\n");
						sort_producers(&merch_list);
						system("pause");;
						clear_cons();
					}
					else if (selectedMenuOption == 5)
					{
						printf("You wanted to find merchandise by id!\n");

						int id;
						printf("Id: "); scanf("%d", &id);
						print_product_by_id(&merch_list, id);

						system("pause");;
						clear_cons();
					}
					else if (selectedMenuOption == 6)
					{
						printf("Here's a list of all eligble merchandise!\n");

						print_all_values(&merch_list);

						system("pause");;
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
						printf("Please specify filename (only filename): ");
						char* path[100];
						scanf("%s", path);
						load_custom_colors(&colorconf, path);
						system("pause");;
						clear_cons();
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
	}

	return 0;
}
