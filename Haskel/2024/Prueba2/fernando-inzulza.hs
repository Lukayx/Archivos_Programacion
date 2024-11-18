-- PRUEBA 2 INFO188
-- 2 de Octubre 2024
-- Tiempo: 90mins
-- Entrega: Subir archivo <nombre-apellido>.hs a la tarea 'prueba 2' de SiveducMD
--
-- ***************************************************************************************
-- INSTRUCCIONES:
--      - Toda funcion debe ir con contrato y una explicacion breve y clara de lo que hace.
--      - Puede escribir funciones auxiliares para ayudar a organizar su codigo
-- ***************************************************************************************
--

-- ***************************************************************************
-- ************ Sea el siguiente tipo de dato y sus funciones ****************
-- ***************************************************************************
data DTree a = Nodo (a,a) [a] (DTree a) (DTree a) | Vacio deriving (Show, Eq)
-- DTree es un arbol binario que organiza elementos de tipo a en un rango (a,a)
-- crear a partir de lista
crearDTree :: (Ord a, Enum a) => a -> a -> [a] -> DTree a
crearDTree minR maxR xs = foldr ins (Nodo (minR, maxR) [] Vacio Vacio) xs 

-- insertar un elemento
ins :: (Ord a, Enum a) => a -> DTree a -> DTree a
ins e (Nodo (minR, maxR) xs Vacio Vacio) 
      | length xs < 4 = Nodo (minR, maxR) (e:xs) Vacio Vacio -- lo que hace (e:xs) es agregar e a la lista xs
      | otherwise =
      let   midR = toEnum ((fromEnum minR + fromEnum maxR) `div` 2)
            izq = Nodo (minR, midR) ([x | x <- xs, x >= minR && x <= midR]) Vacio Vacio
            der = Nodo (succ midR, maxR) ([x | x <- xs, x > midR && x <= maxR]) Vacio Vacio
      in if e <= midR
            then Nodo (minR, maxR) [] (ins e izq) der         
            else Nodo (minR, maxR) [] izq        (ins e der)

ins e (Nodo (minR, maxR) xs izq der) = 
      let midR = toEnum ((fromEnum minR + fromEnum maxR) `div` 2)
      in if e <= midR
            then Nodo (minR, maxR) xs (ins e izq) der         
            else Nodo (minR, maxR) xs izq         (ins e der) 

--  1) (1pt) Explique que hace este arbol y como organiza sus elementos. Muestre 3 ejemplos de uso
--           de sus funciones.

--Este arbol organiza elementos de tipo a en un rango (a,a) y luego los organiza en un arbol binario dependiendo de si son menores o mayores al punto medio del rango.
-- lo que hace otherwise es dividir el rango en dos y crear dos nodos hijos, uno
-- con los elementos menores o iguales al punto medio y otro con los mayores
-- si e es menor a midR, se inserta en el hijo izquierdo, si no en el derecho
-- e cumple el papel de elemento a insertar
--Ejemplo 1:
--crearDTree 1 10 [1,2,3,4,5,6,7,8,9,10] 
--resultado: Nodo (1,10) [1,2,3,4,5,6,7,8,9,10] (Nodo (1,5) [1,2,3,4,5] (Nodo (1,3) [1,2,3] (Nodo (1,2) [1,2] Vacio Vacio) (Nodo (3,3) [3] Vacio Vacio)) (Nodo (5,5) [5] Vacio Vacio)) (Nodo (6,10) [6,7,8,9,10] (Nodo (6,8) [6,7,8] (Nodo (6,7) [6,7] Vacio Vacio) (Nodo (8,8) [8] Vacio Vacio)) (Nodo (9,10) [9,10] (Nodo (9,9) [9] Vacio Vacio) (Nodo (10,10) [10] Vacio Vacio)))
--Un ejemplo de uso con valores no numericos seria:
--crearDTree 'a' 'z' ['a'..'z']
-- resultado: Nodo ('a','z') "" (Nodo ('a','m') "" (Nodo ('a','g') "" (Nodo ('a','d') "abcd" Vacio Vacio) (Nodo ('e','g') "efg" Vacio Vacio)) (Nodo ('h','m') "" (Nodo ('h','j') "hij" Vacio Vacio) (Nodo ('k','m') "klm" Vacio Vacio))) (Nodo ('n','z') "" (Nodo ('n','t') "" (Nodo ('n','q') "nopq" Vacio Vacio) (Nodo ('r','t') "rst" Vacio Vacio)) (Nodo ('u','z') "" (Nodo ('u','w') "uvw" Vacio Vacio) (Nodo ('x','z') "xyz" Vacio Vacio)))
--Otro ejemplo distinto sería
--DTree arbol = crearDTree 1 5 [1,2,3,4,5]
--resultado: 
-- ins 10 arbol
-- ins 20 arbol
-- ins 8 arbol


--  2) (2pts) Crear el typeclass 'Chaos' el cual ofrece la funcion 'grow' que inserta un elemento aleatorio
--            en el rango total del arbol, y la funcion `shake`, que mueve los elementos a su `succ` o `pred` 
--            de forma aleatoria, y luego adapta la estructura a los nuevos valores. Haga que `DTree` sea 
--            una instancia de este typeclass y muestre con tres ejemplos su funcionamiento. 



-- class Chaos a where
--       grow :: (Ord a, Enum a) => a -> DTree a -> DTree a
--       shake :: (Ord a, Enum a) => DTree a -> DTree a

-- instance Chaos a where
--       grow e (Nodo (minR,maxR) xs izq der) = ins e (Nodo (minR,maxR) xs izq der)
--       grow e Vacio = ins e Vacio


--  3) (1.5pts) Extienda `DTree` para que sea una instancia de Functor. Explique su funcionamiento y muestre con ejemplos 
instance Functor DTree where
      fmap f (Nodo (minR, maxR) xs izq der) = Nodo (f minR, f maxR) (map f xs) (fmap f izq) (fmap f der)
      fmap f Vacio = Vacio

-- Lo que hace es aplicar la funcion a cada uno de los elementos usando fmap para acceder al su contexto, 
-- mapea en caso de la lista para aplicar la funcion y usa fmap para las subramas izquierda y derecha

--  4) (1.5pts) Extienda `DTree` para que sea una instancia de Aplicativo y explique como podria servir. 

-- instance Applicative DTree where
--       pure x = Nodo (x, x) [] Vacio Vacio
--       Vacio <*> _ = Vacio
--       _ <*> Vacio = Vacio
--       (Nodo (minR, maxR) l1 izq der) <*> (Nodo (minR', maxR') l2 izq' der') = Nodo (fmap minR minR' , fmap maxR maxR') (map (/f x -> f x) l1 l2) (izq <*> izq') (der <*> der')