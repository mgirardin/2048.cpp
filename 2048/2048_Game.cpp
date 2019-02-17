#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define KGRN "\x1B[32m"
#define ll long long

//Starts board with 2 or 3 random values(2 or 4)
int starting_board(ll board[][4]);
//Prints full board
int print_board(ll board[4][4]);
//Asks user for next movement
int mvm_ask(char*);
//Checks if movement is valid and applies it
bool apply_mvm(char, ll board[][4]);
//Checks if the board is full 
bool is_full(ll board[4][4]);
//Check if there is any movement that the player can do
bool no_moves(ll board[4][4]);
//Tells user that he lost and finishes game
int end_game(bool*, ll board[4][4]);
//Adds new block in the board
int new_value(ll board[][4]);

int main(){
	bool ended = false;		
	ll board[4][4] = {0};
	char mvm, start;

	starting_board(board);
	system("clear");
	
	printf("╔═════════════════════════════════════════════════════════╗\n");
	printf("║                            2048!                        ║\n");
	printf("╠═════════════════════════════════════════════════════════╣\n");	
	printf("║  --  Objetivo: Montar um quadrado de valor 2048      -- ║\n");
	printf("║  --    	    Comandos: W/A/S/D                  -- ║\n");
	printf("║  --    	   Feito por: Girardin                 -- ║\n");
	printf("╚═════════════════════════════════════════════════════════╝\n");
	printf("Digite qualquer tecla para começar:\n");
	scanf(" %c", &start);
	system("clear");
	//Game loop
	while(!ended){
		print_board(board);
		mvm_ask(&mvm);
		if(apply_mvm(mvm, board)==false) continue;
		if(is_full(board) && no_moves(board)){
			end_game(&ended, board);
		}	
		else new_value(board);
	}
	return 0;
}

int starting_board(ll board[][4]){
	srand ( time(NULL) );
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

int print_board(ll board[4][4]){
	for(int i=0; i<4; i++){
		printf("|");
		for(int j=0; j<4;j++){
			if(board[i][j]!= 0) printf("%lld|", board[i][j]);
			else printf(" |");
		}	
		printf("\n");
	}	
	printf("\n");
	return 0;
}

int mvm_ask(char* mvm){
	printf("Faça seu movimento:\n");
	scanf(" %c", mvm);
}

bool apply_mvm(char mvm, ll board[][4]){
	int sum=0, last = 0, tmp, count;
	if(mvm == 'D' || mvm == 'd'){
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
					last=0;
					board[i][j]=0;
					j++;	
				}
				else last=board[i][j];
			}
		}
		system("clear");
		return true;
	}
	else if(mvm == 'S' || mvm =='s'){
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
					last=0;
					board[i][j]=0;
					i--;	
				}
				else last=board[i][j];
			}
		}
		system("clear");
		return true;
	}
	else if(mvm == 'A' || mvm =='a'){
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
					last=0;
					board[i][j]=0;
					j--;	
				}
				else last=board[i][j];
			}
		}
		system("clear");
		return true;
	}
	else if(mvm == 'W' || mvm =='w'){
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
					last=0;
					board[i][j]=0;
					i++;	
				}
				else last=board[i][j];
			}
		}
		system("clear");
		return true;
	}
	system("clear");
	return false;
}

bool is_full(ll board[4][4]){
	for(int i=0; i<4; i++){
		for(int j=0; j<4;j++){
			if(board[i][j]==0){
				return false;
			}
		}	
	}
	return true;	
}

bool no_moves(ll board[4][4]){
	return true;
}

int end_game(bool* ended, ll board[4][4]){
	system("clear");
	print_board(board);
	*ended = true;
	printf(KRED);
	printf("Game over!\n");
	printf(KNRM);
	return 0;
}

int new_value(ll board[][4]){
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
	return 0;	
}
