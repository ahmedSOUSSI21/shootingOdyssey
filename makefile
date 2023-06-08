all: main

CC:=gcc
CFLAGS:= -Wall -Werror -g
LDFLAGS:=  -lMLV -lm 

bullet.o: src/bullet.c
	$(CC) -c src/bullet.c $(CFLAGS) 

ship.o: src/ship.c
	$(CC) -c src/ship.c $(CFLAGS)

in_out.o: src/in_out.c 
	$(CC) -c src/in_out.c $(CFLAGS)

interface.o: src/interface.c 
	$(CC) -c src/interface.c $(CFLAGS)

animations.o: src/animations.c
	$(CC) -c src/animations.c $(CFLAGS)

game.o: src/game.c 
	$(CC) -c src/game.c $(CFLAGS) 

menu.o: src/menu.c 
	$(CC) -c src/menu.c $(CFLAGS) 

main.o: src/main.c 
	$(CC) -c src/main.c $(CFLAGS)

main: bullet.o ship.o in_out.o interface.o animations.o game.o menu.o main.o
	$(CC) -o main bullet.o ship.o in_out.o interface.o animations.o game.o menu.o main.o $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o
	rm main
#
#CC = gcc
#CFLAGS = -Wall -Werror
#SRC_DIR = src
#OBJ_DIR = obj
#EXECUTABLE = TP10
#
## Liste des fichiers source
#SRCS = $(wildcard $(SRC_DIR)/*.c)
#
## Génère le nom des fichiers objets à partir des fichiers sources
#OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
#
#.PHONY: all clean
#
#all: $(EXECUTABLE)
#
#$(EXECUTABLE): $(OBJS)
#	$(CC) $(CFLAGS) $^ -o $@
#
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) $(CFLAGS) -c $< -o $@
#
#clean:
#	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)