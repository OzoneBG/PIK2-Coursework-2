#pragma once

/* Defined so Visual Studio doesn't pop up security warnings */
#define _CRT_SECURE_NO_WARNINGS

// System headers
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Project headers
#include "functions.h"
#include "colorconfig.h"
#include "datetime.h"
#include "merchandise.h"
#include "vector.h"
#include "producer.h"

#define WIN_TERMINAL
#ifdef WIN_TERMINAL
#define CLEAR_COMMAND "cls"
#endif
#ifdef UNIX_TERMINAL
#define CLEAR_COMMAND "clear";
#endif

#define MAIN_MENU 1
#define MANAGE_MENU 2
#define COLOR_MENU 3


