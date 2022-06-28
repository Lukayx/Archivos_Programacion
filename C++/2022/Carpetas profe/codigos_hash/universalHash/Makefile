CC=g++
CFLAGS=-Wall -std=c++14 -O3
BINS=openHash univHash
all: clean univHash

univHash:
	$(CC) $(CFLAGS) -o univHash UniversalHash.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)

