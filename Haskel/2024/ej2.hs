-- 1) maximo lista
maximum'' :: (Ord a) => [a] -> a
maximum'' [] = error "error, lista vacia"
maximum'' [x] = x
maximum'' (x:xs)
  | x > maxResto = x
  | otherwise = maxResto
  where maxResto = maximum'' xs

replicate' :: (Num a, Ord a) => a -> i -> [i]
replicate' n i 
  | (n <= 0) = []
  | otherwise = i:replicate' (n-1) i  

take' :: (Num i, Ord i) => i -> [a] -> [a]
take' _ [] = []
take' n (x:xs)
  | (n > 0) = x:take' (n-1) xs 
  |  otherwise = []

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = let right = quicksort [a | a <- xs, a > x]
                       left = quicksort [a | a <- xs, a <= x]
                   in left ++ [x] ++ right


-- SIN TAIL RECURSION
suml :: (Num a) => [a] -> a
sumL [] = 0
sumL (x:xs) = x + (sumL xs)

-- CON TAIL RECURSION
sumTR :: (Num a) => [al] -> a -> a
sumTR [] acc = acc
sumTR (x:xs) acc = sumTR xs (acc + x)

-- Data.List
-- Data.Char
-- Data.Map
-- Data.Set
