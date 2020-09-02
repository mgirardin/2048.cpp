#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_session.hpp"
#include "board.hpp"

#define ll long long
#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KGRN "\x1B[32m"

bool GameSession::is_active(){
    return game_is_active;
}

bool GameSession::should_end(){
    return board.is_full() && board.no_moves();
}

int GameSession::get_score(){
    return board.score;
}

vector<vector<int>> GameSession::get_board(){
    return board.get_cells();
}

void GameSession::Start(){
    board.restart_board();
};

bool GameSession::make_movement(char move){
    bool movement_applied = board.apply_movement(move);
    if(movement_applied && !board.is_full()){
        board.create_cell();
    }
    return movement_applied;
}

void GameSession::Finish(){
	game_is_active = false;
}