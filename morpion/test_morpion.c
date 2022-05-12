#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

int** Morpion;
int r;

int cxa;
int cxb;

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

void Morpion_Render() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++){
            printf("%d ", Morpion[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Rand_Move(int id) {

	int row2;
	int col2;

	srand(r);
	r = rand();
	int row = rand() % 3;
	int col = rand() % 3;

	while (Morpion[row][col]!=0) {

		srand(r);
		r = rand();
		row2 = rand() % 3;
		col2 = rand() % 3;

		if ((row != row2) && (col != col2)) {
			row = row2;
			col = col2;
		}

	}

	Morpion[row][col] = id;
}

//Fonction de policy
/*void eps_greedy(float epsilon) {
	int a = 0;
	r = rand() % 1000;
	if (r<=epsilon*1000) { //Action aléatoire
		
		return (enum action)(rand() % number_actions); 
	}
		
	else { //On choisit une action qui maximise Q
		
		float m = Q[state_row*cols+state_col][0];
		for (int i=1; i<4; i++) {
			
			if (m<Q[state_row*cols+state_col][i]) {
				m = Q[state_row*cols+state_col][i];
				a = i; 
			}
		}

		if (a==0) {
			return up; 
		}
		if (a==1) {
			return down; 
		}
		if (a==2) {
			return left; 
		}
		else {
			return right; 
		}
	}
}*/

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

/*
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
	Morpion_Render();
	
	Rand_Move(2);
	printf("bis\n");
	Rand_Move(2);

	free(Morpion);
	return 0;
	
}
*/

void fonction_test(float epsilon) {

	srand(r);
	r = rand();
	int rd = rand() % 1000;

	if (rd<=epsilon*1000) { //Action aléatoire
		cxa = cxa + 1;
	}
	else {
		cxb = cxb + 1;
	}
}

int main() {

	cxa = 0;
	cxb = 0;
	srand(time(0));
	r = rand();

	float epsilon = 0.5;
	for (int i=0; i<20000; i++) {
			fonction_test(epsilon);
	}
	printf("cxa = %d\n",cxa);
	printf("cxb = %d\n",cxb);
	return 0;
}
