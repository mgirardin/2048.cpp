#ifndef _board_h
#define _board_h 

class Board{
    long long board[4][4] = {0};
    void slide_cells(int x, int y);

    public:
    long long score = 0;
    int restart_board();
    void print();
    bool is_full();
    bool no_moves();
    bool apply_movement(char move);
    void create_cell();
};

#endif