#ifndef _ranking_h
#define _ranking_h 
#include "../libraries/sqlite/sqlite3.h"
#include <vector>
#include <string>
using namespace std;

class Ranking{
    sqlite3 *db;
    vector<pair<string, int>> get_user_points(); 
    vector<pair<string, int>> sort_ranking(vector<pair<string, int>>);
    
    public:
    Ranking();
    void print_ranking();
};

#endif