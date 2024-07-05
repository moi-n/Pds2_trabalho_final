CC=g++
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin
RM=rm -rf

all: $(BIN_DIR)/jogodavelha.exe

$(OBJ_DIR)/casa.o: $(INCLUDE_DIR)/casa.hpp $(SRC_DIR)/casa.cpp
	$(CC) -c $(SRC_DIR)/casa.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/casa.o

$(OBJ_DIR)/tabuleiro.o: $(INCLUDE_DIR)/casa.hpp $(INCLUDE_DIR)/tabuleiro.hpp $(SRC_DIR)/tabuleiro.cpp
	$(CC) -c $(SRC_DIR)/tabuleiro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/tabuleiro.o

$(OBJ_DIR)/jogodavelha.o: $(INCLUDE_DIR)/casa.hpp $(INCLUDE_DIR)/tabuleiro.hpp $(SRC_DIR)/jogodavelha.cpp
	$(CC) -c $(SRC_DIR)/jogodavelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogodavelha.o

$(BIN_DIR)/jogodavelha.exe: $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/casa.o $(OBJ_DIR)/tabuleiro.o
	$(CC) $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/casa.o $(OBJ_DIR)/tabuleiro.o -o $(BIN_DIR)/jogodavelha.exe

clean:
	rm -f $(BIN_DIR)/jogodavelha.exe $(OBJ_DIR)/*.o