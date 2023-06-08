CC = gcc
CFLAGS = -Wall -Werror -g
LDFLAGS:= -lMLV -lm
SRC_DIR = src
OBJ_DIR = bin
EXECUTABLE = main

##Liste des fichiers source
SRCS = $(wildcard $(SRC_DIR)/*.c)

## Génère le nom des fichiers objets à partir des fichiers sources
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)