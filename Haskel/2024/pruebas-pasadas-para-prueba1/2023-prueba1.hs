-- PRUEBA 1 INFO188
-- 26 de Sept 2023
-- Tiempo: 90mins
-- Entrega: Subir archivo <nombre-apellido>.hs a la tarea 'prueba 1' de SiveducMD
--
-- ***************************************************************************************
-- INSTRUCCIONES:
--      - Toda funcion debe ir con contrato y una explicacion breve y clara de lo que hace.
--      - Puede escribir funciones auxiliares para ayudar a organizar su codigo
-- ***************************************************************************************
--
-- 1) (2pts) Minimos en Rango
--    Escriba una funcion llamada "minRangeBatch" que dada una lista L de elementos, y una
--    lista tuplas (i, j) de indices con i < j < |L|, devuelve una lista de tuplas (val, index)
--    donde val es el minimo entre L[i] y L[j] incluyendo los limites, e 'index' el indice
--    de tal valor. Cada tupla de salida corresponde a la respuesta de la tupla de entrada.
--    Ejemplos:
--          minRangeBatch [4,2,10,5,6,7,8,3,1,11] [(0,3), (3,7), (6,9)]
--          --> [(2, 1), (3, 7), (1,8)]
--          minRangeBatch "La Region de los Rios" [(3,8), (0,1)]
--          --> [('e', 4), ('a', 1)]
--
minRangeBatch :: (Ord a) => [a] -> [(Int,Int)] -> [(Int,Int)]
minRangeBatch z [] = []
minRangeBatch z (x:xs) = let min = minimum( drop (fst x) (take ((snd x)+1) z) )
                        let pos = findPos min z
                        in (min, pos) : (minRangeBatch z xs)

findPos :: (Ord a) => a -> [a] -> Int
findPos min [] = error "Lista vacia"
findPos min (x:xs) 
  | (min /= x) = 1 + (findPos min xs)
  | otherwise = 0

-- 2) (2pts) Funciones en Serie
--    Dada una lista de funciones L = [f1, f2, f3, ..., fn] donde cada una es del tipo (a -> a),
--    escriba las funciones "serieInicio val L" y "serieFinal val L", que aplican las funciones
--    en serie a partir del Inicio o del Final, respectivamente.
--    Ejemplos:
--          serieInicio 5 [(\x -> 50+x), (\x -> x*2, (+10)]
--          --> 120
--          serieFinal 5 [(\x -> 50+x), (\x -> x*2, (+10)]
--          --> 80
--


-- 3) (2pts) Typeclass Quantum
--    Crear el typeclass "Quantum", el cual tiene las funciones 'superPos' y 'medir'. 
--    Dado un 'x' de tipo concreto:
--      'superPos x'   -> crea la lista [predecesor de x, x, sucesor de x]
--      'medir [x]'    -> obtiene una instancia del elemento (usted puede decidir cual)
--          
--    a) Crear el Typeclass 'Quantum'
--    b) Hacer que Int y Char Instancien 'Quantum'
--    c) Hacer que (Maybe m) instancie 'Quantum', explique bien el comportamiento que propone.
