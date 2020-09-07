#ifndef _ranking_screen_h
#define _ranking_screen_h 
#include <string>
#include <vector>
#include "menu_base.hpp"
using namespace std;

//TODO: Implement ScreenBase instead of MenuBase
class RankingScreen: public MenuBase{
    int get_biggest_nickname_size(vector<pair<string, int>>);
    void run_option(char option){};
    void print_menu();

    public: 
    RankingScreen(){
        description = "Score ranking";
    }
    void display();
};

#endif