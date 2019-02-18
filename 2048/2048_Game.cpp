#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamelib.h"

#define ll long long

int main(){
	bool ended = false;		
	ll board[4][4] = {0};
	char mvm;

	print_welcome();

	//Initializes random values
	starting_board(board);
	system("clear");

	//Game loop
	while(!ended){
		print_board(board, score);
		//Asks user for next movement
		mvm_ask(&mvm);
		//If movement is not valid, continue the loop to prevent new values in the board
		if(!apply_mvm(mvm, board, &score)) continue;
		//Checks if the game is now over
		if(is_full(board) && no_moves(board)){
			end_game(&ended, board, score);
		}	
		else new_value(board);
	}
	return 0;
}
