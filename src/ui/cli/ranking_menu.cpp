#include "../includes/ranking_menu.hpp"
#include "../../engine/includes/ranking.hpp"
#include <iostream>
#include <vector>

void RankingMenu::open(){
    Ranking rk = Ranking();    
    vector<pair<string, int>> ranking = rk.get_ranking();
    cout << "Ranking:" << endl;
    for(int i=0; i<ranking.size(); i++){
        cout << i+1 << ")" << ranking[i].first << " - " << ranking[i].second << endl;
    }
    cout << endl << "Pressione enter para voltar para a tela inicial." << endl;
    cin.ignore();
}