#include <unordered_map>
#include "includes/board.hpp"

// Public methods 
int Board::restart_board(){
	board = vector<vector<int>>(size, vector<int>(size));
	int cells_to_fill = rand()%10 < 5 ? 3 : 2;
	for(int i=0; i<=cells_to_fill-1; i++){
		int input = get_random_cell_value();
		srand(time(NULL));
		int x_position = rand()%size;
		int y_position = rand()%size;
		board[x_position][y_position] = input;
	}
	score = 0;
	return 1;
}

void Board::create_cell(){
    int iterations = rand()%100, value = get_random_cell_value();
	bool cell_found=false;
	while(!cell_found){
		for(int i=0; i<size; i++){
			for(int j=0; j<size and cell_found==false;j++){
				if(board[i][j] == 0 and iterations == 0){
					board[i][j]=value;
					cell_found=true;
				}
				if(iterations>0){
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
    for(int i=0; i<size; i++){
		for(int j=0; j<size;j++){
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

bool Board::apply_movement(char move){
    move = tolower(move);
	unordered_map<char, pair<int, int>> moves = {
		{'d', make_pair(-1,  0)}, 
		{'a', make_pair( 1,  0)},
		{'w', make_pair( 0,  1)},
		{'s', make_pair( 0, -1)}
	};
	if(moves.find(move) == moves.end()){
		return false;
	}
	vector<vector<int>> previous_board = board;
	slide_cells(moves[move]);
	return previous_board!=board;
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

	auto rotate_matrix = [](vector<vector<int>> board, int size){
		vector<vector<int>> temp_board = board;
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				temp_board[j][i] = board[i][j];
			}
		}
		return temp_board;
	};
	board = rotate_matrix(board, size);
	slide_line(column, direction);
	board = rotate_matrix(board, size);
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
	else if(board[line][start] == board[line][start+direction]){
		board[line][start] += board[line][start+direction];
		remove_cell_and_insert_zero(board, line, start + direction, position_to_insert);
		score += board[line][start];
	}
	counter++;
	slide_line(line, direction, start+direction, counter);  
}

void Board::slide_cells(pair<int,int> directions){
	for(int i=0; i<size; i++){
		slide_line(i, directions.first);
		slide_column(i, directions.second);
	}
}

int Board::get_random_cell_value(){
	srand(time(NULL));
	int val = (rand()%10 < 2) ? 4 : 2;
	return val;
}