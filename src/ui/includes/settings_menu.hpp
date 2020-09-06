#ifndef _settings_menu_h
#define _settings_menu_h 
#include <string>
#include <vector>
#include "menu_base.hpp"
using namespace std;

class SettingsMenu: public MenuBase{
    bool settings_menu_is_open = true;
    void print_menu();
    void run_option(char option);

    public: 
    void display();
    SettingsMenu(){
        options = {"Board size", "Keyboard settings", "Go back to main menu"};
    };
};

#endif