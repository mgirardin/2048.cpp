#include <iostream>
#include <iomanip>
#include "../includes/menu.hpp"
#include "../includes/terminal.hpp"
#include "../includes/cli.hpp"
#include "../includes/ranking_menu.hpp"
using namespace std;

#define MENU_LINE_SIZE 70

void MainMenu::print_menu_instruction(string instruction, string next_color = "blue", string previous_color = "blue"){
    cout << "║  --  ";
    Terminal::change_foreground_color(next_color);
    cout << left << setw(51) << instruction;
    Terminal::change_foreground_color(previous_color);
    cout << right << setw(MENU_LINE_SIZE-57) << "--  ║" << endl;
}

void MainMenu::print_menu_delimiter(string start_char, string end_char, char fill){
    cout << start_char << setfill(fill) << setw(MENU_LINE_SIZE) << end_char << endl;
    cout << setfill(' ');
}

void MainMenu::print_menu_options(){
    for(int i=0; i<options.size(); i++){
        string color = i == choice ? "green" : "blue";
        string previous_color = "blue";
        print_menu_instruction(options[i], color, previous_color);
    }
}

void MainMenu::print_menu(){    
    // TODO: Use '═' (unicode) as a filler (is it possible?)
    Terminal::clear_screen();
    Terminal::change_foreground_color("blue");
    Terminal::make_text_bold();
    print_menu_delimiter("╔", "╗", '*');
    cout << "║" << setw(MENU_LINE_SIZE/2-5) << "" << "2048.cpp" << setw(MENU_LINE_SIZE/2-3) << "║" << endl;
    print_menu_delimiter("║", "║", '*');
    print_menu_instruction("Goal: Merge blocks to gain points");
    print_menu_instruction("Use W/A and Enter to select your option");
    print_menu_options();
    print_menu_delimiter("╚","╝", '-');
    Terminal::change_foreground_color("normal");
}

char MainMenu::get_user_option(){
    char start;
    Terminal::get_user_char(&start);
    start = tolower(start);
    return start;
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
                CommandLineGame clg = CommandLineGame();
                clg.Play();
                break;
            }
            case 1:
            {
                RankingMenu rm = RankingMenu();
                rm.open();
                break;
            }
            case 2:
            {
                exit(0);
            }   
        }
    }
}

void MainMenu::open(){
    while(true){
        print_menu();
        char option = get_user_option();
        run_option(option);
    }
}