CC=g++
CFLAGS=-Wall -O3 -std=c++17
BINS=pila cola pilaArray stlstackqueue
all: clean pila cola pilaArray stl

pila:
	$(CC) $(CFLAGS) -o pila stack.cpp
	
cola:
	$(CC) $(CFLAGS) -o cola queueFL.cpp	

pilaArray:
	$(CC) $(CFLAGS) -o pilaArray stackArray.cpp

stl:
	$(CC) $(CFLAGS) -o stlstackqueue stlstackqueue.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
