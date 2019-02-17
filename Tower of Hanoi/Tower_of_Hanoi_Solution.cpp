#include <stdio.h>

int tower_hanoi(int size, int start, int end){
	if(size == 1){
		printf("Passe a peça %d da posição %d para a posição %d;\n", 1, start, end);
		return 0;	
	}
	tower_hanoi(size-1, start, 6-start-end);
	printf("Passe a peça %d da posição %d para a posição %d;\n", size, start, end);
	tower_hanoi(size-1, 6-start-end, end);
}

int main(){
	int quantity;
	printf("Escolha a quantidade de peças da sua torre:\n");
	scanf("%d", &quantity);
	printf("A solução da torre é dada por:\n");
	tower_hanoi(quantity, 1, 3);
	return 0;
}
