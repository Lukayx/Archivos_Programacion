module Tools where
-- I) FUNCIONES BASICAS
-- funcion que duplica
doubleMe x = x + x

-- funcion que suma duplicados
doubleUs x y = x*2 + y*2

-- doblar numero pequeno
doubleSmallNumber x = if x > 100 
                  then x
                  else x*2