import Data.List (isInfixOf) --funcion ocupada en linea 61
import Data.Char (isDigit) 

data Vector a = Vector a a a deriving (Show) --parametro de tipo 

vplus :: (Num t) => Vector t -> Vector t -> Vector t -- Suma de vectores
vplus (Vector i j k) (Vector l m n) = Vector (i+l) (j+m) (k+n) -- Suma de los componentes de los vectores

vectMult :: (Num t) => Vector t -> t -> Vector t -- Multiplicación de un vector por un escalar
vectMult (Vector i j k) m = Vector (i*m) (j*m) (k*m) -- Multiplicación de los componentes del vector por el escalar

scalarMult :: (Num t) => Vector t -> Vector t -> t  
(Vector i j k) `scalarMult` (Vector l m n) = i*l + j*m + k*n

-- Definimos la función safeDiv
safeDiv :: (Eq a, Fractional a) => a -> a -> Maybe a -- Maybe es un tipo de dato que puede ser Nothing o Just a
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

--Función para mostrar el resultado de manera amigable  
showFuncion :: Maybe String -> String 
showFuncion Nothing = "Error: Uno de los strings está vacío"
showFuncion (Just result) = result

data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday
  deriving (Eq, Ord, Show, Read, Bounded, Enum) --Para que Day se pueda operar como pertenecientes a esas Type classes

-- algunos ejemplos de ejecucion para cada typeclass son:
-- λ> Monday < Tuesday     True                                  [Typeclass Ord]
-- λ> Monday `compare` Tuesday     LT                            [Typeclass Ord]
-- λ> minBound :: Day     Monday                                 [Typeclass Bounded]
-- λ> maxBound :: Day     Sunday                                 [Typeclass Bounded]
-- λ> succ Monday     Tuesday                                    [Typeclass Enum]
-- λ> pred Tuesday     Monday                                    [Typeclass Enum]
-- λ> [Thursday .. Sunday]   [Thursday,Friday,Saturday,Sunday]   [Typeclass Enum]
-- λ> [minBound .. maxBound] :: [Day]   [Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday]   [Typeclass Enum]
-- λ> [Monday ..]   [Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday]   [Typeclass Enum]
-- λ> show Monday     "Monday"                                   [Typeclass Show]
-- λ> read "Saturday" :: Day     Saturday                        [Typeclass Read]
-- λ> Wednesday == Wednesday     True                            [Typeclass Eq]

data Either a b = Left a | Right b deriving (Eq, Ord, Read, Show)
-- Left y Right son constructores de datos que toman un argumento cada uno

data Resultado a = Vacio | Bool a deriving (Show)
-- Resultado puede ser usado en funciones como un tipo de retorno que puede ser o no un valor
--aqui se hará un ejemplo de uso de Resultado
funcionContiene14 :: String -> Resultado String -- la funcion busca el 14 dentro de un string
funcionContiene14 x 
  | "14" `isInfixOf` x = Contiene "14"
  | otherwise = Vacio
-- Esto lo que hace es   
-- Ejemplo de uso de la función
-- λ> funcionContiene14 "hola14"    Contiene "14"

parseNumber :: String -> Either String Int -- Función que parsea un string a un número
parseNumber str
  | all (`elem` "0123456789") str = Right (read str :: Int) -- Si todos los caracteres son dígitos, devuelve Right con el número
  | otherwise = Left "Error: No es un número válido" -- Si no, devuelve Left con un mensaje de error


funcionContiene14 :: String -> Either String Int
funcionContiene14 str
  | all isDigit str = Right (read str :: Int)
  | otherwise = Left "Error: No es un número válido"

-- all (> 0) [1, 2, 3]  -- True
-- all (> 0) [-1, 2, 3] -- False

-- type ErrorMessage = String
-- type Result = Either ErrorMessage Int

-- parseNumber :: String -> Result
-- parseNumber str = ...