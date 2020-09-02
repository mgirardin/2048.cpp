#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../includes/cli.hpp"

#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KGRN "\x1B[32m"

CommandLineGame::CommandLineGame(){
    game = GameSession();
}

void CommandLineGame::print_welcome(){
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

int CommandLineGame::get_user_command(){
    char start;
    scanf(" %c", &start);
    start = tolower(start);
    if(start == 'g');
    else if(start == 'r');
    else{
        Setup();
    }
}

void CommandLineGame::get_user_movement(char* mvm){
    printf("Faça seu movimento:\n");
	scanf(" %c", mvm);
	while ((getchar()) != '\n');
}

void CommandLineGame::Setup(){
    game.Start();
    print_welcome();
    get_user_command();
    system("clear");
}

void CommandLineGame::print_game(vector<vector<int>> board, int score){
    for(int i=0; i<4; i++){
		printf("|");
		for(int j=0; j<4;j++){
			if(board[i][j]!= 0) printf("%d|", board[i][j]);
			else printf(" |");
		}	
		printf("\n");
	}	
	printf("\n");
	printf("Score: %d\n", score);
}

void CommandLineGame::Play(){
    char move;
    while(game.is_active()){
        print_game(game.get_board(), game.get_score());
        get_user_movement(&move);
        game.make_movement(move);
        if(game.should_end()){
            game.Finish();
        }
        system("clear");
	}
    Finish();
}

void CommandLineGame::Finish(){
    system("clear");
	print_game(game.get_board(), game.get_score());
	printf(KRED);
	printf("Game over!\n");
	printf(KNRM);
}