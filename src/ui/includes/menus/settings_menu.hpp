#ifndef _settings_menu_h
#define _settings_menu_h 
#include <string>
#include <vector>
#include "menu_base.hpp"
using namespace std;

class SettingsMenu: public MenuBase{
    void print_menu();

    public: 
    SettingsMenu(){
        description = "Settings";
        options = {};
        //options = {"Board size", "Keyboard settings", "Go back to main menu"};
    };
};

#endif