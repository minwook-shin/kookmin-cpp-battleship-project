CC        = g++
CFLAGS    = -g -Wall
FILE      = main.cpp player.cpp gameManager.cpp ship.cpp windowManager.cpp statusWindow.cpp inputWindow.cpp defendWindow.cpp attackWindow.cpp
TARGET    = battleship

battleship : calcTurn.cpp main.cpp player.cpp gameManager.cpp ship.cpp windowManager.cpp statusWindow.cpp inputWindow.cpp defendWindow.cpp attackWindow.cpp main.h player.h gameManager.h ship.h windowManager.h statusWindow.h inputWindow.h defendWindow.h attackWindow.h
	$(CC) $(FILE) $(CFLAGS) -o $@ -lncurses
	$(CC) calcTurn.cpp $(CFLAGS) -o calcTurnProgram
	echo ">> run program : ./start_game"

run :
	./start_game.sh
	
clean :
	rm $(TARGET)

test :
	$(CC) test.cpp $(CFLAGS) -o $@ -lncurses

dep-install :
	sudo apt-get install libncurses5-dev libncursesw5-dev

set-g++ :
	sudo apt install build-essential 
	sudo apt-get install g++-4.8
	sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90


set-debug : 
	sudo apt-get install valgrind

debug :
	valgrind ./battleship --tool=memcheck --leak-check=full --show-reachable=yes --log-file="./valgrind_log"