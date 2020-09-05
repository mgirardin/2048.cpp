#include "includes/game_settings.hpp"

GameSettings::GameSettings(){}

GameSettings *GameSettings::instance = 0;

GameSettings* GameSettings::getInstance(){
    if(!instance){
        instance = new GameSettings();
    }
    return instance;
}

int GameSettings::get_board_size(){
    return board_size;
}

char GameSettings::get_key_down(){
    return key_down;
}

char GameSettings::get_key_up(){
    return key_up;
}

char GameSettings::get_key_left(){
    return key_left;
}

char GameSettings::get_key_right(){
    return key_right;
}

char GameSettings::get_quit_key(){
    return quit_key;
}