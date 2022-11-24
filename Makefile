CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -O3 -m64 -I include/
LDFLAGS = -s -lSDL2main -lSDL2 -lSDL2_ttf

all:
	$(CC) $(CFLAGS) $(wildcard src/*.c) -o ./build/bin $(LDFLAGS)
	./build/bin