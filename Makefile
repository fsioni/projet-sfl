EXECS_NAME = bin/exec 
OBJ_FILES = obj/main.o obj/Layer.o obj/tmxParsing.o obj/Tileset.o

CC = g++
CFLAGS = -Wall -ggdb -std=c++14

INCLUDE_SFML = -I./extern/SFML/include 
LIBS_SFML = -Lextern/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system 



all: $(EXECS_NAME)

bin/exec : $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML)

obj/main.o: src/main.cpp src/tmxParsing.h src/Layer.h src/Tileset.h
	$(CC) $(CFLAGS) $(INCLUDE_SFML) -c $< -o $@

obj/Tileset.o : src/Tileset.cpp src/Tileset.h src/tmxParsing.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/Layer.o : src/Layer.cpp src/Layer.h src/tmxParsing.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/tmxParsing.o: src/tmxParsing.cpp src/tmxParsing.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ_FILES) $(EXECS_NAME)

docs :
	doxygen doc/sfl.doxy