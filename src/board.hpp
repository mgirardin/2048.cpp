#ifndef _board_h
#define _board_h 
#include <vector>
using namespace std;

class Board{
    vector<vector<int>> board;
    int size = 4;
    void slide_cells(pair<int, int> directions);
    void slide_line(int line, int direction);
    void slide_line(int line, int direction, int start, int counter);
    void slide_column(int column, int direction);

    public:
    long long score = 0;
    int restart_board();
    vector<vector<int>> get_cells();
    bool is_full();
    bool no_moves();                    //maybe no_moves and apply_movement should be in a separete class
    bool apply_movement(char move);
    void create_cell();
};

#endif