#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef struct DateTime {
	WORD year;
	WORD month;
	WORD day_of_week;
	WORD day;
	WORD hours;
	WORD minutes;
	WORD seconds;
	WORD milliseconds;
};


int main()
{
	struct DateTime a, b;
	GetSystemTime(&a);
	time_t start, end;

	struct tm str_time;

	str_time.tm_mday = a.day;



	getch();
	return 0;
}
