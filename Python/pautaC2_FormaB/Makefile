CC=g++
CFLAGS=-Wall -std=c++14
BINS=problemaB1 problemaB2
all: clean problemaB1 problemaB2

problemaB1:
	$(CC) $(CFLAGS) -o problemaB1 problemaB1_pauta.cpp

problemaB2:
	$(CC) $(CFLAGS) -o problemaB2 problemaB2_pauta.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
