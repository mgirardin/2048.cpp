#ifndef _terminal_h
#define _terminal_h 
#include <string>
using namespace std;

class Terminal{
    public:
    void static get_user_char(char *c);
    void static clear_screen();
    void static make_text_bold();
    void static reset_color();
    void static change_foreground_color(string color);
};

#endif