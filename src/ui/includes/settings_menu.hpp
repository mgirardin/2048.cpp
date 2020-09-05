#ifndef _settings_menu_h
#define _settings_menu_h 
#include <string>
#include <vector>
using namespace std;

class SettingsMenu{
    vector<string> options = {};
    int choice = 0;
    void print_menu_instruction(string instruction, string next_color, string previous_color);
    void print_menu_delimiter(string start_char, string end_char, char fill);
    void print_menu_options();
    void print_menu();
    //char get_user_option();
    //void run_option(char option);

    public: 
    void open();
};

#endif