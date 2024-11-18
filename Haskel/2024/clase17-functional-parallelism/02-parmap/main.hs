-- permite un modo de ejecucion paralela
import System.IO
import Control.DeepSeq
import Control.Parallel
import Control.Parallel.Strategies
import Control.Exception
import Text.Printf
import Data.Time.Clock
import System.Environment

-- parMap
parMap' :: (a -> b) -> [a] -> Eval [b]
parMap' f [] = return []
parMap' f (a:as) = do
    b <- rpar (f a)
    bs <- parMap' f as
    return (b:bs)

-- fibonacci
fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib x = (fib $ x-1) + (fib $ x-2)

-- main
main = do
    let set = id $! [37, 37, 37, 37, 37, 37]
    printf "Computing....." 
    hFlush stdout
    let res = runEval $ parMap' fib set
    res `deepseq` (printf "done:\n")
    --printf "done\n"
    --print res


