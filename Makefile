CC		= g++
CFLAGS	= -g -Wall
FILE	= main.cpp player.cpp gameManager.cpp ship.cpp windowManager.cpp statusWindow.cpp inputkWindow.cpp defendWindow.cpp attackWindow.cpp
EXE		= battleship

battleship : main.cpp player.cpp gameManager.cpp ship.cpp windowManager.cpp statusWindow.cpp inputkWindow.cpp defendWindow.cpp attackWindow.cpp main.h player.h gameManager.h ship.h windowManager.h statusWindow.h inputkWindow.h defendWindow.h attackWindow.h
	$(CC) $(FILE) $(CFLAGS) -o $@ -lncurses

test :
	$(CC) test.cpp $(CFLAGS) -o $@ -lncurses

dep-install :
	sudo apt-get install libncurses5-dev libncursesw5-dev

set-g++ :
	sudo apt install build-essential 
	sudo apt-get install g++-4.8
	sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90

clean :
	rm $(EXE)

set-debug : 
	sudo apt-get install valgrind

debug :
	valgrind ./battleship --tool=memcheck --leak-check=full --show-reachable=yes --log-file="./valgrind_log"