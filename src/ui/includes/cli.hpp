#ifndef _cli_h
#define _cli_h 
#include <string>
#include "../../engine/includes/game_session.hpp"

class CommandLineGame{
    GameSession game;

    void get_user_movement(char* mvm);
    void Finish();    
    void print_game(vector<vector<int>>, int score);
    void save_score();

    public:
    CommandLineGame();
    void Play();
};

#endif