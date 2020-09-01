#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "board.hpp"

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

// TODO: Implement this to improve apply_movement
void Board::slide_cells(int x, int y){
}

// TODO: Refactor this monster
bool Board::apply_movement(char move){
    move = tolower(move);
    int sum=0, last = 0, tmp, count;
	if(move == 'd'){
		for(int i=0; i<=3; i++){
			last = 0;
			for(int j=3; j>0; j--){
				count = 0;
				while(board[i][j]==0 && count<3){
					tmp=j;
					while(tmp>=1){
						board[i][tmp]=board[i][tmp-1];	
						tmp--;				
					}
					board[i][0]=0;
					count++;
				}
				if(last!= 0 && board[i][j]==last){
					board[i][j+1]*=2;	
					score += board[i][j+1];
					last=0;
					board[i][j]=0;
					j++;	
				}
				else last=board[i][j];
			}	
			if(last!= 0 && board[i][0]==last){
				board[i][1]*=2;		
				score += board[i][1];
				last=0;
				board[i][0]=0;

			}
			
		}
		system("clear");
		return true;
	}
	else if(move =='s'){
		for(int j=0; j<=3; j++){
			last = 0;
			for(int i=3; i>0; i--){
				count = 0;
				while(board[i][j]==0 && count<3){
					tmp=i;
					while(tmp>=1){
						board[tmp][j]=board[tmp-1][j];	
						tmp--;				
					}
					board[0][j]=0;
					count++;
				}
				if(last!= 0 && board[i][j]==last){
					board[i+1][j]*=2;
					score += board[i+1][j];
					last=0;
					board[i][j]=0;
					i++;	
				}
				else last=board[i][j];
			}
			if(last!= 0 && board[0][j]==last){
				board[1][j]*=2;	
				score += board[1][j];
				last=0;
				board[0][j]=0;

			}
		}
		system("clear");
		return true;
	}
	else if(move =='a'){
		for(int i=0; i<=3; i++){
			last = 0;
			for(int j=0; j<3; j++){
				count = 0;
				while(board[i][j]==0 && count<3){
					tmp=j;
					while(tmp<=2){
						board[i][tmp]=board[i][tmp+1];	
						tmp++;				
					}
					board[i][3]=0;
					count++;
				}
				if(last!= 0 && board[i][j]==last){
					board[i][j-1]*=2;
					score += board[i][j-1];
					last=0;
					board[i][j]=0;
					j--;	
				}
				else last=board[i][j];
			}
			if(last!= 0 && board[i][3]==last){
				board[i][2]*=2;
				score += board[i][2];
				last=0;
				board[i][3]=0;
			}
		}
		system("clear");
		return true;
	}
	else if(move =='w'){
		for(int j=0; j<=3; j++){
			last = 0;
			for(int i=0; i<3; i++){
				count = 0;
				while(board[i][j]==0 && count<3){
					tmp=i;
					while(tmp<=2){
						board[tmp][j]=board[tmp+1][j];	
						tmp++;				
					}
					board[3][j]=0;
					count++;
				}
				if(last!= 0 && board[i][j]==last){
					board[i-1][j]*=2;
					score += board[i-1][j];
					last=0;
					board[i][j]=0;
					i--;	
				}
				else last=board[i][j];
			}
			if(last!= 0 && board[3][j]==last){
				board[2][j]*=2;
				score += board[2][j];
				last=0;
				board[3][j]=0;

			}
		}
		system("clear");
		return true;
	}
	system("clear");
	return false;
}