#ifndef _cli_h
#define _cli_h 
#include <string>
#include "game_session.hpp"

class CommandLineGame{
    GameSession game;

    void get_user_command();
    void get_user_movement(char* mvm);
    void Finish();    
    void print_game(vector<vector<int>>, int score);
    void print_menu();
    void print_menu_instruction(string instruction);
    void print_menu_delimiter(string start_char, string end_char, char fill);
    void clear_screen();
    void show_ranking();
    void save_score();

    public:
    CommandLineGame();
    void Setup();
    void Play();
};

#endif