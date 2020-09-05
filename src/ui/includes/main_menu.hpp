#ifndef _mainmenu_h
#define _mainmenu_h 
#include <string>
#include <vector>
using namespace std;

class MainMenu{
    vector<string> options = {"Start game", "Score ranking", "Settings", "Quit"};
    int choice = 0;
    void print_menu_instruction(string instruction, string next_color, string previous_color);
    void print_menu_delimiter(string start_char, string end_char, char fill);
    void print_menu_options();
    void print_menu();
    char get_user_option();
    void run_option(char option);

    public: 
    void open();
};

#endif