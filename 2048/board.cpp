#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string>
#include "board.hpp"

// Public methods 
int Board::restart_board(){
	board = vector<vector<int>>(4, vector<int>(4));
    srand(time(NULL));
	int size = rand()%10, input, x, y;
	if(size < 5) size=3;
	else size=2;
	for(int i=0; i<=size-1; i++){
		input = (rand()%10 < 1) ? 4 : 2;
		x = rand()%4;
		y = rand()%4;
		board[x][y] = input;
	}
	return 1;
}

void Board::create_cell(){
    int value = rand()%10, iterations = rand()%100;
	bool found=false;
	if(value < 2) value=4;
	else value=2;
	while(!found){
		for(int i=0; i<4; i++){
			for(int j=0; j<4;j++){
				if(board[i][j]==0){
					if(iterations==0){	
						board[i][j]=value;
						found=true;
					}
					iterations--;
				}
			}	
		}
	}
}

vector<vector<int>> Board::get_cells(){
    return board;
}

bool Board::is_full(){
    for(int i=0; i<4; i++){
		for(int j=0; j<4;j++){
			if(board[i][j]==0){
				return false;
			}
		}	
	}
	return true;
}

bool Board::no_moves(){
    int last;
	for(int j=0; j<=3; j++){
		last = 0;
		for(int i=0; i<3; i++){
			if (board[i][j]==0){
				return false;				
			}
			else if(last!= 0 && board[i][j]==last){
				return false;	
			}
			else last=board[i][j];
		}
		if(last!= 0 && board[3][j]==last){
			return false;
		}
	}
	for(int i=0; i<=3; i++){
		last = 0;
		for(int j=0; j<3; j++){
			while(board[i][j]==0){
				return false;
			}
			if(last!= 0 && board[i][j]==last){
				return false;	
			}
			else last=board[i][j];
		}
		if(last!= 0 && board[i][3]==last){
			return false;
		}
	}
	return true;
}

// TODO: Refactor this monster (now just a little monster, was way worse)
bool Board::apply_movement(char move){
    move = tolower(move);
	bool isValidMove = false;
    if(move == 'd'){
		slide_cells(-1, 0);
		isValidMove = true;
	}
	if(move == 'a'){
		slide_cells(1, 0);
		isValidMove = true;
	}
	if(move == 'w'){
		slide_cells(0, 1);
		isValidMove = true;
	}
	if(move == 's'){
		slide_cells(0, -1);
		isValidMove = true;
	}
	system("clear");
	return isValidMove;
}

// Private methods
void Board::slide_column(int column, int direction){
	if(direction == 0){
		return;
	}
	if(direction != 1 and direction != -1){
		throw string("Column slide direction must be be 0, 1 or -1");
	}
	if(column<0 or column>size-1){
		throw string("Column to slide must not be < 0 or >= board size");
	}

	vector<vector<int>> temp_board = board;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			temp_board[j][i] = board[i][j];
		}
	}
	board = temp_board;

	slide_line(column, direction);

	vector<vector<int>> new_board = board;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			new_board[j][i] = board[i][j];
		}
	}
	board = new_board;
}

//direction == 1 -> LEFT / UP
//direction ==-1 -> RIGHT / DOWN
void Board::slide_line(int line, int direction){
	if(direction == 0){
		return;
	}
	if(direction != 1 and direction != -1){
		throw string("Line slide direction must be be 0, 1 or -1");
	}
	if(line<0 or line>size-1){
		throw string("Line to slide must not be < 0 or >= board size");
	}
	int start = direction == -1 ? size-1 : 0;
	slide_line(line, direction, start, 0);
}

void Board::slide_line(int line, int direction, int start, int counter = 0){
	if(direction == 1 and start >= size-1 || direction == -1 and start <= 0){
		return;
	}
	/*
		Counter needed to avoid infinite recursion calls for full sequence of 0s;
		We need to stay in the same cell when we delete the current cell (value 0), otherwise we
		jump the next number, but it could cause infinite recursion calls
	*/
	if(counter>size){
		return;
	}
	int position_to_insert = direction == 1 ? size-1 : 0;
	auto remove_cell_and_insert_zero = [](vector<vector<int>> &board, int line, 
											int position_to_remove, int position_to_insert){ 
        board[line].erase(board[line].begin()+position_to_remove);
		board[line].insert(board[line].begin() + position_to_insert, 0);
    };
	//Current cell == 0
	if(board[line][start] == 0){
		remove_cell_and_insert_zero(board, line, start, position_to_insert);
		start-=direction;
	}
	//Next cell == 0
	else if(board[line][start+direction] == 0){
		remove_cell_and_insert_zero(board, line, start+direction, position_to_insert);
		start-=direction;
	}
	//Current cell == next cell
	if(board[line][start] == board[line][start+direction]){
		board[line][start] += board[line][start+direction];
		remove_cell_and_insert_zero(board, line, start + direction, position_to_insert);
		score += board[line][start];
	}
	counter++;
	slide_line(line, direction, start+direction, counter);  
}

void Board::slide_cells(int line_direction, int column_direction){
	for(int i=0; i<size; i++){
		slide_line(i, line_direction);
		slide_column(i, column_direction);
	}
}