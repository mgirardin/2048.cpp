#ifndef _mainmenu_h
#define _mainmenu_h 
#include <string>
#include <vector>
#include "menu_base.hpp"
using namespace std;

class MainMenu: public MenuBase{
    void print_menu();
    void run_option(char option);
    public:
    MainMenu(){
        options = {"Start game", "Score ranking", "Settings", "Quit"};
    };
};

#endif