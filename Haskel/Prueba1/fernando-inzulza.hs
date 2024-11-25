-- PRUEBA 1 INFO188
-- 28 Agosto 2024
-- Tiempo: 90mins
-- Entrega: Subir archivo <nombre-apellido>.hs a la tarea 'prueba 1' de SiveducMD
--
-- ***************************************************************************************
-- INSTRUCCIONES:
--      - Toda funcion debe ir con contrato y una explicacion breve y clara de lo que hace.
--      - Puede escribir funciones auxiliares para ayudar a organizar su codigo
-- ***************************************************************************************
--

-- 1) (2pts) "REVISANDO MIN HEAPS"
--    Escriba una funcion llamada isMinHheap que recibe un min-heap representado como lista, 
--    y contesta TRUE si el min-heap es valido con su regla, sino de lo contrario FALSE.
--    
--    EJEMPLO 1:
--    isMinHeap [2, 3, 4, 100, 200, 10, 20]
--    True
--    
--    EJEMPLO 2:
--    isMinHeap [2, 3, 40, 100, 200, 10, 20]
--    False
--
--    RECORDATORIO: En zero-indexing (como en Haskell), en un min-heap los hijos de un 
--    elemento en posicion "i" son "2*i + 1" y "2*i + 2" y deben ser >= al padre.

isMinHeap :: (Num a, Ord a) => [a] -> a -> Bool
isMinHeap [] _ = error "Lista vacia"
isMinHeap l acc 
  | ((acc*2+1) :: Num >= (length l) || (acc*2+2) :: Num >= (length l)) = True
  | (l !! (acc*2+1) >= l !! acc && l !! (acc*2+2) >= l !! acc) = True && isMinHeap l acc+1
  | otherwise = False

      
-- 2) (2pts) "GATOS MAS CERCANOS"
--    Dada una lista de gatos donde cada uno se localiza con una tupla (x,y), escribir una funcion 'catNN'
--    que recibe una lista de gatos, y un radio de cercania `r`, retorna una lista de gatos cercanos, donde en la posicion 'i' 
--    se encontrara la lista de gatos cercanos para el i-esimo gato. Por cercano, se entiende a cualquier gato dentro del radio de otro.
--
--    EJEMPLO 1: (lista de 5 gatos y radio 2.0)
--    catNN [(1.5, 1.8), (1.6, 2.0), (5.0, 5.1), (5.3, 5.2), (1.1, 0.9)] 2.0
--    [[1,4], [0,4], [3], [2], [0,1]]
--
--    EJEMPLO 2: (lista de 4 gatos en fila y radio 1.0)
--    catNN [(1.0, 0.0), (4.0, 0.0), (8.0, 0.0), (8.5, 0.0)] 1.0
--    [[], [], [3], [2]]

--EL TERCER PARAMETRO ES UN ACC Y DEBE INICIARSE SIEMPRE EN 0
catNN :: (Floating a, Ord a) => [(a,a)] -> a -> Int -> [[Int]]
catNN [] _ _ = []
catNN l r acc
  | acc >= length l = []  -- Asegura que acc no exceda el rango
  | otherwise = buscaCercanias (l !! acc ) l r 0 : catNN l r (acc+1)

buscaCercanias :: (Floating a, Ord a) => (a,a) -> [(a,a)] -> a -> Int -> [Int] 
buscaCercanias g [] r acc = []
buscaCercanias g (x:xs) r acc
  | (g == x) = buscaCercanias g xs r (acc+1)
  | (dist <= r) = acc : buscaCercanias g xs r (acc+1)
  | otherwise = buscaCercanias g xs r (acc+1)
  where dist = sqrt((fst g - fst x)**2 + (snd g - snd x)**2)

-- 3) (2pts) "MATRICES SPARSAS" 
--    Haga una funcion 'smPrint' que reciba una matriz sparsa de tamano `n x n` en formato solo-valores-no-zero (coordenada, valor) --> ((i,j), val), 
--    ademas recibe el valor 'n' del tamano de la matriz. La funcion debe imprimir la matriz completa con su forma cuadrada, incluyendo sus valores nulos y no nulos.
--
--    EJEMPLO:
--    smPrint [((0,2), 9), ((2,0), 3), ((3,4), 5)] 5
--
--    RESULTADO:
--    0 0 9 0 0
--    0 0 0 0 0
--    3 0 0 0 0
--    0 0 0 0 5
--    0 0 0 0 0
--
--    HINT: para pasar un numero a string, use (show <num>) -->  por ejemplo:  show 3 --> "3"
