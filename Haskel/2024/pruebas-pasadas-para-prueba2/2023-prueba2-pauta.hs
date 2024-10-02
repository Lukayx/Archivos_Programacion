-- {-# LANGUAGE NoImplicitPrelude #-}
module Prueba2 where
-- PRUEBA 2 INFO188
-- 24 de Octubre 2023
-- Tiempo: 90mins
-- Entrega: Subir archivo <nombre-apellido>.hs a la tarea 'prueba 2' de SiveducMD
--
-- ***************************************************************************************
-- INSTRUCCIONES:
--      - Toda funcion debe ir con contrato y una explicacion breve y clara de lo que hace.
--      - Puede escribir funciones auxiliares para ayudar a organizar su codigo
-- ***************************************************************************************
--
-- import Prelude hiding ((<*>),pure) 
-- 1) Grafo
--   Se tiene el siguiente tipo de dato 'Grafo' que vamos a usar.
data Grafo a = G [(a,[a])] deriving (Show, Eq)
--   donde cada elemento (tupla) de la lista es un nodo con su identificador (a) y su lista de nodos adyacentes ([a]).
--   Ejemplo: let miGrafo = G [(1,[2,3]),(2,[1]),(3,[1,2,4])]
--
--
--
--   a) (1.5 pts) Instancie Grafo a Functor y use esa nueva funcionalidad para hacer la 
--                funcion 'shiftUp' que recibe un Grafo y convierte cada identificador a su sucesor.









instance Functor Grafo where
    fmap f (G l) = G (map (\t -> (f (fst t), map f (snd t))) l) 

-- Utiliza map para aplicar la función f a cada elemento de la lista l.
-- Cada elemento t de l es una tupla (a, [a]).
-- Se descompone la tupla usando fst para obtener el primer elemento (el identificador del nodo), y snd para obtener la lista de nodos adyacentes.




shiftUp :: (Enum a) => Grafo a -> Grafo a -- Enum es una clase de tipo que permite generar secuencias de valores, por lo que se puede usar para incrementar los identificadores de los nodos.
shiftUp grafo = fmap (\x -> succ x) grafo -- Se aplica la función succ a cada identificador del grafo, incrementando en 1 cada uno.

-- shiftUp :: Grafo Int -> Grafo Int
-- shiftUp = fmap (+1)





--   b) (1.5 pts) Instancie Grafo a Aplicativo, y use esa nueva funcionalidad para hacer 
--                la funcion 'superConexion' donde se aplica un grafo de funciones a un grafo 
--                de datos, resultando en muchas mas conexiones por nodo. 

instance Applicative Grafo where
pure x = G [(x,[])]
-- solucion A --> usando el aplicativo de lista
(G l1) <*> (G l2) = G (zipWith ( \(f, fs) (x, xs) -> (f x, fs <*> xs)) l1 l2)
-- solucion B --> usando zipWith + comprension de listas
--(G l1) <*> (G l2) = G (zipWith (\x y -> ((fst x) (fst y), [f v | f <- (snd x), v <- (snd y)])) l1 l2)



--   c) (1.5 pts) Instancie Grafo a Monada, proponga un diseno que le haga sentido 
--                y que permita hacer 'modificaciones' a un grafo al hacer "Grafo >>= f". 
--                Trate de elaborar algo interesante.

-- Helper function to unwrap the Grafo structure
nodosGrafo :: Grafo a -> [(a, [a])]
nodosGrafo (G nodes) = nodes

instance Monad Grafo where
    return x = G [(x, [])]
    (G l) >>= f = G [(x', ys') | (x, ys) <- l, (x', ys') <- nodosGrafo (f x)]

-- se hace un comportamiento donde f se aplica a cada nodo, por lo tanto se puede modificar el grafo, a partir de la informacion del nodo. La unica limitante de esta solucion es que no participa la informacion de los vecinos, esta se pierde y se vuelve a generar. 
-- Ejemplos:
--  λ> (G [(1,[2,3]),(2,[1]),(3,[1,2,4])]) >>= (\x -> G [(x, [x + 1])])
--     G [(1,[2]),(2,[3]),(3,[4])]
--
--  λ> (G [(1,[2,3]),(2,[1]),(3,[1,2,4])]) >>= (\x -> G [(x, [x + 1, x+2])])
--     G [(1,[2,3]),(2,[3,4]),(3,[4,5])]
--
--  λ> (G [(65,[2,3]),(70,[1]),(80,[1,2,4])]) >>= (\x -> G [(chr x, [chr x, chr $ x+1, chr $ x+2])])
--     G [('A',"ABC"),('F',"FGH"),('P',"PQR")]

--
--
--
--
-- 2) (1.5 pts) En Python, implemente el operador aplicativo para listas con el mismo 
--              comportamiento que tiene en Haskell. El aplicativo puede ser una funcion 
--              como "aplicativo(lista_funcs, lista_datos)". La respuesta debe estar 
--              en un archivo python aparte con un codigo "main" ejemplicifando su uso.
--
-- def aplicativo(funcs, vals):
--    if not funcs:
--        return []
--    if not vals:
--        return []
--    r = []
--    for f in funcs:
--        for x in vals:
--            r.append(f(x))
--
--    return r
--
-- # Ejemplo de uso
-- lambdas = [lambda x: x+10, lambda x: x*x, lambda x: x ** 2]
-- valores = [3, 5, 8]
--
-- result = aplicativo(lambdas, valores)
-- print(result)
