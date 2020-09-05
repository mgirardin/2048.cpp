#ifndef _rankingmenu_h
#define _rankingmenu_h 
#include <string>
#include <vector>
#include "menu_base.hpp"
using namespace std;

class RankingMenu: public MenuBase{
    int get_biggest_nickname_size(vector<pair<string, int>>);
    void run_option(char option){};
    void print_menu();
    public: 
    void open();
};

#endif