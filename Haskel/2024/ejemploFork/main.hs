import System.IO
import Control.Monad.Par

--fibbonacci
fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

-- new :: Par (IVar a)
-- put :: NFData a => IVar a -> a -> Par ()
-- get :: IVar a -> Par a
-- fork:: Par() -> Par ()

-- ejemplo dos computos paralelos
main = do
  let comp = runPar $ do
      i <- new
      j <- new
      fork (put i (fib 35))
      fork (put j (fib 35))
      a <- get i
      b <- get j
      return (a+b)
  print comp