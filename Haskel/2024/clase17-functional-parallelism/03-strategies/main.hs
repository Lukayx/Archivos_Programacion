import System.IO
import Control.DeepSeq
import Control.Parallel
import Control.Parallel.Strategies
import Control.Exception
import Text.Printf
import Data.Time.Clock
import System.Environment
import Control.Monad.Par

-- definicion (sinonimo)
-- type Strategy a = a -> Eval a


-- fibonacci
fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib x = (fib $ x-1) + (fib $ x-2)

-- estrategia para evaluar pares en paralelo
parPairUno' :: Strategy (a,b)
parPairUno' (a,b) = do
    a' <- rpar a
    b' <- rpar b
    return (a', b')


-- funcion parametrizada para estrategias
evalPair :: Strategy a -> Strategy b -> Strategy (a,b)
evalPair sa sb (a,b) = do
    a' <- sa a
    b' <- sb b
    return (a', b')

-- parPair con estrategia parametrizada
-- parPair :: Strategy (a,b)
-- parPair = evalPair rpar rpar
--

-- parPair con estrategias como argumentos
parPair' :: Strategy a -> Strategy b -> Strategy (a,b)
parPair' sa sb = evalPair (rparWith sa) (rparWith sb)


-- par de tuplas, con estrategia parametrizada
parPP :: Strategy a -> Strategy b -> Strategy c -> Strategy d -> Strategy ((a,b),(c,d))
parPP sa sb sc sd = evalPair (evalPair sa sb) (evalPair sc sd)


-- generador de estrategias de evaluacion en listas
evalList' :: Strategy a -> Strategy [a]
evalList' s [] = return []
evalList' s (x:xs) = do
    x' <- s x
    xs' <- evalList' s xs
    return (x':xs')


-- parList
parList' :: Strategy a -> Strategy [a]
parList' s = evalList' (rparWith s)


-- identidad
--x `using` s = x
--
--
--
--
--newtype Par a
--instance Applicative Par
--instance Monad Par
--
--runPar :: Par a -> a


--fork :: Par () -> Par ()
--
--data IVar a -- instance Eq
--
--new :: Par (Ivar a)
--put :: NFData a => IVar a -> a -> Par ()
--get :: Ivar a -> Par a


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


-- spawnea un computo en paralelo y retorna un IVar 
-- que se usa para esperar el resultado.
spawn' :: NFData a => Par a -> Par (IVar a)
spawn' p = do
    i <- new
    fork (do x <- p; put i x)
    return i

-- parMapM
parMapM'' :: NFData b => (a -> Par b) -> [a] -> Par [b]
parMapM'' f as = do
    ibs <- mapM (spawn' . f) as
    mapM get ibs

-- parMap
parMap'' :: NFData b => (a -> b) -> [a] -> Par [b]
parMap'' f as = do
    ibs <- mapM (spawn' . return . f) as
    mapM get ibs


