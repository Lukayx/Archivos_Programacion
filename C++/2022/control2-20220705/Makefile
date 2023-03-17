CC=g++
CFLAGS=-Wall -std=c++17
BINS=problema1 problema2 *.o
all: clean problema1 BST.o problema2

problema1:
	$(CC) $(CFLAGS) -o problema1 problema1.cpp

problema2:
	$(CC) $(CFLAGS) -o problema2 problema2.cpp BST.o

BST.o: BST.cpp
	$(CC) $(CFLAGS) -c BST.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
