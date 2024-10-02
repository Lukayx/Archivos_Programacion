-- INFO188 2021
-- Prueba I
-- NOTA: Para cada ejercicio, hacer contratos y explicar la intuicion detras de su solucion.
-- 
--
-- 1) Numeros coprimos
-- Dos numeros son coprimos si es que su unico dividor en comun es 1. Programar la funcion 'coprimo', 
-- que recibe dos numeros y responde si estos son coprimos o no 
-- Ejemplo:
-- > coprimo 14 25
-- True
-- > coprimo 9 15
-- False
-- > coprimo 133 532
-- False
gcd' :: Int -> Int -> Int
gcd' a b = if b == 0
            then a
            else gcd b (a `mod` b)

coprimo :: Int -> Int -> Bool
coprimo a b = gcd' a b == 1




-- 2) Creando un operador generalizado entre vectores
-- Crear un operador generalizado entre dos vectores k-dimensionales en base 
-- a dos funciones pasadas como argumento. La funcion se usa como
-- vecop f g vector1 vector2
-- En donde 'g' opera entre las componentes del vector, mientras que 'f' entre los resultados 
-- que entrega 'g', generando un elemento final reducido.
-- Ejemplo:
-- producto punto       --> vecop (+) (*) [1,2,3] [4,5,6]
-- opuesto prod. punto  --> vecop (*) (+) [1,2,3] [4,5,6]
vecop :: (b -> b -> b) -> (a -> a -> b) -> [a] -> [a] -> b
vecop f g xs ys = foldl1 f $ zipWith g xs ys




-- 3) Typeclass 'Evo'
-- Sea 'Evo' el typeclass que hace crecer o decrecer un type constructor
--
-- a) Definir el typeclass 'Evo', el cual tiene dos funciones: 'env' y 'pel'
--  - 'env' recibe un tipo y entrega un nuevo tipo envuelto por su propio tipo.
--  - 'pel' recibe un tipo y entrega un nuevo tipo el contenido del interior.

class Evo c where
    env :: c a -> c (c a)
    pel :: c a -> a

-- b) Haga que Maybe sea instancia de 'Evo'
instance Evo Maybe where
    -- env
    env Nothing = Just Nothing
    env (Just x) = Just (Just x)
    -- pel
    pel Nothing = error "llegamos a la nada"
    pel (Just x) = x


-- c) Haga que Either sea instancia de 'Evo'
instance Evo (Either a) where
    env (Left x)    = Left x
    env (Right x)   = Right (Right x)
    -- pel
    --pel (Left x)    = error "no pel on Left"
    pel (Left x)    = error "no pel on Left"
    pel (Right x)   = x
    

-- d) Proponga un comportamiento 'env' y 'pel' para el siguiente arbol. Justifique la logica que propuso.
instance Evo Tree where
    -- env
    env E         = N E E E
    env (N x l r) = N (N x E E) (env l) (env r)
    -- pel
    pel E = error "error al aplicar pel a E"
    pel (N x l r) = x

data Tree a = E | N a (Tree a) (Tree a) deriving (Show, Read, Eq)

-- nodo base
singleton :: a -> Tree a  
singleton x = N x E E  

-- crear arbol a partir de una lista
treeBuild :: (Ord a) => [a] -> Tree a
treeBuild xs = foldr treeInsert E xs

-- funcion insertar (arbol binario de busqueda,  l > r)
treeInsert :: (Ord a) => a -> Tree a -> Tree a  
treeInsert x E = singleton x  
treeInsert x (N a left right)   
    | x == a = N x left right  
    | x < a  = N a (treeInsert x left) right  
    | x > a  = N a left (treeInsert x right)



-- funcion para ver si un elemento pertenece a un arbol o no
treeElem :: (Ord a) => a -> Tree a -> Bool  
treeElem x E = False  
treeElem x (N a left right)  
    | x == a = True  
    | x < a  = treeElem x left  
    | x > a  = treeElem x right
