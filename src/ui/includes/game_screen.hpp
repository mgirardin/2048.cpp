#ifndef _game_screen_h
#define _game_screen_h 
#include <string>
#include "screen_base.hpp"
#include "../../engine/includes/game_session.hpp"

class GameScreen: ScreenBase{
    GameSession game;

    void get_user_movement(char* mvm);
    void Finish();    
    void print_game(vector<vector<int>>, int score);
    void save_score();

    public:
    GameScreen();
    void display();
};

#endif