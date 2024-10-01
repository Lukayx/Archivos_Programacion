data Vector a = Vector a a a deriving (Show)

vplus :: (Num t) => Vector t -> Vector t -> Vector t
vplus (Vector i j k) (Vector l m n) = Vector (i+l) (j+m) (k+n)

vectMult :: (Num t) => Vector t -> t -> Vector t
vectMult (Vector i j k) m = Vector (i*m) (j*m) (k*m)

scalarMult :: (Num t) => Vector t -> Vector t -> t  
(Vector i j k) `scalarMult` (Vector l m n) = i*l + j*m + k*n

-- Definimos la función safeDiv
safeDiv :: (Eq a, Fractional a) => a -> a -> Maybe a
safeDiv _ 0 = Nothing           -- Si el divisor es 0, devuelve Nothing
safeDiv x y = Just (x / y)      -- Si no, devuelve Just con el resultado de la división

-- Función para mostrar el resultado de manera amigable
showDivResult :: Maybe Double -> String
showDivResult Nothing = "Error: División por cero"
showDivResult (Just result) = "El resultado es: " ++ show result

funcion :: String-> String -> Maybe String
funcion x y 
  | x == y = Just "Son iguales"
  | (x == "" || y == "") = Nothing
  | otherwise = Just (x ++ " " ++ y)

showFuncion :: Maybe String -> String
showFuncion Nothing = "Error: Uno de los strings está vacío"
showFuncion (Just result) = result

data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday
  deriving (Eq, Ord, Show, Read, Bounded, Enum) --Para que Day se pueda operar como pertenecientes a esas Type classes

