#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int** Morpion;
int r;

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

/*
void Rand_Crea() {
	int** AleatoireC = malloc(9*sizeof(int *));
	int** AleatoireR = malloc(9*sizeof(int *));

	for (int i=0; i<9; i++) {
		AleatoireC[i] = malloc(9*sizeof(int));
		AleatoireR[i] = malloc(9*sizeof(int));
	}

	AleatoireR[0][0]=2,AleatoireR[0][1]=2,AleatoireR[0][2]=0,AleatoireR[0][3]=


	[2,2,0,0,0,1,1,1,2];
	AleatoireC[0] = [1,2,1,2,0,0,1,2,0];
} */

void Rand_Move(int id) {

	int row2;
	int col2;

	srand(r);
	r = rand();
	int row = rand() % 3;
	int col = rand() % 3;
	printf("row = %d\n",row);
	printf("col = %d\n\n",col);

	while (Morpion[row][col]!=0) {

		srand(r);
		r = rand();
		row2 = rand() % 3;
		col2 = rand() % 3;
		printf("row2 = %d\n",row2);
		printf("col2 = %d\n\n",col2);

		if ((row != row2) && (col != col2)) {
			row = row2;
			col = col2;
		}

	}

	Morpion[row][col] = id;
}

int Is_Winning() { //Renvoie 0 si pas de gagnant, 1 si les croix gagnent, 2 si les cercles l'emportent
	
	//Tests sur les colonnes
	if ((Morpion[0][0]==Morpion[1][0]) && (Morpion[1][0]==Morpion[2][0])) {
		return (Morpion[0][0]);
	}
	if ((Morpion[0][1]==Morpion[1][1]) && (Morpion[1][1]==Morpion[2][1])) {
		return (Morpion[0][1]);
	}
	if ((Morpion[0][2]==Morpion[1][2]) && (Morpion[1][2]==Morpion[2][2])) {
		return (Morpion[0][2]);
	}
	
	//Tests sur les lignes
	if ((Morpion[0][0]==Morpion[0][1]) && (Morpion[0][1]==Morpion[0][2])) {
		return (Morpion[0][0]);
	}
	if ((Morpion[1][0]==Morpion[1][1]) && (Morpion[1][1]==Morpion[1][2])) {
		return (Morpion[1][0]);
	}
	if ((Morpion[2][0]==Morpion[2][1]) && (Morpion[2][1]==Morpion[2][2])) {
		return (Morpion[2][0]);
	}
	
	//Test des diagonales
	if ((Morpion[0][0]==Morpion[1][1]) && (Morpion[1][1]==Morpion[2][2])) {
		return (Morpion[0][0]);
	}
	if ((Morpion[0][2]==Morpion[1][1]) && (Morpion[1][1]==Morpion[2][0])) {
		return (Morpion[1][1]);
	}
	
	else {
		return 0;
	}
}

void Morpion_Reset() {
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			Morpion[i][j] = 0;
		}
	}
}

int main() {
	int i;
	srand(time(0));
	r = rand();
	InitMorpion();
	Morpion[0][1] = 1;
	Morpion[1][1] = 1;
	Morpion[2][0] = 2;
	Morpion[1][2] = 2;
	Morpion[0][2] = 1;
	morpion_render();
	
	Rand_Move(2);
	printf("bis\n");
	Rand_Move(2);

	free(Morpion);
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