EXECS_NAME = bin/exec 
OBJ_FILES = obj/main.o obj/Layer.o obj/tmxParsing.o obj/Tileset.o obj/Map.o obj/MapLayer.o obj/CollisionLayer.o obj/SpawnPoint.o obj/SpawnPoint.o obj/SpawnsLayer.o obj/Box.o obj/CollisionBox.o obj/StateManager.o

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
obj/Map.o : src/Map/Map.cpp src/Map/Map.h src/Map/Tileset.h src/Map/Layers/Layer.h src/Map/tmxParsing.h src/Map/Box.h
	$(COMPILATIONOBJ)

obj/Tileset.o : src/Map/Tileset.cpp src/Map/Tileset.h src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/Layer.o : src/Map/Layers/Layer.cpp src/Map/Layers/Layer.h src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/MapLayer.o : src/Map/Layers/MapLayer.cpp src/Map/Layers/MapLayer.h  src/Map/Layers/Layer.h src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/Box.o : src/Map/Box.cpp src/Map/Box.h
	$(COMPILATIONOBJ)

obj/CollisionBox.o : src/Map/CollisionBox.cpp src/Map/CollisionBox.h src/Map/Box.h
	$(COMPILATIONOBJ)

obj/CollisionLayer.o : src/Map/Layers/CollisionLayer.cpp src/Map/Layers/CollisionLayer.h src/Map/Layers/Layer.h src/Map/CollisionBox.h
	$(COMPILATIONOBJ)

obj/SpawnPoint.o : src/Map/SpawnPoint.cpp src/Map/SpawnPoint.h src/Map/Box.h
	$(COMPILATIONOBJ)

obj/SpawnsLayer.o : src/Map/Layers/SpawnsLayer.cpp src/Map/Layers/SpawnsLayer.h src/Map/Layers/Layer.h src/Map/SpawnPoint.h
	$(COMPILATIONOBJ)

obj/tmxParsing.o: src/Map/tmxParsing.cpp src/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/StateManager.o : src/StateManager/StateManager.cpp src/StateManager/State.h
	$(COMPILATIONOBJ)

clean:
	rm $(OBJ_FILES) $(EXECS_NAME)

docs :
	doxygen doc/sfl.doxy