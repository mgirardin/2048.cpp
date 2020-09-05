#ifndef _rankingmenu_h
#define _rankingmenu_h 
#include <string>
#include <vector>
using namespace std;

class RankingMenu{
    int get_biggest_nickname_size(vector<pair<string, int>>);
    public: 
    void open();
};

#endif