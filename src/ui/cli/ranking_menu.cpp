#include <iostream>
#include <iomanip>
#include <vector>
#include "../includes/ranking_menu.hpp"
#include "../includes/terminal.hpp"
#include "../../engine/includes/ranking.hpp"

int RankingMenu::get_biggest_nickname_size(vector<pair<string, int>> ranking){
    int biggest_size = -1;
    for(auto user_points: ranking){
        biggest_size = max(biggest_size, (int) user_points.first.size());
    }
    return biggest_size;
}

void RankingMenu::open(){
    Ranking rk = Ranking();    
    vector<pair<string, int>> ranking = rk.get_ranking();
    int biggest_nickname_size = get_biggest_nickname_size(ranking);
    cout << "Ranking:" << endl;
    for(int i=0; i<ranking.size(); i++){
        int width = biggest_nickname_size - to_string(i+1).size() + 1;
        cout << i+1 << ")" << left << setw(width) << ranking[i].first << " - " << ranking[i].second << endl << right;
    }
    cout << endl << "Press any key to continue." << endl;
    cin.ignore();
}