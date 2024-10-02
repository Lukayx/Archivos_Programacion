data Arbol a = Av | Nodo a (Arbol a) (Arbol a) deriving (Show, Read, Eq)

arbolUno :: (Ord a) => a -> Arbol a
arbolUno a = Nodo a Av Av

arbolInsertar :: (Ord a) => a -> Arbol a -> Arbol a
arbolInsertar x Av = arbolUno x
arbolInsertar x (Nodo y izq der)
  | x == y = Nodo y izq der
  | x < y = Nodo y (arbolInsertar x izq) der
  | x > y = Nodo y izq (arbolInsertar x der)

arbolBuild :: (Ord a) => [a] -> Arbol a
arbolBuild xs = foldr arbolInsertar Av xs

arbolElem :: (Ord a) => a -> Arbol a -> Bool
arbolElem x Av = False
arbolElem x (Nodo y izq der)
  | x == y = True
  | x < y = arbolElem x izq
  | x > y = arbolElem x der

arbolRama :: (Ord a) => a -> Arbol a -> Arbol a
arbolRama x Av = Av
arbolRama x (Nodo y izq der)
  | x == y = Nodo y izq der
  | x < y = arbolRama x izq
  | x > y = arbolRama x der


-- ELIMINA CON SUCESOR (DERECHA Y LUEGO FULL IZQUIERDA)
arbolEliminar :: (Ord a) => a -> Arbol a -> Arbol a
arbolEliminar _ Av = Av
arbolEliminar x (Nodo y izq der)
  | x < y = Nodo y (arbolEliminar x izq) der -- Buscamos en el subárbol izquierdo
  | x > y = Nodo y izq (arbolEliminar x der) -- Buscamos en el subárbol derecho
  | otherwise = eliminarNodo (Nodo y izq der) -- El nodo a eliminar es el actual

-- Función auxiliar para eliminar un nodo específico
eliminarNodo :: (Ord a) => Arbol a -> Arbol a
eliminarNodo (Nodo _ Av der) = der -- Si no hay subárbol izquierdo, retornamos el derecho
eliminarNodo (Nodo _ izq Av) = izq -- Si no hay subárbol derecho, retornamos el izquierdo
eliminarNodo (Nodo _ izq der) = Nodo menor izq (arbolEliminar menor der) -- Reemplazamos por el menor del subárbol derecho
  where menor = encontrarMenor der -- sucesor

-- Función para encontrar el menor valor en un árbol
encontrarMenor :: Arbol a -> a
encontrarMenor (Nodo y Av _) = y
encontrarMenor (Nodo _ izq _) = encontrarMenor izq