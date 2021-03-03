EXEC_NAME = bin/exec
OBJ_FILES = obj/main.o 
CC = g++
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/SFML/include
LIBS = -L./extern/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system


all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $^ -o $@ $(LIBS)
	

obj/main.o: src/main.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ src/main.cpp


clean:
	rm $(OBJ_FILES) $(EXEC_NAME)
