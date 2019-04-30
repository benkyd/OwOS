#include "logger.h"

#include <kernel/drivers/terminal/terminal.h>

void loggerLog(char* str) {
    Write("         ");
    Writeln(str);
}

void loggerOK(char* str) {
    Write("[");
	SetFGColour(VGA_BRIGHT_GREEN);
	Write("  OK  ");
	SetFGColour(VGA_WHITE);
	Write("] ");
    Writeln(str);
}

void loggerFailed(char* str) {
    Write("[");
	SetFGColour(VGA_BRIGHT_RED);
	Write("FAILED");
	SetFGColour(VGA_WHITE);
	Write("] ");
    Writeln(str);
}
