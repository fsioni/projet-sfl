EXECS_NAME = bin/exec 
OBJ_FILES = obj/main.o obj/Layer.o obj/tmxParsing.o obj/Tileset.o obj/Map.o 
OBJ_FILES += obj/MapLayer.o obj/CollisionLayer.o obj/SpawnPoint.o obj/SpawnPoint.o
OBJ_FILES += obj/SpawnsLayer.o obj/Box.o obj/CollisionBox.o obj/StateManager.o
OBJ_FILES += obj/Game.o obj/EntityWithHP.o obj/EntityWithoutHP.o obj/Player.o
OBJ_FILES += obj/Enemy.o obj/winTxt.o obj/gameTxt.o obj/AssetManager.o
OBJ_FILES += obj/StateGameSFML.o


CC = g++
CFLAGS = -Wall -ggdb -std=c++14

INCLUDE_SFML = -I./extern/SFML/include 
LIBS_SFML = -Lextern/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system 

COMPILATIONOBJ = $(CC) $(CFLAGS) -c $< -o $@ 


all: $(EXECS_NAME)

bin/exec : $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SFML)

obj/main.o: src/main.cpp src/Core/Game.h
	$(COMPILATIONOBJ)

obj/StateGameSFML.o : src/SFML/StateGameSFML.cpp src/SFML/StateGameSFML.h src/SFML/AssetManager.h src/Core/Game.h src/Core/StateManager/StateManager.cpp src/Core/StateManager/State.h
	$(COMPILATIONOBJ)

obj/AssetManager.o : src/SFML/AssetManager.cpp src/SFML/AssetManager.h 
	$(COMPILATIONOBJ)

obj/Map.o : src/Core/Map/Map.cpp src/Core/Map/Map.h src/Core/Map/Tileset.h src/Core/Map/Layers/Layer.h src/Core/Map/tmxParsing.h src/Core/Map/Box.h
	$(COMPILATIONOBJ)

obj/Tileset.o : src/Core/Map/Tileset.cpp src/Core/Map/Tileset.h src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/Layer.o : src/Core/Map/Layers/Layer.cpp src/Core/Map/Layers/Layer.h src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/MapLayer.o : src/Core/Map/Layers/MapLayer.cpp src/Core/Map/Layers/MapLayer.h  src/Core/Map/Layers/Layer.h src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/Box.o : src/Core/Map/Box.cpp src/Core/Map/Box.h
	$(COMPILATIONOBJ)

obj/CollisionBox.o : src/Core/Map/CollisionBox.cpp src/Core/Map/CollisionBox.h src/Core/Map/Box.h
	$(COMPILATIONOBJ)

obj/CollisionLayer.o : src/Core/Map/Layers/CollisionLayer.cpp src/Core/Map/Layers/CollisionLayer.h src/Core/Map/Layers/Layer.h src/Core/Map/CollisionBox.h
	$(COMPILATIONOBJ)

obj/SpawnPoint.o : src/Core/Map/SpawnPoint.cpp src/Core/Map/SpawnPoint.h src/Core/Map/Box.h
	$(COMPILATIONOBJ)

obj/SpawnsLayer.o : src/Core/Map/Layers/SpawnsLayer.cpp src/Core/Map/Layers/SpawnsLayer.h src/Core/Map/Layers/Layer.h src/Core/Map/SpawnPoint.h
	$(COMPILATIONOBJ)

obj/tmxParsing.o: src/Core/Map/tmxParsing.cpp src/Core/Map/tmxParsing.h
	$(COMPILATIONOBJ)

obj/StateManager.o : src/Core/StateManager/StateManager.cpp src/Core/StateManager/State.h
	$(COMPILATIONOBJ)

obj/Game.o : src/Core/Game.cpp src/Core/StateManager/StateManager.h src/Core/Entity/Player.h
	$(COMPILATIONOBJ)

obj/EntityWithHP.o : src/Core/Entity/EntityWithHP.cpp src/Core/Entity/EntityWithoutHP.h 
	$(COMPILATIONOBJ)

obj/EntityWithoutHP.o : src/Core/Entity/EntityWithoutHP.cpp
	$(COMPILATIONOBJ)

obj/Player.o : src/Core/Entity/Player.cpp src/Core/Entity/EntityWithHP.h
	$(COMPILATIONOBJ)

obj/Enemy.o : src/Core/Entity/Enemy.cpp src/Core/Entity/EntityWithHP.h
	$(COMPILATIONOBJ)

obj/winTxt.o : src/txt/winTxt.cpp
	$(COMPILATIONOBJ)

obj/gameTxt.o : src/txt/gameTxt.cpp src/txt/winTxt.h src/Core/Game.h 
	$(COMPILATIONOBJ)

clean:
	rm $(OBJ_FILES) $(EXECS_NAME)

docs :
	doxygen doc/sfl.doxy