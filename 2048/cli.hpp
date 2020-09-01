#ifndef _cli_h
#define _cli_h 
#include "game_session.hpp"

class CommandLineGame{
    GameSession game;

    int get_user_command();
    void get_user_movement(char* mvm);
    void Finish();    
    void print_game(vector<vector<int>>, int score);
    void print_welcome();

    public:
    CommandLineGame();
    void Setup();
    void Play();
};

#endif