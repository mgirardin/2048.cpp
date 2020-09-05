#include <iostream>
#include "includes/game_session.hpp"
#include "includes/game_settings.hpp"
#include "includes/board.hpp"
#include "includes/ranking.hpp"

#define MAX_NICKNAME_LENGTH 95

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
    game_is_active = true;
    board.restart_board();
};

bool GameSession::is_quit_move(char move){
    GameSettings *gs = GameSettings::getInstance();
    return move == gs->get_quit_key();
}

bool GameSession::make_movement(char move){
    if(is_quit_move(move)){
        Finish();
        return false;
    }
    bool movement_applied = board.apply_movement(move);
    if(movement_applied && !board.is_full()){
        board.create_cell();
    }
    return movement_applied;
}

void GameSession::Finish(){
	game_is_active = false;
}

bool GameSession::Save_Score(){
    Ranking rk = Ranking();
    cout << "Score: " << board.score << endl;
    cout << "Digite seu nickname: ";
    cin.ignore();
    string nickname;
    getline(cin, nickname);
    return rk.create_record(board.score, string(nickname));
}