import Control.DeepSeq
import Text.Printf
import Data.Time.Clock
import System.Environment
import Control.Monad.Par

-- calculo de ejemplo a usar en el parZipWith
fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)


-- implementacion parZipWith con monada Par
parZipWith :: NFData c => (a -> b -> c) -> [a] -> [b] -> Par [c]
parZipWith f _ [] = return []
parZipWith f [] _ = return []
parZipWith f (x:xs) (y:ys) = do
    -- generar un spark de computo
    mvar <- spawn (return $ f x y)
    -- sparks pendientes
    pendiente <- parZipWith f xs ys
    -- obtener el computo
    c <- get mvar
    -- ir formando lista de computos paralelos
    return (c : pendiente)

main :: IO ()
main = do
  args <- getArgs
  let size = read (head args) :: Int
  printf "creando listas de tamano %i......." size
  let l1 = [1..size] :: [Int]
      l2 = [size, size-1..1] :: [Int]
  printf "done\n"

  printf "calculando parZipWith......."
  t1 <- getCurrentTime
  let result = runPar $ parZipWith (\x y -> fib (x+y)) l1 l2
  print result
  t2 <- getCurrentTime
  let tpar = diffUTCTime t2 t1
  printf "done: %s secs\n" (show tpar)

--➜  prueba3 ./hs_prog 30 +RTS -N1
--done: 2.464980882s secs
--
--➜  prueba3 ./hs_prog 30 +RTS -N2
--done: 1.331810429s secs
--
--➜  prueba3 ./hs_prog 30 +RTS -N4
--done: 0.791984918s secs
