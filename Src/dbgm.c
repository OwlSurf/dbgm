#include "dbgm.h"

#ifdef DEBUG
enum colors_e {
	GREEN, 
	BLUE, 
	RED,
	YELLOW, 
	CYAN,
	PURPLE, 
	COLOR_MAX
};
uint8_t color[COLOR_MAX][8] = {
        GREEN_COLOR,
        BLUE_COLOR,
        RED_COLOR,
	YELLOW_COLOR,
	CYAN_COLOR,
	PURPLE_COLOR
};

uint8_t color_name[COLOR_MAX][8] = {
	"Green",
	"Blue",
	"Red",
	"Yellow",
	"Cyan",
	"Purple"
};

void print_all_colors()
{
	for (uint16_t i = 0; i < COLOR_MAX; i++)
	{
		DEBUG_PRINT("Color: %s %s %s\r\n", color[i], color_name[i], COLOR_OFF);
	}
}
#endif
