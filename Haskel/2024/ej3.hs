serieInicio :: a -> [(a -> a)] -> a
serieInicio val l = foldl (\ acc x -> x acc) val l

serieFinal :: a -> [(a -> a)] -> a
serieFinal val l = foldr (\x acc -> x acc) val l