EXECS_NAME = bin/exec 
OBJ_FILES = obj/main.o obj/Layer.o obj/tmxParsing.o obj/Tileset.o obj/Map.o obj/MapLayer.o

CC = g++
CFLAGS = -Wall -ggdb -std=c++14

INCLUDE_SFML = -I./extern/SFML/include 
LIBS_SFML = -Lextern/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system 

COMPILATIONOBJ = $(CC) $(CFLAGS) -c $< -o $@ 


all: $(EXECS_NAME)

bin/exec : $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML)

obj/main.o: src/main.cpp src/Map/tmxParsing.h src/Map/Layers/Layer.h src/Map/Tileset.h src/Map/Map.h src/Map/Layers/MapLayer.h
	$(COMPILATIONOBJ)
obj/Map.o : src/Map/Map.cpp src/Map/Map.h src/Map/Tileset.h src/Map/Layers/Layer.h src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/Tileset.o : src/Map/Tileset.cpp src/Map/Tileset.h src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/Layer.o : src/Map/Layers/Layer.cpp src/Map/Layers/Layer.h src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/MapLayer.o : src/Map/Layers/MapLayer.cpp src/Map/Layers/MapLayer.h  src/Map/Layers/Layer.h src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/Box.o : src/Collision/Box.cpp src/Box.h
	$(COMPILATIONOBJ)

obj/CollisionBox.o : src/CollisionBox.cpp src/CollisionBox.h src/Box.h
	$(COMPILATIONOBJ)

obj/CollisionLayer.o : src/Layers/CollisionLayer.cpp src/Layers/CollisionLayer.h src/Layers/Layer.h src/Layers/CollisionBox.h
	$(COMPILATIONOBJ)

obj/SpawnPoint.o : src/Map/SpawnPoint.cpp src/Map/SpawnPoint.h srx/Box.h
	$(COMPILATIONOBJ)

obj/SpawnsLayer.o : src/Layers/SpawnsLayer.cpp src/Layers/SpawnsLayer.h src/Layers/Layer.h src/SpawnPoint.h
	$(COMPILATIONOBJ)

obj/tmxParsing.o: src/Map/tmxParsing.cpp src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

clean:
	rm $(OBJ_FILES) $(EXECS_NAME)

docs :
	doxygen doc/sfl.doxy