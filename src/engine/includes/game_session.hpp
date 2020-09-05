#ifndef _game_session_h
#define _game_session_h 
#include "board.hpp"

class GameSession{
    Board board;
    bool game_is_active = true;
    bool is_quit_move(char move);

    public:
    void Start();
    void Play();
    void Finish();
    bool Save_Score();
    bool is_active();
    vector<vector<int>> get_board();
    bool should_end();
    int get_score();
    bool make_movement(char move);
};

#endif