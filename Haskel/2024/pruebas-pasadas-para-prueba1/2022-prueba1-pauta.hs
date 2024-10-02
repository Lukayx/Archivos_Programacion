-- 1) (2pts) Procesamiento de Lista
--    Escriba una funcion llamada 'tup', que dada una lista de valores de clase `Num`, 
--    retorne una tupla con:
--              - la suma de los elementos en posiciones pares
--              - la suma de los elementos en posiciones impares
--              - la lista de elementos que son potencia de `2`.

isPower2 :: (Num a, Integral a) => a -> Bool
isPower2 1 = True
isPower2 x
    | (modulo == 0)  = isPower2 (x `div` 2)
    | otherwise     = False
    where modulo = x `mod` 2

tup :: (Num a, Integral a) => [a] -> (a, a, [a])
tup xs = let pares = sum [xs !! i | i <- [0,2..(length xs - 1)]]
             impares = sum [xs !! i | i <- [1,3..(length xs - 1)]]
             powers = [x | x <- xs, isPower2 x]
         in (pares, impares, powers)
--
-- 2) (2pts) 'El compositor'
-- Dada una lista de funciones [f1, f2, f3, ..., fn] del tipo (a -> a), y una lista de valores [x1, x2, ..., xm] del tipo `a`, 
-- crear la funcion `compositor` que genera el resultado [f1(x1), f2(f1(x2)), f3(f2(f1(x3))), ..., fk(fk-1(..(f2(f1(xk)))))]
-- donde `k` es el menor entre `n` y `m`.
--
compositor :: [(a -> a)] -> [a] -> [a]
compositor fs xs = zipWith (\x y -> x y) (scanl1 (\acc x -> x . acc) fs) xs
--
--
-- 3) (2pts) Ordenamiento juntando mitades ordenadas
--    Una forma de ordenar elementos es unir sus mitades que garantizan estar ordenadas, de forma recursiva.
--    Se construye con `sort188` que es el la logica global, y `juntar` que fusiona dos listas ordenadas en otra ordenada.
--      a) (1.4pts) Implemente ambas funciones `sort188` y `juntar`.
juntar :: (Ord a) => [a] -> [a] -> [a]
juntar [] [] = []
juntar [] ys = ys
juntar xs [] = xs
juntar (x:xs) (y:ys) 
    | x <= y = x : juntar xs (y:ys)
    | x > y  = y : juntar (x:xs) ys


sort188 :: (Ord a) => [a] -> [a]
sort188 [] = []
sort188 [x] = [x]
sort188 xs = let half = length xs `div` 2
                 left = take half xs
                 right = drop half xs
             in juntar (sort188 left) (sort188 right)

--      b) (0.6pts) ¿Es posible mejorar el algoritmo en alguna parte con recursion por la cola? Explique y Justifique
--
--      respuesta positiva: Se podria en 'juntar', acumulando la lista resultante en un argumento extra
--
--      respuesta negativa: No es necesario porque el operador x : xs ya funciona de forma eficiente sin 
--      dejar la concatenaicion pendiente. Distintos seria con "++"
--

