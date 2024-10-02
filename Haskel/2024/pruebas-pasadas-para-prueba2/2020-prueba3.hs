-- PRUEBA 3: INFO188
-- Fecha: 13 de Noviembre
--
-- LEER, INSTRUCCIONES:
-- a) Cada solucion debe incluir contrato y explicar con comentarios el algoritmo.
-- b) Puede implementar funciones auxiliares para apoyarse.
-- c) Todas las preguntas tienen el mismo puntaje.
-- d) Subir su(s) archivo(s) como un archivo comprimido llamado info188-p3-nombre.zip.
-- e) Respete los tiempos de siveducMD, es un sistema automatico.
--
--
--
--
--
--
-- Ejercicios:
-- I)  Creee un tipo de dato que representa un arbol familiar de 
--     seres extraterrestres que se reproducen individualmente (sin pareja).
--     Cada "Ser" del arbol tiene una "edad" y ademas puede tener 0, 1 o mas hijos. 
--
--     Consejo 1: A pesar de que sabe que la edad es un numero, formule su tipo como type
--     constructor.
--
import System.Random

data Arf a = Ser a [Arf a] | ArfVacio deriving (Show)
--
--
--
--
--
-- II) Haga que su arbol familiar sea una instancia de Functor.
instance Functor Arf where
    fmap f ArfVacio = ArfVacio
    fmap f (Ser e xs) = Ser (f e) (map (fmap f) xs)







-- III) Implementar la funcion "evo StdGen gens <Arbol>", la cual avanza el arbol familiar 
--      en "gens" generaciones en el tiempo. Avanzar en una generacion en el tiempo 
--      significa que:
--      a) Cada ser aumenta su edad en 20 anios.
--      b) Cada ser tiene una probabilidad de 50% de tener un hijo.
--      (Nota: no importa si su solucion provoca que los hermanos 
--             tengan la misma cantidad de hijos)
--

evo :: (Num a) => StdGen -> Int -> Arf a -> Arf a
evo r 0 fam = fam
evo r gens ArfVacio = ArfVacio
evo r gens q@(Ser e xs) = let (x, r') = randomR (1,1000) r :: (Int, StdGen)
                          in evo r' (gens-1) (nextGen (mkStdGen x) (fmap (+20) q))
                              


nextGen :: (Num a) => StdGen -> Arf a -> Arf a
nextGen r ArfVacio = ArfVacio
nextGen r q@(Ser e xs) = let 
                            (x,r') = randomR (0,1) r :: (Float, StdGen)
                            h = if (x < 0.5) then [Ser 1 [ArfVacio]] else []
                            in Ser e ((map (nextGen r') xs) ++ h)






-- IV) Escriba una funcion que exporte el arbol a un archivo. Proponga usted un
--     formato y expliquelo.
