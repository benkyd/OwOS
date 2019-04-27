#include "logger.h"

#include <kernel/drivers/terminal/terminal.h>

void loggerLog(char* str) {
    write("         ");
    writeln(str);
}

void loggerOK(char* str) {
    write("[");
	setFGColour(VGA_BRIGHT_GREEN);
	write("  OK  ");
	setFGColour(VGA_WHITE);
	write("] ");
    writeln(str);
}

void loggerFailed(char* str) {
    write("[");
	setFGColour(VGA_BRIGHT_RED);
	write("FAILED");
	setFGColour(VGA_WHITE);
	write("] ");
    writeln(str);
}
