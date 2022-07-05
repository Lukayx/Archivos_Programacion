CC=g++
CFLAGS=-Wall -std=c++17
BINS=BST.o problema

all: clean BST.o
	$(CC) $(CFLAGS) -o problema problema.cpp BST.o

BST.o:
	$(CC) $(CFLAGS) -c BST.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
