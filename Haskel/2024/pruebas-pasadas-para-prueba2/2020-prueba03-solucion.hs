-- PRUEBA 3: INFO188 -- PAUTA
-- Fecha: 13 de Noviembre
import System.Random
import System.IO
-- Ejercicios:
-- I)  Creee un tipo de dato que representa un arbol familiar de 
--     seres extraterrestres que se reproducen individualmente (sin pareja).
--     Cada "Ser" del arbol tiene una "edad" y ademas puede tener 0, 1 o mas hijos. 
--     Consejo 1: A pesar de que sabe que la edad es un numero, formule su tipo como type
--     constructor.
data Arf a = Ser a [Arf a] | ArfVacio
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

evo :: (Num a) => StdGen -> Int -> Arf a -> Arf a
evo r 0 fam = fam
evo r gens ArfVacio = ArfVacio
evo r gens q@(Ser e xs) = let (x, r') = randomR (1,1000) r :: (Int, StdGen)
                          in evo r' (gens-1) (nextGen (mkStdGen x) q)
                              
nextGen :: (Num a) => StdGen -> Arf a -> Arf a
nextGen r ArfVacio = ArfVacio
nextGen r q@(Ser e xs) = let 
                            (x,r') = randomR (0,1) r :: (Float, StdGen)
                            h = if (x < 0.5) then [Ser 1 [ArfVacio]] else []
                            qq@(Ser edad lista) = fmap (+20) q
                            in Ser edad ((map (nextGen r') lista) ++ h)

-- IV) Escriba una funcion que exporte el arbol a un archivo. Proponga usted un
--     formato y expliquelo.
--     FORMATO: lista de seres, con un numero que indica cuantos hijos tendra.
instance Show a => Show (Arf a) where
    show (ArfVacio) = ""
    show (Ser e xs) = let h = length xs - 1
                      in "Ser "++(show e)++"\n"++(show $ h)++"\n"++(foldl (\acc x -> acc ++(show x)) "" xs)

exportArbol :: (Show a) => Arf a -> IO ()
exportArbol ser = do
            let contents = show ser
            writeFile "aliens.txt" contents
            return ()
