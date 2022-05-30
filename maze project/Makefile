#Makefile

CC=gcc
CFLAGS=-W -Wall -Werror -Wfatal-errors -lm
INC=-I include/
SRC=src/
EXEC=Q_Learning

all: $(EXEC) clean

Q_Learning: $(SRC)Q_Learning.o $(SRC)functions.o $(SRC)mazeEnv.o
	$(CC) $(INC) -g -o $(SRC)$@ $^ $(CFLAGS)

$(SRC)%.o: $(SRC)%.c 
	$(CC) $(INC) -g -o $@ -c $< $(CFLAGS)

clean: 
	rm -rf $(SRC)*.o $(EXEC)

