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

int main() {
	int i;
	InitMorpion();
	Morpion[0][1] = 1;
	Morpion[1][1] = 1;
	Morpion[2][0] = 1;
	Morpion[1][2] = 2;
	Morpion[0][2] = 1;
	morpion_render();
	i = Is_Winning();
	printf("i = %d\n",i);
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