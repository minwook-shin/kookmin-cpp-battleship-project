CC		= g++
CFLAGS	= -g
FILE	= main.cpp
EXE		= battleship

battleship : main.cpp
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