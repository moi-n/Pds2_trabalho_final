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

$(OBJ_DIR)/player.o: $(INCLUDE_DIR)/player.hpp $(SRC_DIR)/player.cpp
	$(CC) -c $(SRC_DIR)/player.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/player.o

$(BIN_DIR)/jogodavelha.exe: $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/casa.o $(OBJ_DIR)/tabuleiro.o
	$(CC) $(OBJ_DIR)/jogodavelha.o $(OBJ_DIR)/casa.o $(OBJ_DIR)/tabuleiro.o -o $(BIN_DIR)/jogodavelha.exe

clean:
	@echo "clean project"
	cd $(BIN_DIR) && del jogodavelha.exe 
	cd $(OBJ_DIR) && del *.o
	@echo "clean completed"