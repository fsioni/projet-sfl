EXECS_NAME = bin/exec bin/exampletmx
OBJ_FILES = obj/main.o obj/exampletmx.o

CC = g++
CFLAGS = -Wall -ggdb

INCLUDE_SFML = -I./extern/SFML/include 
INCLUDE_TMX = -Iextern/tmxlite/
LIBS_SFML = -L./extern/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system 
LIBS_TMX = -Lextern/tmxlite -ltmxlite


all: $(EXECS_NAME)


bin/exec : obj/main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML)

bin/exampletmx : obj/exampletmx.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML) $(LIBS_TMX)



obj/main.o: src/main.cpp 
	$(CC) $(CFLAGS) $(INCLUDE_SFML) -c $^ -o $@

obj/exampletmx.o : src/mainTmxliteExample.cpp
	$(CC) $(CFLAGS) $(INCLUDES_SFML) $(INCLUDE_TMX) -c $^ -o $@



clean:
	rm $(OBJ_FILES) $(EXECS_NAME)

docs :
	doxygen doc/sfl.doxy