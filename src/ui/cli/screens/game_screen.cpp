#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "../../includes/screens/game_screen.hpp"
#include "../../../engine/includes/ranking.hpp"
#include "../../includes/terminal.hpp"

#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define MENU_LINE_SIZE 70
#define EMPTY_CELL 0

GameScreen::GameScreen(): game(GameSession()){
    description = "Start game";
}

void GameScreen::get_user_movement(char* mvm){
    printf(" Make your move:\n ");
    Terminal::get_user_char(mvm);
}

void GameScreen::print_text_centered(string text){
    int left_division = (MENU_LINE_SIZE-text.size())/2;
    int right_division = (MENU_LINE_SIZE-text.size()-left_division);
    cout << "║" << setw(left_division) << "" << text << setw(right_division) << "║" << endl;
}

void GameScreen::print_title_delimiter(string start_char, string end_char, char fill){
    cout << start_char << setfill(fill) << setw(MENU_LINE_SIZE) << end_char << endl;
    cout << setfill(' ');
}

void GameScreen::print_title(string title){
    print_title_delimiter("╔", "╗", '*');
    print_text_centered(title);
    print_title_delimiter("║", "║", '*');
}

void GameScreen::print_game(vector<vector<int>> board, int score){
    int board_size = board.size();
    auto get_max_number_of_digits = [](vector<vector<int>> board, int board_size){
        int max_cell_value = INT32_MIN;
        for(int i=0; i<board_size; i++){
            for(int j=0; j<board_size; j++){
                int cell_value = board[i][j];
                max_cell_value = (cell_value>max_cell_value) ? cell_value : max_cell_value;
            }
        }
        return to_string(max_cell_value).size();
    };
    int max_number_of_digits = get_max_number_of_digits(board, board_size);
    print_title("2048.cpp");
    for(int i=0; i<board_size; i++){
        stringstream ss;
        ss << "|";
		for(int j=0; j<board_size;j++){
            string cell_value = board[i][j] != EMPTY_CELL ? to_string(board[i][j]) : " ";
            ss << setw(max_number_of_digits) << cell_value << "|";
		}	
        print_text_centered(ss.str());
	}	
    print_title_delimiter("╚","╝", '-');
    cout << endl << " Score: " << score << endl;
}

void GameScreen::display(){
    game.Start();
    char move;
    Terminal::change_foreground_color("blue");
    Terminal::make_text_bold();
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

void GameScreen::Finish(){
    Terminal::clear_screen();
	print_game(game.get_board(), game.get_score());
    Terminal::change_foreground_color("red");
	printf(" Game over!\n");
    Terminal::change_foreground_color("blue");
    printf("\n Do you want to save your result? (y/N)\n");
    char choice;
    scanf("%c", &choice);
    choice = tolower(choice);
    if(choice == 'y'){
        save_score();
    }
}

void GameScreen::save_score(){
    Terminal::clear_screen();
    if(game.Save_Score()){
        printf("Score saved!\n\n");
    }
    else{
        printf("Error saving score :(\n\n");
    }
    printf("Press enter to continue.\n");
    cin.ignore();
    return;
}