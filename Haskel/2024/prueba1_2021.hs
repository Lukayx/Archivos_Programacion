- 1) maximo lista
maximum'' :: (Ord a) => [a] -> a
maximum'' [] = error "error, lista vacia"
maximum'' [x] = x
maximum'' (x:xs)
  | x > maxResto = x
  | otherwise = maxResto
  where maxResto = maximum'' xs