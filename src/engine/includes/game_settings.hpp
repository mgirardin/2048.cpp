#ifndef _game_settings_h
#define _game_settings_h 
using namespace std;

class GameSettings{
    static GameSettings *instance;
    int board_size = 4;
    char key_down = 's', key_up = 'w', key_left = 'a', key_right = 'd';
    GameSettings();

    public:
    static GameSettings *getInstance();
    int get_board_size();
    char get_key_down();
    char get_key_up();
    char get_key_left();
    char get_key_right();
};

#endif