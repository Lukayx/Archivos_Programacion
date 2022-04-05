CC=g++
CFLAGS=-Wall -std=c++17
BINS= alum
all: clean alum

alum:
	$(CC) $(CFLAGS) -o alum alumnos.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
