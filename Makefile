CC = g++
CFLAGS = -std=c++11 -Wall
INCLUDES = -I include


SRC = $(wildcard src/*.cpp)
# wildcard is a function that returns a list of all files that match the pattern src/*.cpp

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
# % is a wildcard that matches any string of characters

EXEC = bin/main.exe
EXEC2 = bin/teste_jogador.exe
EXEC3 = bin/teste_reversi.exe
EXEC4 = bin/teste_gomoku.exe
EXEC5 = bin/teste_lig4.exe
EXEC6 = bin/teste_barco.exe
EXEC7 = bin/teste_batalhanaval.exe

all: $(EXEC) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)

$(EXEC2): src/jogador.cpp
	$(CC) $(INCLUDES) $(CFLAGS) tests/teste_jogador.cpp src/jogador.cpp -o $(EXEC2)

$(EXEC3): src/reversi.cpp src/tabuleiro.cpp src/casa.cpp 
	$(CC) $(INCLUDES) $(CFLAGS) tests/teste_reversi.cpp src/reversi.cpp src/tabuleiro.cpp src/casa.cpp -o $(EXEC3) 

$(EXEC4): src/gomoku.cpp src/tabuleiro.cpp src/tabuleirofileira.cpp src/casa.cpp 
	$(CC) $(INCLUDES) $(CFLAGS) tests/teste_gomoku.cpp src/gomoku.cpp src/tabuleiro.cpp src/casa.cpp src/tabuleirofileira.cpp -o $(EXEC4)

$(EXEC5): src/lig4.cpp src/tabuleiro.cpp src/tabuleirofileira.cpp src/casa.cpp
	$(CC) $(INCLUDES) $(CFLAGS) tests/teste_lig4.cpp src/lig4.cpp src/tabuleiro.cpp src/tabuleirofileira.cpp src/casa.cpp -o $(EXEC5)

$(EXEC6): src/barco.cpp src/ponto.cpp
	$(CC) $(INCLUDES) $(CFLAGS) tests/teste_barco.cpp src/barco.cpp src/ponto.cpp -o bin/teste_barco.exe

$(EXEC7): src/batalhanaval.cpp src/barco.cpp src/tabuleiro.cpp src/casa.cpp
	$(CC) $(INCLUDES) $(CFLAGS) src/batalhanaval.cpp src/barco.cpp src/tabuleiro.cpp src/casa.cpp -o bin/teste_batalhanaval.exe
	
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ 
# $@ is the name of the target
#$^ is the name of the dependencies

obj/%.o: src/%.cpp 
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@
# $< is the name of the first dependency
# tell make to build the .o file , regardless of whether there is a corresponding .hpp

clean:
	del /Q obj\*.o
	del /Q $(EXEC)
