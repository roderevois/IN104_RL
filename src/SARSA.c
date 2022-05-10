 //QLearning
#include <stdlib.h>
#include "mazeEnv.h"
#include "functions.h"
#include <stdbool.h>

double** Q;

//Fonction de policy
enum action eps_greedy(float epsilon) {
	int r = 0;
	int a = 0;
	r = rand() % 1000;
	if (r<epsilon*1000) { //Action aléatoire
		
		return (enum action)(rand() % number_actions); }
		
	else { //On choisit une action qui maximise Q
		
		float m = Q[state_row*cols+state_col][0];
		for (int i=1; i<4; i++) {
			
			if (m<Q[state_row*cols+state_col][i]) {
				m = Q[state_row*cols+state_col][i];
				a = i; }
				}
		if (a==0) {
			return up; }
		if (a==1) {
			return down; }
		if (a==2) {
			return left; }
		if (a==3) {
			return right; }
		}
	}

//Implémentation de la fonction Q-learning
//Initialisation
void QInitialisation() {
	//Création de la matrice - Les matrices maze et Q suivent le même ordonnancement des cases;
	//Lecture: Cases lues vers la droite sur la ligne, puis on descend d'une ligne, on se replace en début de ligne
	Q = malloc(rows*cols*sizeof(double *));
	for (int i=0; i<rows*cols; i++) {
		Q[i] = malloc(4*sizeof(double)); //0 : up, 1 : down, 2 : left, 3 : right
		}
	if (Q == NULL) {
		printf("Failed to create Q matrix");
		}
	
	for (int i=0; i<rows*cols; i++) { //Remplissage de la matrice Q
		for (int j=0; j<4; j++) {
			Q[i][j] = 1;
			}
		}

	for (int j=0; j<4; j++) { //L'arrivée est à 0
		Q[goal_row*cols+goal_col][j] = 0; }
	//return Q;
	}

//Training
void QTraining (int i_max, float epsilon, float alpha, float gamma) {

	printf("GoalRow = %d, GoalCol = %d\n", goal_row, goal_col);
	
	for (int i = 0; i<i_max; i++) {

		printf("i = %d\n",i);
		maze_reset();
		//printf("InitRow: %d, InitCol: %d\n",state_row,state_col);

		while (!((state_row == goal_row) && (state_col == goal_col))) {
				
			//printf("(%d, %d)\n",state_row,state_col);
			action a = eps_greedy(epsilon);
			struct envOutput new_output = maze_step(a);
			
			float reward = new_output.reward;
			int new_col = new_output.new_col;
			int new_row = new_output.new_row;
			
			//On applique la formule à condition de ne pas rentrer dans un mur. On en fait la verification
			int* current = &visited[new_row][new_col];
			//printf("%c\n", maze[new_row][new_col]);
			
			//bool btd = ((*current) == !(wall));
			//printf("%d\n", btd); -> On ne rentre pas dans la boucle if quand "g" est sur la case !!!
			
			if ((*current) == !(wall) || (*current) == (goal)) {
				//Calcul du reward(t+1) apparaissant dans la formule
				float fut_reward = Q[new_row*cols + new_col][0];
				for (int i=0; i<4; i++) {
					fut_reward = max(fut_reward, Q[new_row*cols + new_col][0]);
					}
				
				//On met à jour la matrice Q
				Q[state_row*cols+state_col][a] = Q[state_row*cols+state_col][a] + alpha*(reward + gamma*fut_reward - Q[state_row*cols+state_col][a]);
				
				//Mise à jour du "s" de l'algorithme
				state_row = new_row;
				state_col = new_col;
				
				}
				//else {
				//Q[state_row*cols+state_col][a] = Q[state_row*cols+state_col][a] - 0.005; }
				
			
			//Si nous ne sommes pas rentrés dans la boucle if, nous étions dans un mur et on retrouve une nouvelle action via la policy comme si rien ne s'était passé
			}
		//printf("SortieWhileRow = %d, SortieWhileCol = %d\n",state_row,state_col );
		}
	printf("5\n");
	}

void Q_render(){
     for (int i=0; i<rows*cols; i++) {
         for (int j=0; j<4; j++){
             printf("%f ", Q[i][j]);
         }
         printf("\n");
     }
     printf("\n");
}

int main() {
	maze_make("maze.txt");
  	init_visited();
  	maze_render();
  	
  	float epsilon = 0.5;
  	float alpha = 0.5;
  	float gamma = 0.5;
  	printf("%d, %d \n", rows, cols);
   	printf("number of actions :  %d \n", number_actions);
   	QInitialisation();
   	Q_render();
   	QTraining(2000,epsilon,alpha,gamma);
   	Q_render();
   	
   	free(visited);
   	free(maze);
   	free(Q);
   	return 0; }


	