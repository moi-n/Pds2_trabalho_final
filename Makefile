CC = g++
CFLAGS = -std=c++11 -Wall
INCLUDES = -I include


SRC = $(wildcard src/*.cpp)
# wildcard is a function that returns a list of all files that match the pattern src/*.cpp

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
# % is a wildcard that matches any string of characters

EXEC = bin\teste.exe

all: $(EXEC)

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
