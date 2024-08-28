-- Listas

-- Concatenación de listas
lista1 = [1, 2, 3] ++ [4, 5, 6]

-- Acceso por posición
elem1 = lista1 !! 0  -- Primer elemento: 1

-- Lista de listas
listaDeListas = [[1,2,3], [4,5,6]]

-- Comparación de listas
comparacion = [1,2,3] == [1,2,3]  -- True

-- Head, Tail, Last, Init
headEjemplo = head [1,2,3]    -- 1
tailEjemplo = tail [1,2,3]    -- [2,3]
lastEjemplo = last [1,2,3]    -- 3
initEjemplo = init [1,2,3]    -- [1,2]

-- Longitud, Null, Reverse, Take, Drop
longitud = length [1,2,3]          -- 3
esVacia = null []                  -- True
invertida = reverse [1,2,3]        -- [3,2,1]
tomar = take 2 [1,2,3]             -- [1,2]
dejar = drop 2 [1,2,3]             -- [3]

-- Maximum, Minimum, Sum, Product, Elem
maximo = maximum [1,2,3]           -- 3
minimo = minimum [1,2,3]           -- 1
suma = sum [1,2,3]                 -- 6
producto = product [1,2,3]         -- 6
existe = elem 2 [1,2,3]            -- True

-- Zip
pares = zip [1..] ["apple", "orange", "cherry", "mango"]
-- [(1, "apple"), (2, "orange"), (3, "cherry"), (4, "mango")]

-- Rangos
rango1 = [1..5]                -- [1,2,3,4,5]
rango2 = ['a'..'z']            -- ['a','b','c'..'z']
ciclo = take 12 (cycle "CHI")  -- "CHICHICHICHI"

-- Repeat y Replicate
repetir = take 4 (repeat 5)    -- [5,5,5,5]
replicar = replicate 3 10      -- [10,10,10]

-- Comprensión de listas
comprension1 = [x*3 | x <- [1..5]]  -- [3,6,9,12,15]
comprension2 = [2*x | x <- [1..10], x > 3, x < 5]  -- [8]

-- Producto cartesiano
cartesiano = [x : [y] | x <- "ab", y <- "xy"]
-- ["ax", "ay", "bx", "by"]

-- Tuplas
tupla1 = fst (1, 34)  -- 1
tupla2 = snd (1, 34)  -- 34

-- Ejercicios

-- Función recursiva que retorna el último elemento de una lista
ultimo :: [a] -> a
ultimo [x] = x
ultimo (_:xs) = ultimo xs

-- Función que revisa si una lista es palindrome
palindrome :: (Eq a) => [a] -> Bool
palindrome xs = xs == reverse xs

-- Función que duplica los elementos de una lista
duplicar :: [a] -> [a]
duplicar [] = []
duplicar (x:xs) = x : x : duplicar xs

-- Función recursiva que invierte los elementos de una lista
invertir :: [a] -> [a]
invertir [] = []
invertir (x:xs) = invertir xs ++ [x]

-- Generar todos los triángulos (a,b,c) con lados < 10 que sean pitagóricos
triangulos :: [(Int, Int, Int)]
triangulos = [(a,b,c) | a <- [1..9], b <- [1..9], c <- [1..9], a^2 + b^2 == c^2]
