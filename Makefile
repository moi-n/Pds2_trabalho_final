CC=g++
#CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin

all: $(BIN_DIR)/main

$(OBJ_DIR)/casa.o: $(INCLUDE_DIR)/casa.hpp $(SRC_DIR)/casa.cpp
	$(CC) -c $(SRC_DIR)/casa.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/casa.o

$(OBJ_DIR)/tabuleiro.o: $(INCLUDE_DIR)/casa.hpp $(INCLUDE_DIR)/tabuleiro.hpp $(SRC_DIR)/tabuleiro.cpp
	$(CC) -c $(SRC_DIR)/tabuleiro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/tabuleiro.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/casa.hpp $(INCLUDE_DIR)/tabuleiro.hpp $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

$(BIN_DIR)/main: $(OBJ_DIR)/main.o $(OBJ_DIR)/casa.o $(OBJ_DIR)/tabuleiro.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/casa.o $(OBJ_DIR)/tabuleiro.o -o $(BIN_DIR)/main

clean:
	rm -f $(BIN_DIR)/main $(OBJ_DIR)/*.o