-- INFO188 2021
-- Prueba I
-- NOTA: Para cada ejercicio, hacer contratos y explicar la intuicion detras de su solucion.
-- 
--
-- 1) Numeros coprimos (1 punto)
-- Dos numeros son coprimos si es que su unico dividor en comun es 1. Programar la funcion 'coprimo', 
-- que recibe dos numeros y responde si estos son coprimos o no 
-- Ejemplo:
-- > coprimo 14 25
-- True
-- > coprimo 9 15
-- False
-- > coprimo 133 532
-- False




-- 2) Creando un operador generalizado entre vectores (2 puntos)
-- Crear un operador generalizado entre dos vectores k-dimensionales en base 
-- a dos funciones pasadas como argumento. La funcion se usa como
-- vecop f g vector1 vector2
-- En donde 'g' opera entre las componentes del vector, mientras que 'f' entre los resultados 
-- que entrega 'g', generando un elemento final reducido.
-- Ejemplos:
-- producto punto
--  vecop (+) (*) [1,2,3] [4,5,6]
-- opuesto prod. punto
--  vecop (*) (+) [1,2,3] [4,5,6]
-- operacion nueva
--  vecop (min) (++) ["gato", "perro"] ["caballo", "cochino"]




-- 3) Typeclass 'Evo' (3 puntos)
-- Sea 'Evo' el typeclass que hace envolver un type constructor sobre si mismo


-- a) Definir el typeclass 'Evo', el cual tiene dos funciones: 'env' y 'pel' (de envolver y pelar)
--  - 'env' recibe un tipo y entrega un nuevo tipo envuelto por su propio tipo.
--  - 'pel' recibe un tipo y entrega un nuevo tipo el contenido del interior.



-- b) Incluya Maybe como instancia de 'Evo'
-- Ejemplos:
-- > env (Just 45)
--   Just (Just 45)
--
-- > env $ env (Just 45)
--   Just (Just (Just 45))
--
-- > pel (Just 45)
--   45
--
-- > pel (Just (Just 45))
--   Just 45



-- c) Incluya Either como instancia de 'Evo', y considere usar el mensaje de error en algun caso que no corresponda con el contrato.

-- > env (Right 45)
--   Right (Right 45)
--
-- > env (Left 45)
--   Left 45
--
-- > pel (Right (Right 45))
--   Right 45
--
-- > pel (Right (Left 45))
--   Left 45
    

-- d) Proponga un comportamiento 'env' y 'pel' para el siguiente arbol.
-- Ejemplo:
-- > miArbol = treeBuild [1,4,6,52,67,32]
-- > miArbol
--   N 32 (N 6 (N 4 (N 1 E E) E) E) (N 67 (N 52 E E) E)
--
-- > env miArbol
--   comportamiento propuesto
--
-- > pel miArbol
--   comportamiento propuesto

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
