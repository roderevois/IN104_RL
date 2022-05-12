//Morpion
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

//Q Matrix
double** Q;

//Morpion
int** Morpion;

//Nombre de lignes de Q = Nombre d'états possibles d'un morpion 3⁹
int length = 19683;

//Nombre aléatoire de début de chaine
int r;

/*
Quelques valeurs utiles
3^8 = 6561
3^7 = 2187
3^6 = 729
3^5 = 243
3^4 = 81
3^3 = 27
3^2 = 9 
*/

//Initialisation
void Q_Initialisation() {

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

//Création et initialisation de la matrice du morpion
void Init_Morpion() {
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

//Remet la grille à 0
void Morpion_Reset() {
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


//Affiche la matrice Q entre les lignes start line et end line
void Q_Render(int s_line, int e_line){

	if (s_line > e_line) {
		exit(1);
	}

	if (s_line<0) {
		exit(2);
	}

    for (int i=s_line; i<e_line; i++) {
        for (int j=0; j<9; j++){
            printf("%f ", Q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
Propose un placement aléatoire pour l'adversaire

L'utilisation des fonctions rand() et srand(time(0)) sont inefficaces ici puisque dépendant du temps, l'exécution
est plus rapide que l'évolution de l'horloge et donc l'aléatoire en est biasé; Fournissant les mêmes positions
plusieurs parties d'affilées (le temps que l'horloge se mette à jour soit ~10-15 ms). On utilise une chaine de nombres
mis à jour avec la seed précédent pour servir de seed pour le suivant. Cette suite de nombre est dépendante de
de la seed initiale. 
*/
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

void Q_Training(int i_max, float epsilon, float alpha, float gamma) {
	
	//A qui le tour, on fait commencer chacun son tour les adversaires
	int tour = 0;
	int sub_tour;

	//Initialisation de l'aléatoire
	srand(time(0));
	r = rand();

	//Compteur de victoires
	int vict_rand = 0;
	int vict_q = 0;

	int Win;

	for (int i = 0; i<i_max; i++) {
		
		//Reset en début de boucle
		Morpion_Reset();
		Win = 0;

		printf("i = %d\n",i);

		sub_tour = tour;

		//Corps de l'algorithme de QLearning
		while(Win == 0) {

			if ((sub_tour % 2) == 0) { //L'agent joue
				
				

			}

			else { //L'agent aléatoire joue
				
				//Mise à jour du morpion
				Rand_Move(2);

			}

			//Si un vainqueur est trouvé on sort de la boucle
			Win = Is_Winning();

			//Au suivant
			sub_tour = sub_tour + 1;
		}

		//Mise à jour des compteurs
		if (Win == 1) { //L'agent prend a les croix (1)
			vict_q = vict_q + 1;
		}
		else { //L'adversaire aléatoire a les cercles (2)
			vict_rand = vict_rand + 1;
		}

		printf("Morpion en sortie :\n");
		Morpion_Render();

		//Le tour de commencer passe à l'autre
		tour = (tour+1) % 2;
	}
}

int main() 
{
	Init_Morpion();
	Morpion_Render();
	
	//Paramètres de Reinforcement Learning
	int i_max = 10;
	float epsilon = 0.5;
  	float alpha = 0.5;
  	float gamma = 0.5;

	Q_Initialisation();
	Q_Render(5050,5070);

	Q_Training(i_max,epsilon,alpha,gamma);

	Q_Render(5050,5070);
	free(Morpion);
	free(Q);
	return 0;
}
