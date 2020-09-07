#ifndef _mainmenu_h
#define _mainmenu_h 
#include <string>
#include <vector>
#include "menu_base.hpp"
#include "../screens/game_screen.hpp"
#include "../screens/ranking_screen.hpp"
#include "settings_menu.hpp"
#include "../screens/quit_screen.hpp"
using namespace std;

class MainMenu: public MenuBase{
    void print_menu();
        
    public:
    MainMenu(){
        description = "Main menu";
        is_main_menu = true;
        GameScreen *gs = new GameScreen();
        RankingScreen *rm = new RankingScreen();
        SettingsMenu *sm = new SettingsMenu();
        QuitScreen *qs = new QuitScreen();
        options = {gs, rm, sm , qs};
    };
};

#endif