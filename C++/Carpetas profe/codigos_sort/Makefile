CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS=recursion sortAlg sortSTL
all: clean recursividad sortAlg sortSTL

recursividad:
	$(CC) $(CFLAGS) -o recursion recursion.cpp

sortAlg:
	$(CC) $(CFLAGS) -o sortAlg SortAlg.cpp

sortSTL:
	$(CC) $(CFLAGS) -o sortSTL sortArrSTL.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
