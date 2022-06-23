CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS=BusquedaExhaustiva ArregloDeSufijos Lista_enlazada
all: clean BusquedaExhaustiva ArregloDeSufijos Lista_enlazada

recursividad:
	$(CC) $(CFLAGS) -o BusquedaExhaustiva BusquedaExhaustiva.cpp

sortAlg:
	$(CC) $(CFLAGS) -o ArregloDeSufijos ArregloDeSufijos.cpp

sortSTL:
	$(CC) $(CFLAGS) -o Lista_enlazada ListaEnlazada.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
