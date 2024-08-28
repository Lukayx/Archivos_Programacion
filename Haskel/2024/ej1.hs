func :: (Num a)  => [a] -> a
func [x] = x 
func (_:xs) = func xs

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

--minRangeBatch :: (Ord a) => [a] -> [(Int, Int)] -> [(Int, Int)]
--minRangeBatch z [] = []
--minRangeBatch z (x:xs) = let min = minimum (drop (fst x) (take ((snd x)+1) z))
--                          let pos = findPos min z 


findPos :: (Ord a) => a -> [a] -> Int
findPos a [] = error "no fue encontrado el indice"
findPos a (x:xs)
  | (a /= x) = 1 + (findPos a xs)
  | otherwise = 0

length' :: [a] -> Int
length' [] = 0
length' (_:xs) = 1 + length' xs

motorEfi :: (RealFloat a) => a -> a -> String 
motorEfi ccl kmpL 
  | (val <= 0.3)  = "Liviano"
  | (val <= 0.5)  = "Mediano"
  | (val <= 0.8) = "Pesado"
  | otherwise        = "Muy pesado"
  where val = ccl/kmpL