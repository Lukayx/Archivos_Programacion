import System.IO
import Control.DeepSeq
import Control.Parallel
import Control.Parallel.Strategies
import Control.Exception
import Text.Printf
import Data.Time.Clock
import System.Environment
import Control.Monad.Par

-- fibonacci
fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib x = (fib $ x-1) + (fib $ x-2)

-- spawnea un computo en paralelo y retorna un IVar 
-- que se usa para esperar el resultado.
spawn' :: NFData a => Par a -> Par (IVar a)
spawn' p = do
    i <- new
    fork (do x <- p; put i x)
    return i

-- parMapM (monadic f)
parMapM'' :: NFData b => (a -> Par b) -> [a] -> Par [b]
parMapM'' f as = do
    ibs <- mapM (spawn' . f) as
    mapM get ibs

-- parMap (non-monadic f)
parMap'' :: NFData b => (a -> b) -> [a] -> Par [b]
parMap'' f as = do
    ibs <- mapM (spawn' . return . f) as
    mapM get ibs






--ejemplo dos computos paralelos
--main = do 
--    let comp = runPar $ do
--        --i <- new
--        --j <- new
--        --k <- new
--        --l <- new
--        --fork (put i (fib 35))
--        --fork (put j (fib 35))
--        --fork (put k (fib 35))
--        --fork (put l (fib 35))
--        i <- spawnP (fib 35)
--        j <- spawnP (fib 35)
--        k <- spawnP (fib 35)
--        l <- spawnP (fib 35)
--        a <- get i
--        b <- get j
--        c <- get k
--        d <- get l
--        return (a+b+c+d)
--    print comp








-- ejemplo dos computos paralelos
main = do 
    let comp = runPar $ do
        x <- parMap'' fib [10,20,30,32]
        y <- parMap'' fib [30,31,32,33]
        return (x ++ y)
    print comp
