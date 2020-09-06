#include <iostream>
#include <iomanip>
#include "../includes/main_menu.hpp"
#include "../includes/terminal.hpp"
#include "../includes/game_screen.hpp"
#include "../includes/ranking_menu.hpp"
#include "../includes/settings_menu.hpp"
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

// TODO: Refactor this 
void MainMenu::run_option(char option){
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
                GameScreen clg = GameScreen();
                clg.display();
                break;
            }
            case 1:
            {
                RankingMenu rm = RankingMenu();
                rm.display();
                break;
            }
            case 2:
            {
                SettingsMenu sm = SettingsMenu();
                sm.display();
                break;
            }
            case 3:
            {
                exit(0);
            }   
        }
    }
}