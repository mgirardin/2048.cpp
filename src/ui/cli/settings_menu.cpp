#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "../includes/settings_menu.hpp"
#include "../includes/terminal.hpp"

void SettingsMenu::print_menu(){
    Terminal::clear_screen();
    Terminal::change_foreground_color("blue");
    Terminal::make_text_bold();
    print_menu_title("Settings");
    print_menu_instruction("Use W/A and Enter to select your option");
    print_menu_options();
    print_menu_delimiter("╚","╝", '-');
    Terminal::change_foreground_color("normal");
}