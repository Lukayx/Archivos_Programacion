CC=g++
CFLAGS=-Wall -std=c++14 -O3
BINS=openHash
all: clean openHash

openHash:
	$(CC) $(CFLAGS) -o openHash OpenHash.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)

