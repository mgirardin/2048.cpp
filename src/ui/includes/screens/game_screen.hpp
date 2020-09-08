#ifndef _game_screen_h
#define _game_screen_h 
#include <string>
#include "screen_base.hpp"
#include "../../engine/includes/game_session.hpp"

class GameScreen: public ScreenBase{
    GameSession game;

    void get_user_movement(char* mvm);
    void Finish();    
    void print_game(vector<vector<int>>, int score);
    void save_score();
    void print_text_centered(string text);
    void print_title(string title);
    void print_title_delimiter(string start_char, string end_char, char fill);

    public:
    GameScreen();
    void display();
};

#endif