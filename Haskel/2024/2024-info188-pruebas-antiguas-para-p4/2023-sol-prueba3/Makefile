all:
	nvcc -O3 -Xcompiler -fopenmp p2p3.cu -o cpp_prog
hs:
	ghc -o hs_prog -dynamic -threaded -package monad-par p1.hs
