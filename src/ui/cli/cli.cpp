#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <iomanip>
#include "../includes/cli.hpp"
#include "../../engine/includes/ranking.hpp"
#include "../includes/terminal.hpp"

#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KGRN "\x1B[32m"
#define KBLUE "\x1B[36m"
#define MENU_LINE_SIZE 70

CommandLineGame::CommandLineGame(): game(GameSession()){}

void CommandLineGame::get_user_movement(char* mvm){
    printf("Faça seu movimento:\n");
    Terminal::get_user_char(mvm);
}

void CommandLineGame::print_game(vector<vector<int>> board, int score){
    int board_size = board.size();
    int max_cell_value = INT32_MIN;
    for(int i=0; i<board_size; i++){
        for(int j=0; j<board_size; j++){
            int cell_value = board[i][j];
            max_cell_value = (cell_value>max_cell_value) ? cell_value : max_cell_value;
        }
    }
    int max_number_of_digits = to_string(max_cell_value).size();
    for(int i=0; i<board_size; i++){
		printf("|");
		for(int j=0; j<board_size;j++){
            string cell_value = board[i][j] != 0 ? to_string(board[i][j]) : " ";
            cout << setw(max_number_of_digits) << cell_value << "|";
		}	
		printf("\n");
	}	
	printf("\n");
	printf("Score: %d\n", score);
}

void CommandLineGame::Play(){
    game.Start();
    char move;
    while(game.is_active()){
        print_game(game.get_board(), game.get_score());
        get_user_movement(&move);
        game.make_movement(move);
        if(game.should_end()){
            game.Finish();
        }
        Terminal::clear_screen();
	}
    Finish();
}

void CommandLineGame::Finish(){
    Terminal::clear_screen();
	print_game(game.get_board(), game.get_score());
	printf("%sGame over!\n%s", KRED, KNRM);
    printf("\n\nDeseja salvar seu resultado no ranking? (y/N)\n");
    char choice;
    scanf("%c", &choice);
    choice = tolower(choice);
    if(choice == 'y'){
        save_score();
    }
}

void CommandLineGame::save_score(){
    Terminal::clear_screen();
    if(game.Save_Score()){
        printf("Score salvo com sucesso!\n\n");
    }
    else{
        printf("Erro ao salvar score :(\n\n");
    }
    printf("Pressione enter para voltar a tela inicial.\n");
    cin.ignore();
    return;
}