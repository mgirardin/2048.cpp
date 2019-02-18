#ifndef _game_lib_h
#define _game_lib_h 
#define ll long long
#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KGRN "\x1B[32m"

extern ll score;
//Welcome new user
int print_welcome();
//Starts board with 2 or 3 random values(2 or 4)
int starting_board(ll board[][4]);
//Prints full board
int print_board(ll board[4][4], ll);
//Asks user for next movement
int mvm_ask(char*);
//Checks if movement is valid and applies it
bool apply_mvm(char, ll board[][4], ll*);
//Checks if the board is full 
bool is_full(ll board[4][4]);
//Check if there is any movement that the player can do
bool no_moves(ll board[4][4]);
//Tells user that he lost and finishes game
int end_game(bool*, ll board[4][4], ll);
//Adds new block in the board
int new_value(ll board[][4]);

#endif
