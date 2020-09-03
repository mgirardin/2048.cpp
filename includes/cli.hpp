#ifndef _cli_h
#define _cli_h 
#include "game_session.hpp"

class CommandLineGame{
    GameSession game;

    void get_user_command();
    void get_user_movement(char* mvm);
    void Finish();    
    void print_game(vector<vector<int>>, int score);
    void print_welcome();
    void show_ranking();
    void save_score();

    public:
    CommandLineGame();
    void Setup();
    void Play();
};

#endif