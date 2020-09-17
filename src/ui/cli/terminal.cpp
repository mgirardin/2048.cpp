#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../includes/terminal.hpp"
#include "../../../libraries/termcolor/termcolor.hpp"
using namespace std;

void Terminal::clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Terminal::get_user_char(char* c){
    #ifdef _WIN32
        // TODO: Implement this to Windows
        #error Not ready for Windows
    #else
        system("/bin/stty raw");
        scanf("%c", c);
        if(*c <= 13){
            *c = '\n';
        }
        system ("/bin/stty cooked");
    #endif
}

void Terminal::make_text_bold(){
    cout << termcolor::bold;
}

// Accepts green, red, blue and normal 
// TODO: Refactor ( reflection would be beautiful :'( )
void Terminal::change_foreground_color(string color){
    vector<string> colors = {"red", "blue", "green", "normal"};
    if (find(colors.begin(), colors.end(), color)==colors.end()){
        cout << color << endl;
        throw("color not supported");
    }
    if(color == "red"){
        cout << termcolor::red;
    }
    else if(color == "green"){
        cout << termcolor::green;
    }
    else if(color == "blue"){
        cout << termcolor::blue;
    }
    else if(color == "normal"){
        cout << termcolor::reset;
    }
}