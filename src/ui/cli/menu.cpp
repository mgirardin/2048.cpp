#include <iostream>
#include <iomanip>
#include "../includes/menu.hpp"
#include "../includes/terminal.hpp"
#include "../includes/cli.hpp"
#include "../includes/ranking_menu.hpp"
using namespace std;

#define MENU_LINE_SIZE 70

void MainMenu::print_menu_instruction(string instruction){
    cout << "║" << left << setw(57) << "  --  " + instruction << right << setw(MENU_LINE_SIZE-57) << "--  ║" << endl;
}

void MainMenu::print_menu_delimiter(string start_char, string end_char, char fill){
    cout << start_char << setfill(fill) << setw(MENU_LINE_SIZE) << end_char << endl;
    cout << setfill(' ');
}

void MainMenu::print_menu(){    
    // TODO: Use '═' (unicode) as a filler (is it possible?)
    Terminal::clear_screen();
    Terminal::change_foreground_color("blue");
    Terminal::make_text_bold();
    print_menu_delimiter("╔", "╗", '*');
    cout << "║" << setw(MENU_LINE_SIZE/2-5) << "" << "2048.cpp" << setw(MENU_LINE_SIZE/2-3) << "║" << endl;
    print_menu_delimiter("║", "║", '*');
    print_menu_instruction("Objetivo: Montar um quadrado de valor 2048");
    print_menu_instruction("Comandos: W/A/S/D");
    print_menu_instruction("Digite S para comecar o jogo");
    print_menu_instruction("Digite R para ver o Score Ranking");
    print_menu_instruction("Digite Q para sair do jogo");
    print_menu_delimiter("╚","╝", '-');
    Terminal::change_foreground_color("normal");
}

char MainMenu::get_user_option(){
    char start;
    Terminal::get_user_char(&start);
    start = tolower(start);
    return start;
}

void MainMenu::run_option(char option){
    Terminal::clear_screen();
    if(option == 's'){
        CommandLineGame clg = CommandLineGame();
        clg.Play();
    }
    else if(option == 'r'){
        RankingMenu rm = RankingMenu();
        rm.open();
    }
    else if(option == 'q'){
        exit(0);
    }
}

void MainMenu::open(){
    while(true){
        print_menu();
        char option = get_user_option();
        run_option(option);
    }
}