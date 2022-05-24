##TABLE OF CONTENTS
* [Author](#authors)
* [Context & Objectives](#context)
* [General Info on the project](#general-info)
* [How to use](#use)

## Authors
This project was created by Roderick Revois & Olivier Ledard as part of the teaching unit IN104 of the French University ENSTA Paris.  

## Context & Objectives
Said project was realised to learn and make a first step in the world of machine learning and more precisely of Reinforcement Learning, which was used for the two parts.  
  
1) We first implement QLearning algorithms to find the exit of a labyrinth, without first knowledge of the maze structure.  
2) We then use the QLearning & SARSA algorithms in the environement of the tic-tac-toe game, to train the machine.  

## General Information
1) The first part of the project was to use the QLearning algorithm to find the exit of a maze.  
Loading the QLearning.c file, you can change the different characteristics of the project directly at the top of the file.  
  
i_max : number of iterations  
epsilon : random factor  
alpha   : learning rate  
gamma   : actualization rate  
The initial parameters work perfectly though, and were found to be more or less the most optimized parameters for _our_ project.  
  
The training can then be launched with the command :  
                *gcc -o *NameOfTheExecutable* -lm functions.c mazeEnv.c QLearning.c -lm*  
Or using the makefile
  
2) The second part of the project deals with The Tic-Tac-Toe game. We attempt to train the computer to play the game, and it succeeds !  
This part can use both QLearning and SARSA algorithms, though as we worked all the project with QLearning we strongly recomand its use. The SARSA algorithm is running, but non optimized yet and gives bad results. This algorithm will be optimized in the next days.  
  
Loading 
