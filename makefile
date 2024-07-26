# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/client.c src/voiture.c src/location.c src/menu.c src/manager.c
OBJ = $(SRC:.c=.o)
BIN = bin/location_voiture

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJ)
    mkdir -p bin
    $(CC) $(OBJ) -o $(BIN)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(BIN)
