#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int** Morpion;

//Création et initialisation de la matrice du morpion
void InitMorpion() {
	Morpion = malloc(3*sizeof(int));

	for (int i=0; i<3; i++) {
		Morpion[i] = malloc(3*sizeof(int));
	}

	if (Morpion == NULL) {
		printf("Failed to create Morpion matrix");
		}

	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			Morpion[i][j] = 0;
		}
	}
}

void morpion_render() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++){
            printf("%d ", Morpion[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Propose un random move pour l'adversaire
void rand_move() {
	morpion_render();
	srand(time(0));
	int row = rand() % 3;
	printf("row = %d\n",row);
	int col = rand() % 3;
	printf("col = %d\n",col);
	while (Morpion[row][col]!=0) {
		srand(rand()%1908);
		int row2 = rand() % 3;
		int col2 = rand() % 3;
		if ((row != row2) && (col != col2)) {
			printf("yes\n");
			row = row2;
			col = col2;
		}
	}
	printf("sortie de boucle\n");
}

int main() {
	InitMorpion();
	Morpion[0][1] = 1;
	Morpion[1][1] = 2;
	Morpion[2][0] = 1;
	Morpion[1][2] = 2;
	rand_move();
	return 0;
	
}

/*printf("Premier nombre : %d\n",rand()%100);
	srand(time(0));
	printf("Second nombre : %d\n",rand()%100);
	srand(rand()%15089);
	printf("3e nombre : %d\n",rand()%100);
	srand(rand()%180919);
	printf("4e nombre : %d\n",rand()%100);
	srand(rand()%19610);
	printf("5e nombre : %d\n",rand()%100);
	srand(1);
	printf("Premier nombre : %d\n",rand()%100);
	srand(2);
	printf("Second nombre : %d\n",rand()%9+1); */