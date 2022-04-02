CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS=taller
all: clean taller

taller:
	$(CC) $(CFLAGS) -o taller tallerVectores.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
