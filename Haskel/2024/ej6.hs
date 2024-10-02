instance Functor Maybe where
    fmap _ Nothing = Nothing
    fmap f (Just x) = Just (f x)

-- ((+3) <$> (*2)) <$> [5] resultado: [13]
-- (+4) <$> ((+3) <$> [3]) resultado: [10]

f :: Int -> String
f x = show x  -- Convierte el número en string

g :: String -> String
g s = reverse s  -- Invierte la cadena

h :: String -> Int
h s = length s  -- Devuelve la longitud de la cadena

-- Usando fmap
resultadoFmap :: Int -> Int
resultadoFmap = fmap h (fmap g f)

-- Usando composición (.)
resultadoDot :: Int -> Int
resultadoDot = h . g . f

-- Usando <$>
resultadoDollar :: Int -> Int
resultadoDollar = h <$> g <$> f

-- Aplicación
main = do
  print (resultadoFmap 12345)  -- 5
  print (resultadoDot 12345)   -- 5
  print (resultadoDollar 12345) -- 5


-- Instancia de Applicative para Maybe
instance Applicative Maybe where
    pure = Just
    Nothing <*> _ = Nothing
    (Just f) <*> something = fmap f something

-- Ejemplo de uso:
result = pure (+3) <*> Just 5  -- Resultado: Just 8


-- pure: Envuelve un valor en el contexto del functor.
-- Tipo: pure :: a -> f a
-- <*>: Toma una función envuelta en un contexto y un valor en un contexto y aplica la función al valor.
-- Tipo: <*> :: f (a -> b) -> f a -> f b




-- Instancia de Monad para Maybe
instance Monad Maybe where
    return = Just
    Nothing >>= _ = Nothing
    (Just x) >>= f = f x

-- Ejemplo de uso:
result = Just 5 >>= (\x -> return (x + 3))  -- Resultado: Just 8

-- return: Es equivalente a pure de Applicative y coloca un valor dentro de un contexto.
-- Tipo: return :: a -> m a
-- >>= (bind): Toma un valor envuelto en un contexto y una función que toma un valor normal y devuelve un valor en un contexto. Luego, aplica la función al valor.
-- Tipo: >>= :: m a -> (a -> m b) -> m b


(+) <$> (+3) <*> (*100) $ 5 -- resultado: 508
-- aplica la función (+) a los resultados de (+3) y (*100) aplicados a 5
