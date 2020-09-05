#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "../includes/settings_menu.hpp"
#include "../includes/terminal.hpp"

#define MENU_LINE_SIZE 70

void SettingsMenu::print_menu_instruction(string instruction, string next_color = "blue", string previous_color = "blue"){
    cout << "║  --  ";
    Terminal::change_foreground_color(next_color);
    cout << left << setw(51) << instruction;
    Terminal::change_foreground_color(previous_color);
    cout << right << setw(MENU_LINE_SIZE-57) << "--  ║" << endl;
}

void SettingsMenu::print_menu_delimiter(string start_char, string end_char, char fill){
    cout << start_char << setfill(fill) << setw(MENU_LINE_SIZE) << end_char << endl;
    cout << setfill(' ');
}

void SettingsMenu::print_menu(){
    Terminal::clear_screen();
    Terminal::change_foreground_color("blue");
    Terminal::make_text_bold();
    print_menu_delimiter("╔", "╗", '*');
    cout << "║" << setw(MENU_LINE_SIZE/2-5) << "" << "Settings" << setw(MENU_LINE_SIZE/2-3) << "║" << endl;
    print_menu_delimiter("║", "║", '*');
    //print_menu_instruction("Goal: Merge blocks to gain points");
    //print_menu_instruction("Use W/A and Enter to select your option");
    //print_menu_options();
    print_menu_delimiter("╚","╝", '-');
    cout << endl << "Press enter to continue." << endl;
    Terminal::change_foreground_color("normal");
}

void SettingsMenu::open(){
    print_menu();
    cin.ignore();
}