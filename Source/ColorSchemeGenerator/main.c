#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "colors.h"

//Set color by id
int set_color_by_int(int number, char mode);

//prints colors to let user select
void print_colors();

typedef struct ColorConfig {
	int background_color;
	int text_color;
};

int main()
{
	struct ColorConfig config;

	//Ask the user for color configuration
	print_colors();
	
	int bgcolor;
	printf("Select color for background: "); scanf("%d", &bgcolor);
	config.background_color = set_color_bg(bgcolor);
	int tcolor;
	printf("Select color for text: "); scanf("%d", &tcolor);
	config.text_color = set_color_text(tcolor);

	char* filename[100];
	printf("Please specify filename (only name): "); scanf("%s", filename);

	strcat(filename, ".bin");
	FILE* fp = fopen(filename, "w");

	if (fp != NULL)
	{
		fwrite(&config, sizeof(struct ColorConfig), 1, fp);
	}
	else
	{
		printf("Failed to open!\n");
	}

	fclose(fp);

	return 0;
}

int set_color_text(int number)
{
	int color = 0;

	switch (number)
	{
	case 1:
		color = TBLACK;
		break;
	case 2:
		color = TDARKBLUE;
		break;
	case 3:
		color = TDARKGREEN;
		break;
	case 4:
		color = TDARKCYAN;
		break;
	case 5:
		color = TDARKRED;
		break;
	case 6:
		color = TDARKMAGENTA;
		break;
	case 7:
		color = TDARKYELLOW;
		break;
	case 8:
		color = TDARKGRAY;
		break;
	case 9:
		color = TGRAY;
		break;
	case 10:
		color = TBLUE;
		break;
	case 11:
		color = TGREEN;
		break;
	case 12:
		color = TCYAN;
		break;
	case 13:
		color = TRED;
		break;
	case 14:
		color = TMAGENTA;
		break;
	case 15:
		color = TYELLOW;
		break;
	case 16:
		color = TWHITE;
		break;
	}

	return color;
}

int set_color_bg(int number)
{
	//Default black
	int color = 0;

		switch(number)
		{
			case 1:
				color = BGBLACK;
				break;
			case 2:
				color = BGDARKBLUE;
				break;
			case 3:
				color = BGDARKGREEN;
				break;
			case 4:
				color = BGDARKCYAN;
				break;
			case 5:
				color = BGDARKRED;
				break;
			case 6:
				color = BGDARKMAGENTA;
				break;
			case 7:
				color = BGDARKYELLOW;
				break;
			case 8:
				color = BGDARKGRAY;
				break;
			case 9:
				color = BGGRAY;
				break;
			case 10:
				color = BGBLUE;
				break;
			case 11:
				color = BGGREEN;
				break;
			case 12:
				color = BGCYAN;
				break;
			case 13:
				color = BGRED;
				break;
			case 14:
				color = BGMAGENTA;
				break;
			case 15:
				color = BGYELLOW;
				break;
			case 16:
				color = BGWHITE;
				break;
		}	

		return color;
}

void print_colors()
{
	printf("1. Black\n");
	printf("2. Dark Blue\n");
	printf("3. Dark Green\n");
	printf("4. Dark Cyan\n");
	printf("5. Dark Red\n");
	printf("6. Dark Magenta\n");
	printf("7. Dark Yellow\n");
	printf("8. Dark Gray\n");
	printf("9. Gray\n");
	printf("10. Blue\n");
	printf("11. Green\n");
	printf("12. Cyan\n");
	printf("13. Red\n");
	printf("14. Magenta\n");
	printf("15. Yellow\n");
	printf("16. White\n");
}