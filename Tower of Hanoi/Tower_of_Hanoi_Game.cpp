#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

#define NOT_VALID "\x1B[31mEssa movimentação não é válida!\n\n \x1B[0m"
#define VALID "Movimentação realizada!\n\n"
#define CONGRATS "Parabéns, você ganhou!\n\n"
#define KGRN  "\x1B[32m"

//Prints the 3 tower structures
int print_towers(stack<int>, stack<int>, stack<int>, int);
//Pops the top element from some tower and pushes it to another one if allowed
bool swap_top(stack<int>&, stack<int>&);
//Asks user for the number of pieces of the game (between 1 and 6)
int pieces_request(int* size);
//Asks user for next movement
int mvm_ask(int*, int*);
//Translates int movement input from user to stack
stack<int>* finds_tower(int, stack<int>&, stack<int>&, stack<int>&);
//Checks if movement is valid and applies it
int apply_mvm(int, int, stack<int>&, stack<int>&, stack<int>&);
//Checks if towerB or towerC have all pieces of the game
bool is_game_ended(const stack<int>&,const stack<int>&,const stack<int>&);
//Prints congratulations and finishes game
int end_game(const stack<int>&, const stack<int>&, const stack<int>&, bool*, int);


int main(){
	bool ended = false;
	int tout, tin, size;
	stack<int> towerA, towerB, towerC;

	pieces_request(&size);

	//Filling first tower
	for(int i=size; i>=1; i--){
		towerA.push(i);	
	}

	//Game loop
	while(!ended){
		print_towers(towerA, towerB, towerC, size);
		mvm_ask(&tout, &tin);
		apply_mvm(tin, tout, towerA, towerB, towerC);

		if(is_game_ended(towerA, towerB, towerC)){
			end_game(towerA, towerB, towerC, &ended , size);	
		}
	}
	
	return 0;
}


int print_towers(stack<int> a, stack<int> b, stack<int> c, int size){
	int size_a = a.size(), size_b = b.size(), size_c = c.size();
	int tmp_a, tmp_b, tmp_c;
	int i, j;

	for(i = 0; i < size+1; i++){
		printf("\a\t\t\t\t");
		if(size_a + i >= size+1){
			tmp_a = a.top();
			a.pop();
			for(j = 0; j<tmp_a; j++){
				printf("\b");			
			}
			for(j = 0; j<tmp_a; j++){
				printf("-");			
			}
			printf("|");	
			for(j = 0; j<tmp_a; j++){
				printf("-");			
			}
			printf("\t\t");
		}	
		else{
			printf("|");
			printf("\t\t");
		}

		if(size_b + i >= size+1){
			tmp_b = b.top();
			b.pop();
			for(j = 0; j<tmp_b; j++){
				printf("\b");			
			}
			for(j = 0; j<tmp_b; j++){
				printf("-");			
			}
			printf("|");	
			for(j = 0; j<tmp_b; j++){
				printf("-");			
			}
			printf("\t\t");
		}	
		else{
			printf("|");
			printf("\t\t");
		}	
		if(size_c + i >= size+1){
			tmp_c = c.top();
			c.pop();
			for(j = 0; j<tmp_c; j++){
				printf("\b");			
			}
			for(j = 0; j<tmp_c; j++){
				printf("-");			
			}
			printf("|");	
			for(j = 0; j<tmp_c; j++){
				printf("-");			
			}
		}	
		else{
			printf("|");
		}
		printf("\n");
	}
	return 0;
}


bool swap_top(stack<int>& a, stack<int>& b){
	int topA = (a.empty() ? 0 : a.top()), topB = (b.empty() ? 0 : b.top());
	
	if (!topA){
		return false;	
	}
	else if(b.empty() || topA < topB){
		a.pop();
		b.push(topA);
		return true;		
	}
	else return false;
}

int pieces_request(int* size){
	bool fair_choice = false;
	while(fair_choice == false){
		printf("Escolha o número de peças do seu jogo (até 6 peças):\n");
		scanf("%d", size);
		if (*size>=1 && *size<=6){
			fair_choice = true;		
		}
		else printf("\x1B[31mVocê não pode escolher esse número!\n\x1B[0m");
	}
	system("clear");
	printf("\n");
	return 0;
}

int mvm_ask(int* tout, int* tin){
	printf("Digite a sua movimentação:\n");
	scanf(" %d %d", tout, tin);
	system("clear");
	return 0;
}

stack<int>* finds_tower(int a, stack<int>& towerA, stack<int>& towerB, stack<int>& towerC){
	if(a == 1){
		return &towerA;
	}
	else if (a == 2){
		return &towerB;	
	}
	else{
		return &towerC;	
	}
}

int apply_mvm(int tin,int tout, stack<int>& towerA, stack<int>& towerB, stack<int>& towerC){
	if(tin==tout || tin>3 || tout>3 || tin<1 || tout<1){	
		printf(NOT_VALID);
		return 0;
	}

	if(!swap_top(*(finds_tower(tout, towerA, towerB, towerC)), *(finds_tower(tin, towerA, towerB, towerC)))){
		printf(NOT_VALID);
	}
	else{
		printf(VALID);
	}	
	return 0;
}

bool is_game_ended(const stack<int>& towerA,const stack<int>& towerB,const stack<int>& towerC){
	return towerA.empty() && (towerB.empty() || towerC.empty());
}

int end_game(const stack<int>& towerA, const stack<int>& towerB, const stack<int>& towerC, bool* ended, int size){
	*ended = true;	
	print_towers(towerA, towerB, towerC, size);
	printf("%s\n", KGRN);
	printf(CONGRATS);
	return 0;
}
