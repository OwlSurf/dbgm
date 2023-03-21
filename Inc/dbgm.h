#ifndef DBGM_H
#define DBGM_H
//For windows compiler
#define _CRT_SECURE_NO_WARNINGS
/**
 *	\file dbgm.h
 *	\author Roman Garanin owlsurf@mail.ru
 *
 *	(c) Roman Garanin, 2022
 *
 *	Abbreviations:
 *		dbgm - debug messages.	:wq		
 */


//You can define your print function here.
#ifndef PRINT
#define PRINT printf
#endif

#ifdef __cplusplus
extern "C" {
#endif
#include "stdio.h"
#include "stdint.h"

#define CLEAR_SCREEN        "\x1B[2J\x1b[1;1H"
#define COLOR_OFF           "\033[0m" 

		
#define GREEN_COLOR         "\033[0;32m"	

#define GREENOUT(format)       GREEN_COLOR format COLOR_OFF
#define BLUE_COLOR          "\033[0;34m"	
#define BLUEOUT(format)        BLUE_COLOR format COLOR_OFF
#define RED_COLOR           "\033[0;31m"	
#define REDOUT(format)         RED_COLOR format COLOR_OFF
#define YELLOW_COLOR        "\033[0;33m"
#define YELLOWOUT(format)      YELLOW_COLOR format COLOR_OFF
#define CYAN_COLOR          "\033[0;36m"	
#define CYANOUT(format)        CYAN_COLOR format COLOR_OFF
#define PURPLE_COLOR        "\033[0;35m"	
#define PURPLEOUT(format)      PURPLE_COLOR format COLOR_OFF

#ifdef DEBUG
#define DEBUG_PRINT(...) PRINT(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#define ERROR_PRINT(...) 	PRINT(REDOUT("Error: ") __VA_ARGS__)
#define LOG_PRINT(...)		PRINT(BLUEOUT("Log: ") CYAN_COLOR __VA_ARGS__);PRINT(COLOR_OFF)
#define WARNING_PRINT(...) 	PRINT(YELLOWOUT("Warning:") CYAN_COLOR __VA_ARGS__);PRINT(COLOR_OFF)

#ifdef DEBUG
void print_all_colors();
#endif

#ifdef __cplusplus
}
#endif
#endif
