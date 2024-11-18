all: prog

prog: main.hs
	ghc -dynamic -threaded -package monad-par random main.hs -o prog
	
clean:
	rm -f prog *.o *.hi