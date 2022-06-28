CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS=BusquedaExhaustiva ArregloDeSufijos Lista_enlazada
all: clean BusquedaExhaustiva ArregloDeSufijos ListaEnlazada

BusquedaExhaustiva:
	$(CC) $(CFLAGS) -o BusquedaExhaustiva BusquedaExhaustiva.cpp

ArregloDeSufijos:
	$(CC) $(CFLAGS) -o ArregloDeSufijos ArregloDeSufijos.cpp

ListaEnlazada:
	$(CC) $(CFLAGS) -o ListaEnlazada Lista_Enlazada.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
