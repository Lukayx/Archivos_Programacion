-- PRUEBA 3 INFO188
-- 6 de Noviembre 2024
-- Tiempo: 90mins
-- Entrega: Subir archivo <nombre-apellido>.hs a la tarea 'prueba 3' de SiveducMD
--
-- ***************************************************************************************
-- INSTRUCCIONES:
--      - Toda funcion debe ir con contrato y una explicacion breve y clara de lo que hace.
--      - Puede escribir funciones auxiliares para ayudar a organizar su codigo
-- ***************************************************************************************
--

import Data.Monoid
-- 1) [3pts] Implemente la union de grafos (combinar sin repetir) como Monoide usando el tipo Graph que se define en base a arcos:
data Graph a = Graph [(a, a)]  deriving (Show, Eq)
    -- a) Explique bien sus funciones auxiliares que ocupara
    -- b) Muestre ejemplos operando grafos como Monoides

-- FUNCION AUXILIAR
swap (a,b) = (b,a) -- para girar la tupla (a,b) a (b,a) y viceversa 

instance (Eq a) => Semigroup (Graph a) where
    (Graph xs) <> (Graph ys) = Graph (xs ++ ys')
        where ys' = filter (\y -> not (elem y xs || elem (swap y) xs) ) ys

instance (Semigroup a,Eq a) => Monoid (Graph a) where
    mempty = Graph []
    mappend = (<>)

-- Ejemplo 1:
-- show (Graph [(1,2),(2,3),(3,4)] <> Graph [(3,4),(4,5),(5,6)])
-- "Graph [(1,2),(2,3),(3,4),(4,5),(5,6)]"

-- Ejemplo 2:
-- show (Graph [(1,2),(1,3),(1,4)] <> Graph [(1,2),(3,1),(4,1)])      
-- "Graph [(1,2),(1,3),(1,4)]"

-- Ejemplo 3:
-- show (Graph [(1,2),(1,3),(1,4)] <> Graph [(1,2),(3,1),(4,1),(1,5)])
-- "Graph [(1,2),(1,3),(1,4),(1,5)]"

-- 2) [3pts] Implemente quicksort en paralelo, decida si va a ocupar la Monada Eval o Par.
-- a) Justifique su eleccion con argumentos tecnico 
-- b) Escriba esta solucion en un archivo aparte para que sea compilado y testeado en paralelo. Incluya Makefile.
-- c) Entregue resultados de ejecucion usando 1, 2, 4, threads, en un problema lo suficientemente grande.
