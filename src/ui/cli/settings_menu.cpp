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

void SettingsMenu::run_option(char option){
    Terminal::clear_screen();
    if(option == 'w'){
        choice = choice>0 ? choice-1 : choice;
    }
    else if(option == 's'){
        choice = choice<options.size()-1 ? choice+1 : choice;
    }
    else if(option == 'q'){
        exit(0);
    }
    else if(option == '\n'){
        switch(choice){
            case 0:
            {
                
                break;
            }
            case 1:
            {
                
                break;
            }
            case 2:
            {
                settings_menu_is_open = false;
                break;
            } 
        }
    }
}

void SettingsMenu::open(){
        while(settings_menu_is_open){
            print_menu();
            char option = get_user_option();
            run_option(option);
        }
    }
