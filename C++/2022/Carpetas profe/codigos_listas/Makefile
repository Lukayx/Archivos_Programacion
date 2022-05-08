CC=g++
CFLAGS=-Wall -std=c++17
BINS=listas listasDobles
all: clean puntero listas listasDobles

ejemplo:
	$(CC) $(CFLAGS) -o puntero puntero.cpp

listas:
	$(CC) $(CFLAGS) -o listas listas.cpp
	
listasDobles:
	$(CC) $(CFLAGS) -o listasDobles listasDobles.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
	
