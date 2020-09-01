#ifndef _board_h
#define _board_h 
#include <vector>
using namespace std;

class Board{
    vector<vector<int>> board;
    void slide_cells(int x, int y);

    public:
    long long score = 0;
    int restart_board();
    vector<vector<int>> get_cells();
    bool is_full();
    bool no_moves();
    bool apply_movement(char move);
    void create_cell();
};

#endif