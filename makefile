all: main

CC:=gcc
CFLAGS:= -Wall
LDFLAGS:=  -lMLV -lm 

bullet.o: src/bullet.c
	$(CC) -c src/bullet.c $(CFLAGS) $(LDFLAGS)

ship.o: src/ship.c
	$(CC) -c src/ship.c $(CFLAGS) $(LDFLAGS)

interface.o: src/interface.c 
	$(CC) -c src/interface.c $(CFLAGS) $(LDFLAGS)

animations.o: src/animations.c
	$(CC) -c src/animations.c $(CFLAGS) $(LDFLAGS)

game.o: src/game.c 
	$(CC) -c src/game.c $(CFLAGS) $(LDFLAGS)

main.o: src/main.c 
	$(CC) -c src/main.c $(CFLAGS) $(LDFLAGS)

main: bullet.o ship.o interface.o animations.o game.o main.o
	$(CC) -o main bullet.o ship.o interface.o animations.o game.o main.o $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o
	rm main