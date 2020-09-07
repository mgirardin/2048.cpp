#include <iostream>
#include <iomanip>
#include "../../includes/menus/main_menu.hpp"
#include "../../includes/terminal.hpp"
#include "../../includes/screens/game_screen.hpp"
#include "../../includes/screens/ranking_screen.hpp"
#include "../../includes/menus/settings_menu.hpp"
using namespace std;

void MainMenu::print_menu(){    
    // TODO: Use '═' (unicode) as a filler (is it possible?)
    Terminal::clear_screen();
    Terminal::change_foreground_color("blue");
    Terminal::make_text_bold();
    print_menu_title("2048.cpp");
    print_menu_instruction("Goal: Merge blocks to gain points");
    print_menu_instruction("Use W/A and Enter to select your option");
    print_menu_options();
    print_menu_delimiter("╚","╝", '-');
    Terminal::change_foreground_color("normal");
}