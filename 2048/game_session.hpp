#ifndef _game_session_h
#define _game_session_h 
#include "board.hpp"

class GameSession{
    Board board;
    void print_welcome();
    int get_user_command();
    void get_user_movement(char* mvm);

    public:
    void Setup();
    void Play();
    void Finish(bool* ended, Board board);
};

#endif