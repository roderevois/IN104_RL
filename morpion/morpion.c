//Morpion
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

double** Q;
int** Morpion;
int length = 19683;
/*Valeurs utiles
3^8 = 6561
3^7 = 2187
3^6 = 729
3^5 = 243
3^4 = 81
3^3 = 27
3^2 = 9 */

//Initialisation
void QInitialisation() {

	//Il y a 3⁹=19683 états possibles
	Q = malloc(19683*sizeof(double *));
	for (int i=0; i<19683; i++) {
		//9 actions possibles : placer dans chaque case
		Q[i] = malloc(9*sizeof(double));
	}

	if (Q == NULL) {
		printf("Failed to create Q matrix");
	}
	
	int indice;
	
	//Case vide = 0, Croix = 1, Cercle = 2
	for (int a1 = 0; a1<3; a1++) {
		for (int a2 = 0; a2<3; a2++) {
			for (int a3 = 0; a3<3; a3++) {
				for (int a4 = 0; a4<3; a4++) {
					for (int a5 = 0; a5<3; a5++) {
						for (int a6 = 0; a6<3; a6++) {
							for (int a7 = 0; a7<3; a7++) {
								for (int a8 = 0; a8<3; a8++) {
									for (int a9 = 0; a9<3; a9++) {
		
		//Hash désignant l'état
		indice = 6561*a1 + 2187*a2 + 729*a3 + 243*a4 + 81*a5 + 27*a6 + 9*a7 + 3*a8 + a9;
		
		//On se place dans chaque état possible : Initialisation optimiste de toutes les cases
		for (int i = 0; i<9; i++) {
			Q[indice][i] = 1; 
		}
		
		//Pénalisation des cases occupées qu'on a pas envie de tirer comme action si la méthode du maximum est utilisée
		if (a9 != 0) { //Case du bas droite = 9ème colonne
			Q[indice][8] = 0; 
		}
		if (a8 != 0) {
			Q[indice][7] = 0; 
		}
		if (a7 != 0) {
			Q[indice][6] = 0; 
		}
		if (a6 != 0) {
			Q[indice][5] = 0; 
		}
		if (a5 != 0) {
			Q[indice][4] = 0; 
		}
		if (a4 != 0) {
			Q[indice][3] = 0; 
		}
		if (a3 != 0) {
			Q[indice][2] = 0; 
		}
		if (a2 != 0) {
			Q[indice][1] = 0; 
		}
		if (a1 != 0) { //Case haut droite = 1ère colonne
			Q[indice][0] = 0; 
		}
		
									}
								}
							}
						}
					}
				}
			}
		}
	}	
}

int is_winning() { //Renvoie 0 si pas de gagnant, 1 si les croix gagnent, 2 si les cercles l'emportent
	
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
		return (Morpion[1][0]);
	}
	
	else {
		return 0;
	}
}

//Affiche la matrice Q entre les lignes start line et end line
void Q_render(int sline, int eline){

	if (sline > eline) {
		exit(1);
	}

	if (sline<0) {
		exit(2);
	}

    for (int i=sline; i<eline; i++) {
        for (int j=0; j<9; j++){
            printf("%f ", Q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Affiche la grille de morpion actuelle
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
	int row2;
	int col2;
	int r;

	srand(time(0));
	int row = rand() % 3;
	int col = rand() % 3;

	while (Morpion[row][col]!=0) {

		r = rand() % 300;
		srand(rand() % r);
		row2 = rand() % 3;
		col2 = rand() % 3;

		if ((row != row2) && (col != col2)) {
			row = row2;
			col = col2;
		}
	}
}

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

/*  //Paramètres de Reinforcement Learning
	float epsilon = 0.5;
  	float alpha = 0.5;
  	float gamma = 0.5; */

int main() {
	InitMorpion();
	morpion_render();
	
	QInitialisation();
	Q_render(6550,6570);

	free(Morpion);
	free(Q);
	return 0;
	}
