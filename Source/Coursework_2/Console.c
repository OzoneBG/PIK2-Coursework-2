#include "console.h"

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



