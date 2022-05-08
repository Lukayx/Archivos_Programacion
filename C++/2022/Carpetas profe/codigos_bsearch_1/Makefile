CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS=binaryS
all: clean binarySearch 

binarySearch:
	$(CC) $(CFLAGS) -o binaryS BinarySearch.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
