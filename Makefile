EXECS_NAME = bin/exec bin/exampletmx bin/maptest
OBJ_FILES = obj/main.o obj/exampletmx.o obj/maptest.o

CC = g++
CFLAGS = -Wall -ggdb -std=c++14

INCLUDE_SFML = -I./extern/SFML/include 
INCLUDE_TMX = -Iextern/tmxlite/include
LIBS_SFML = -Lextern/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system 
LIBS_TMX = -Lextern/tmxlite -ltmxlite


all: $(EXECS_NAME)


bin/exec : obj/main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML)

bin/exampletmx : obj/exampletmx.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML) $(LIBS_TMX)

bin/maptest : obj/maptest.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_TMX)



obj/main.o: src/main.cpp 
	$(CC) $(CFLAGS) $(INCLUDE_SFML) -c $^ -o $@

obj/exampletmx.o : src/mainTmxliteExample.cpp
	$(CC) $(CFLAGS) $(INCLUDES_SFML) $(INCLUDE_TMX) -c $^ -o $@

obj/maptest.o : src/mainMapTest.cpp
	$(CC) $(CFLAGS) $(INCLUDE_TMX) -c $^ -o $@



clean:
	rm $(OBJ_FILES) $(EXECS_NAME)

docs :
	doxygen doc/sfl.doxy