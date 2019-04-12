CC=g++

all: SDLWindow Particle Pixel MathHelper main love
	
SDLWindow: SDLWindow.o
	$(CC) -std=c++14 -g -c SDLWindow.cpp
	
Particle: Particle.o
	$(CC) -std=c++14 -g -c Particle.cpp
	
Pixel: Pixel.o
	$(CC) -std=c++14 -g -c Pixel.cpp
	
MathHelper: MathHelper.o
	$(CC) -std=c++14 -g -c MathHelper.cpp

main: windowTesting.o
	$(CC) -std=c++14 -g -c windowTesting.cpp
	
love: 
	$(CC) -std=c++14 -g -o loveTest SDLWindow.o Particle.o Pixel.o windowTesting.o -D_REENTRANT -ImathHelp.h -I/usr/include/SDL2 -lSDL2
	
#love: windowTesting.cpp
#	$(CC) -std=c++14 -g -o loveTest windowTesting.cpp SDLWindow.cpp Particle.cpp Pixel.cpp -D_REENTRANT -I/usr/include/SDL2 -lSDL2 
