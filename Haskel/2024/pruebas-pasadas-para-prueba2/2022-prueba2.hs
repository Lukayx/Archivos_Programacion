-- PRUEBA 2 INFO188
-- 29 Noviembre 2022
-- Tiempo: 90mins
-- Entrega: Subir archivo <nombre-apellido>.hs en SiveducMD
-- ***************************************************************************************
-- INSTRUCCIONES:
--      - Toda funcion debe ir con contrato y una explicacion breve y clara de lo que hace.
--      - La instanciacion de un typeclass debe ir acompanado de una breve explicacion.
--      - Puede escribir funciones auxiliares para ayudar a organizar su codigo.
-- ***************************************************************************************
-- ENUNCIADO:
-- A continuacion se presenta el tipo de dato "Qtree" por QuadTree que es un arbol donde cada nodo contiene dos coordenadas que marcan un rectangulo en el plano, y ademas tiene hasta cuatro nodos hijos. 
data Qtree a = Gv | Nodo (a,a) (a,a) (Qtree a) (Qtree a) (Qtree a) (Qtree a) deriving (Show, Read, Eq)
-- Gv es 
-- 1) (2pts) Instancie el Qtree a Functor. Explique su comportamiento, y de un ejemplo de uso.
-- Functor es una clase de tipo que tiene un solo metodo, fmap, que toma una funcion y un functor y aplica la funcion a cada elemento del functor. En este caso, se aplica la funcion a cada nodo del arbol.
instance Functor Qtree where
    fmap f Gv = Gv
    fmap f (Nodo (x1, y1) (x2, y2) q1 q2 q3 q4) = Nodo (f x1, f y1) (f x2, f y2) (fmap f q1) (fmap f q2) (fmap f q3) (fmap f q4)
    --el porque se escribe fmap y f al principio es porque se esta aplicando la funcion f a cada elemento del nodo, y no a todo el nodo en si.

-- 2) (2pts) Instancie el Qtree para ser un Aplicativo. Explique su comportamiento, a que otro comportamiento conocido se asemeja, y de un ejemplo de uso.


-- 3) (2pts) Proponga un forma para que Qtree sea una Monada. Explique por que tomo tales decisiones (y por que descarto otras) para definir el comportamiento como Monada. Ademas, explique que utilidad podria tener este comportamiento y de un ejemplo.

