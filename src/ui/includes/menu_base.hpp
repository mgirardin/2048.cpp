#ifndef _menubase_h
#define _menubase_h 
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include "terminal.hpp"
using namespace std;

#define MENU_LINE_SIZE 70

class MenuBase{
    public:
    virtual void open(){
        while(true){
            print_menu();
            char option = get_user_option();
            run_option(option);
        }
    }

    protected:
    vector<string> options = {};
    int choice = 0;
    virtual void run_option(char option) = 0;
    virtual void print_menu() = 0;
    
    virtual void print_menu_options(){
        for(int i=0; i<options.size(); i++){
            string color = i == choice ? "green" : "blue";
            string previous_color = "blue";
            print_menu_instruction(options[i], color, previous_color);
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
        cout << "║" << setw(MENU_LINE_SIZE/2-5) << "" << title << setw(MENU_LINE_SIZE/2-3) << "║" << endl;
        print_menu_delimiter("║", "║", '*');
    }
};

#endif