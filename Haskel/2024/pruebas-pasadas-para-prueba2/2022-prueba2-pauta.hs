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

-- 1) (2pts) Instancie el Qtree a Functor. Explique su comportamiento, y de un ejemplo de uso.
instance Functor Qtree where
    fmap _ Gv = Gv
    fmap f (Nodo (x1,y1) (x2,y2) h1 h2 h3 h4) = Nodo (f x1, f y1) (f x2, f y2) (fmap f h1) (fmap f h2) (fmap f h3) (fmap f h4)

-- 2) (2pts) Instancie el Qtree para ser un Aplicativo. Explique su comportamiento, a que otro comportamiento conocido se asemeja, y de un ejemplo de uso.
instance Applicative Qtree where
    pure x = (Nodo (x,x) (x,x) Gv Gv Gv Gv)
    Gv <*> _ = Gv
    _ <*> Gv = Gv
    (Nodo (f1,f2) (f3,f4) h1 h2 h3 h4) <*> (Nodo (x1,y1) (x2,y2) q1 q2 q3 q4) = Nodo (f1 x1, f2 y1) (f3 x2, f4 y2) (h1 <*> q1) (h2 <*> q2) (h3 <*> q3) (h4 <*> q4)

-- 3) (2pts) Proponga un forma para que Qtree sea una Monada. Explique por que tomo tales decisiones (y por que descarto otras) para definir el comportamiento como Monada. Ademas, explique que utilidad podria tener este comportamiento y de un ejemplo.
instance Monad Qtree where
    return x = (Nodo (x,x) (x,x) Gv Gv Gv Gv)
    Gv >>= f = Gv
    (Nodo (x1,y1) (x2,y2) h1 h2 h3 h4) >>= f = f x1 
