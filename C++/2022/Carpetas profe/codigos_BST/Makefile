CC=g++
CFLAGS=-Wall -std=c++14 -O3
BINS=bst BST.o
all: clean bst

bst: BST.o
	$(CC) $(CFLAGS) -o bst BinarySearchTree.cpp BST.o

BST.o: BST.cpp
	$(CC) $(CFLAGS) -c BST.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
