#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
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

void RankingMenu::print_menu(){
    Ranking rk = Ranking();    
    vector<pair<string, int>> ranking = rk.get_ranking();
    int biggest_nickname_size = get_biggest_nickname_size(ranking);
    Terminal::clear_screen();
    Terminal::change_foreground_color("blue");
    Terminal::make_text_bold();
    print_menu_title("Ranking");
    for(int i=0; i<ranking.size(); i++){
        int width = biggest_nickname_size - to_string(i+1).size() + 1;
        stringstream ss;
        ss <<  i+1 << ") " << left << setw(width) << ranking[i].first << " : " << ranking[i].second << right;
        string record = ss.str();
        print_menu_instruction(record); 
    }
    print_menu_delimiter("╚","╝", '-');
    cout << endl << " Press enter to continue." << endl;
    Terminal::change_foreground_color("normal");
    cin.ignore();
}

void RankingMenu::display(){
    print_menu();
}