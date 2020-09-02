#ifndef _game_session_h
#define _game_session_h 
#include "board.hpp"

class GameSession{
    Board board;
    bool game_is_active = true;

    public:
    void Start();
    void Play();
    void Finish();
    bool is_active();
    vector<vector<int>> get_board();
    bool should_end();
    int get_score();
    bool make_movement(char move);
};

#endif