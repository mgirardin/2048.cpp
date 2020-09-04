#include <stdlib.h>
#include <iostream>
#include "../includes/terminal.hpp"

void Terminal::clear_screen(){
    #ifdef WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
}

void Terminal::get_user_char(char* c){
    #ifdef WINDOWS
        // TODO: Implement this to Windows 
    #else
        system("/bin/stty raw");
        scanf(" %c", c);
        system ("/bin/stty cooked");
    #endif
}