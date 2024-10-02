import Data.Char (isUpper)

suma :: (Num a) => a -> a -> a
suma x y = x + y 

comparar :: (Ord a) => a -> a -> a
comparar x y 
    | (x > y) = x
    | otherwise = y

--
compararListas :: (Ord a) => [a] -> [a] -> [Ordering]
compararListas = zipWith compare -- lo que hace esto es comparar los elementos de las listas y devolver una lista de resultados
-- lo que hace zipWith es aplicar la funcion compare a los elementos de las listas y devolver una lista con los resultados
-- zipWith :: (a -> b -> c) -> [a] -> [b] -> [c]

upperVerify :: String -> [Bool] -- verifica si un caracter es mayuscula
upperVerify = map isUpper -- map aplica la funcion isUpper a cada caracter de la lista
-- map :: (a -> b) -> [a] -> [b]

--upperVerify2 :: String -> [Bool]
--upperVerify2 = map (\c -> c >= 'A' && c <= 'Z')

funcion :: [Float] -> (Float, String) -- recibe una lista de flotantes y devuelve una tupla con la suma de los elementos y una cadena con la suma
funcion xs = foldl (\(sum, str) x -> (sum + x , str ++ " + " ++ show x)) (1.0, "1.0") xs 
-- foldl aplica la funcion lambda a cada elemento de la lista, acumulando el resultado en la tupla (sum, str)
-- foldl :: (b -> a -> b) -> b -> [a] -> b              b es el acumulador, a es el elemento de la lista

multiplicarConScanl :: [Int] -> [(Int, String)]
multiplicarConScanl = scanl (\(prod, str) x -> (prod * x, str ++ " * " ++ show x)) (1, "1")
-- scanl aplica la funcion lambda a cada elemento de la lista, acumulando el resultado en una lista de tuplas (prod, str)
-- scanl :: (b -> a -> b) -> b -> [a] -> [b]            b es el acumulador, a es el elemento de la lista