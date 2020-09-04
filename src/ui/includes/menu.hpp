#ifndef _mainmenu_h
#define _mainmenu_h 
#include <string>
using namespace std;

class MainMenu{
    void print_menu_instruction(string instruction);
    void print_menu_delimiter(string start_char, string end_char, char fill);
    void print_menu();
    char get_user_option();
    void run_option(char option);

    public: 
    void open();
};

#endif