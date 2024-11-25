# Makefile

all: prog

prog: main.hs
    ghc -dynamic -threaded -package monad-par main.hs -o prog

clean:
    rm -f prog *.o *.hi