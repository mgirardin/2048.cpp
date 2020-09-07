#ifndef _menubase_h
#define _menubase_h 
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../terminal.hpp"
#include "../screens/screen_base.hpp"
using namespace std;

#define MENU_LINE_SIZE 70

class MenuBase: public ScreenBase{
    public:
    virtual void display(){
        while(is_main_menu || is_menu_open){
            print_menu();
            char option = get_user_option();
            run_option(option);
        }
        is_menu_open = true;
        choice = 0;
    }

    protected:
    vector<ScreenBase*> options = {};
    int choice = 0;
    bool is_main_menu = false;
    bool is_menu_open = true;

    virtual void run_option(char option){
        Terminal::clear_screen();
        if(option == 'w'){
            choice = choice>0 ? choice-1 : choice;
        }
        else if(option == 's'){
            int options_size = options.empty() ? 0 : options.size();
            choice = choice<(options_size-1) ? choice+1 : choice;
        }
        else if(option == 'q'){
            exit(0);
        }
        else if(option == '\n'){
            if(choice == options.size()){
                is_menu_open = false;
                return;
            }
            options[choice]->display();
        }
    };

    virtual void print_menu() = 0;
    
    virtual void print_menu_options(){
        for(int i=0; i<options.size(); i++){
            string color = i == choice ? "green" : "blue";
            string previous_color = "blue";
            print_menu_instruction(options[i]->description, color, previous_color);
        }
        if(is_main_menu == false){
            string color = options.size() == choice ? "green" : "blue";
            string previous_color = "blue";
            print_menu_instruction("Go back to previous menu", color, previous_color);
        }
    };

    void print_menu_delimiter(string start_char, string end_char, char fill){
        cout << start_char << setfill(fill) << setw(MENU_LINE_SIZE) << end_char << endl;
        cout << setfill(' ');
    }

    void print_menu_instruction(string instruction, string next_color = "blue", string previous_color = "blue"){
        cout << "║  --  ";
        Terminal::change_foreground_color(next_color);
        cout << left << setw(51) << instruction;
        Terminal::change_foreground_color(previous_color);
        cout << right << setw(MENU_LINE_SIZE-57) << "--  ║" << endl;
    }

    char get_user_option(){
        char start;
        Terminal::get_user_char(&start);
        start = tolower(start);
        return start;
    }

    void print_menu_title(string title){
        int left_division = (MENU_LINE_SIZE-title.size())/2;
        int right_division = (MENU_LINE_SIZE-title.size()-left_division);
        print_menu_delimiter("╔", "╗", '*');
        cout << "║" << setw(left_division) << "" << title << setw(right_division) << "║" << endl;
        print_menu_delimiter("║", "║", '*');
    }
};

#endif