-- permite un modo de ejecucion paralela
import Control.Parallel.Strategies
import System.IO (hFlush, stdout)
import Text.Printf
import Control.DeepSeq

-- fibonacci
fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib x = (fib $ x-1) + (fib $ x-2)

main = do
    printf "Computing four Fibonaccis of 37....." 
    hFlush stdout
    let e = runEval $ do
                a <- rpar (fib 37)
                b <- rpar (fib 37)
                c <- rpar (fib 37)
                d <- rpar (fib 37)
                rseq a
                rseq b
                rseq c
                rseq d
                return (a,b,c,d)
    e `deepseq` (printf "done:\n")
    print e
