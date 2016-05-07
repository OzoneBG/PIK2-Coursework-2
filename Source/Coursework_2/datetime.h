#pragma once
#include "declarations.h"

// Holder for the datetime
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
