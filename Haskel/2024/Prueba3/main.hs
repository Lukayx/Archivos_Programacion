import System.IO
import Control.Monad.Par
import System.Random

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =  let right = quicksort [a | a <- xs, a > x]
                        left = quicksort [a | a <- xs, a <= x]
                    in left ++ [x] ++ right

-- new :: Par (IVar a)
-- put :: NFData a => IVar a -> a -> Par ()
-- get :: IVar a -> Par a
-- fork:: Par() -> Par ()

-- ejemplo dos computos paralelos
main = do
    n <- readLn 
    lista <- take n $ randomRs (1,100000) (mkStdGen 359353)
    let comp = runPar $ do
        i <- new
        j <- new
        fork (put i (quicksort lista))
        fork (put j (quicksort lista))
        a <- get i
        b <- get j
        return (a+b)
    print comp