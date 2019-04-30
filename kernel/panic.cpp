#include "panic.h"

#include <lib/stdint.h>
#include <lib/std/stdlib.h>
#include <lib/std/string.h>

#include <kernel/drivers/terminal/terminal.h>

void PanicKernel(char code, char* why, char* where, char* what) {
    if (why == "") {
        switch (code) {
            case 0x00:
                why = "Self triggered panic";
                break;

            default:
                why = "Uknown Error";
                break;
        }
    }

    ResetTermColours();
    HideCursor();
    Cls();
    
    SetBGColour(VGA_RED);
    for (uint8_t i = 0; i < TERMINAL_WIDTH; i++)
        Puts(' ');

    SetCursorPosition(34, 0);
    Write("KERNEL PANIC");

    ResetTermColours();
    SetFGColour(VGA_DARK_GREY);
    SetCursorPosition(1, 3);
    Write("OOPSIE WOOPSIE! WE MADE A FUCKIE WUCKIE!! A WIDDLE FUCKO BOINGO! \n THE CODE MONKEYS AT HEADQUARTERS ARE WORKING VEWWY HAWD TO FIX THIS!");

    ResetTermColours();
    SetCursorPosition(1, 6);
    Write("EXCEPTION: ");
    Write(why);
    Puts(' ');
    Write(" (Error code 0x");
    Write(itohx(code));
    Puts(')');
    Nline(); Nline();

    SetFGColour(VGA_GREY);
    Write(" at: ");
    Write(where);
    Puts(' ');

    bool seenBracket = false;
    for(uint32_t i = 0; i < strlen(what); i++) {
        if (what[i] == '(')
            seenBracket = true;

        if (GetCursorPosition().x > 60) {
            Write(" ...");
            break;
        }

        if (!seenBracket) {
            SetFGColour(VGA_YELLOW);
        } else {
            SetFGColour(VGA_GREY);
        }
        Puts(what[i]);
    }


    SetCursorPosition(0, TERMINAL_HEIGHT);
    SetBGColour(VGA_GREY);
    for (uint8_t i = 0; i < TERMINAL_WIDTH; i++)
        Puts(' ');

    SetFGColour(VGA_BLACK);
    SetCursorPosition(1, TERMINAL_HEIGHT);
    Write("Error Code: 0x");
    Write(itohx(code));

    asm("cli"); // Clear interrupt bit / dissable interrupts
}
