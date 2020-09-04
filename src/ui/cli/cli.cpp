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

void CommandLineGame::print_menu_instruction(string instruction){
    cout << "║" << left << setw(57) << "  --  " + instruction << right << setw(MENU_LINE_SIZE-57) << "--  ║" << endl;
}

void CommandLineGame::print_menu_delimiter(string start_char, string end_char, char fill){
        cout << start_char << setfill(fill) << setw(MENU_LINE_SIZE) << end_char << endl;
        cout << setfill(' ');
}

void CommandLineGame::print_menu(){    
    // TODO: Use '═' (unicode) as a filler (is it possible? );
    Terminal::clear_screen();
    cout << KBLUE;
    print_menu_delimiter("╔", "╗", '*');
    cout << "║" << setw(MENU_LINE_SIZE/2-5) << "" << "2048.cpp" << setw(MENU_LINE_SIZE/2-3) << "║" << endl;
    print_menu_delimiter("║", "║", '*');
    print_menu_instruction("Objetivo: Montar um quadrado de valor 2048");
    print_menu_instruction("Comandos: W/A/S/D");
    print_menu_instruction("Digite G para comecar o jogo");
    print_menu_instruction("Digite R para ver o Score Ranking");
    print_menu_delimiter("╚","╝", '-');
    cout << KNRM;
}

void CommandLineGame::get_user_command(){
    char start;
    Terminal::get_user_char(&start);
    start = tolower(start);
    if(start == 'g');
    else if(start == 'r'){
        
        Terminal::clear_screen();
        show_ranking();
    }
    else{
        Setup();
    }
}

void CommandLineGame::show_ranking(){
    Ranking rk = Ranking();    
    vector<pair<string, int>> ranking = rk.get_ranking();
    cout << "Ranking:" << endl;
    for(int i=0; i<ranking.size(); i++){
        cout << i+1 << ")" << ranking[i].first << " - " << ranking[i].second << endl;
    }
    cout << endl << "Pressione enter para voltar para a tela inicial." << endl;
    cin.ignore();
    Setup();
}

void CommandLineGame::get_user_movement(char* mvm){
    printf("Faça seu movimento:\n");
    Terminal::get_user_char(mvm);
}

void CommandLineGame::Setup(){
    game.Start();
    print_menu();
    get_user_command();
    Terminal::clear_screen();
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
    Setup();
    Play();
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
    cin.ignore();
    return;
}