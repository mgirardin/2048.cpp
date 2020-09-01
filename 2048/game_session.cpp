#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_session.hpp"
#include "board.hpp"

#define ll long long
#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KGRN "\x1B[32m"

void GameSession::print_welcome(){
    system("clear");
    printf("\x1B[36m");
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("║                            2048!                        ║\n");
    printf("╠═════════════════════════════════════════════════════════╣\n");	
    printf("║  --  Objetivo: Montar um quadrado de valor 2048      -- ║\n");
    printf("║  --    	    Comandos: W/A/S/D                  -- ║\n");
    printf("║  --          Digite G para começar o jogo            -- ║\n");
    printf("║  --        Digite R para ver o Score Ranking         -- ║\n");
    printf("║  --    	   Feito por: Girardin                 -- ║\n");
    printf("╚═════════════════════════════════════════════════════════╝\n");
    printf(KNRM);
}

int GameSession::get_user_command(){
    char start;
    scanf(" %c", &start);
    if(start == 'G' || start == 'g');
    else if(start == 'R' || start == 'r');
    else{
        Setup();
    }
}

void GameSession::get_user_movement(char* mvm){
    printf("Faça seu movimento:\n");
	scanf(" %c", mvm);
	while ((getchar()) != '\n');
}

void GameSession::Setup(){
    print_welcome();
    get_user_command();
    board.restart_board();
    system("clear");
};

void GameSession::Play(){
    bool ended = false;
    char move;
    while(!ended){
		//Checks if the game is now over
		if(board.is_full() && board.no_moves()){
			Finish(&ended, board);
		}
		else{	
			board.print();
			//Asks user for next movement
			get_user_movement(&move);
			//If movement is not valid, continue the loop to prevent new values in the board
			if(!board.apply_movement(move)){
                continue;
            }
			if(!board.is_full()){
                board.create_cell();
            }
		}
	}
}

void GameSession::Finish(bool* ended, Board board){
    system("clear");
	board.print();
	*ended = true;
	printf(KRED);
	printf("Game over!\n");
	printf(KNRM);
}