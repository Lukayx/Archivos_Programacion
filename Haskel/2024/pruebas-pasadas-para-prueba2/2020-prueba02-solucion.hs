-- PRUEBA 2: INFO188 - SOLUCION
-- Fecha: 27 de Octubre 2020
--
-- Ejercicios:
-- I) Crear un modulo llamado Bloque que implementa las funciones
--  a) mLadrillo (x,y,z)
--  b) mConcreto (x,y,z)
--  c) mMadera (x,y,z)
module Bloque(
mLadrillo,
mConcreto,
mMadera)
where

mLadrillo :: (Float,Float,Float) -> Float
mLadrillo (x,y,z) = (x*y*z) * 2000

mConcreto :: (Float,Float,Float) -> Float
mConcreto (x,y,z) = (x*y*z) * 2400

mMadera :: (Float,Float,Float) -> Float
mMadera (x,y,z) = (x*y*z) * 500
--
--  las cuales reciben como argumento una 3-tupla que representa las dimensiones 
--  en metros de un bloque 3D (largo, ancho, alto). 
--  Cada funcion retorna el peso en kg del bloque.
--  La densidad del ladrillo es 2000 kg/m^3.
--  La densidad del concreto es 2400 kg/m^3
--  La densidad de la madera es  500 kg/m^3.
--
--
--
--
--
--
--
-- II) Crear un modulo llamado Pilar que implementa las funciones
module Pilar(
checkPilar,
alturaPilar,
cantidadMaterial
)
where

--  a) checkPilar [mat, (x,y,z), mat, (x,y,z), ..., mat, (x,y,z)]
checkPilar :: [(String, (Float,Float,Float))] -> Bool
checkPilar [] = True
checkPilar = _checkPilar 0 xs

_check :: Float -> [(String, (Float,Float,Float))] -> Bool
_check _ [] = True
_check m (x:xs) 
    | (fst x) == "l" = let x = mLadrillo (snd x)
                         acc = m + x 
                     in (acc > 2000) && _check acc xs
    | (fst x) == "c" = let x = mConcreto (snd x)
                         acc = m + x 
                     in (acc > 2400) && _check acc xs
    | (fst x) == "m" = let x = mMadera (snd x)
                         acc = m + x 
                     in (acc > 500) && _check acc xs
--
--  Que recibe una lista de material seguido por un bloque (3-tupla), asi indicando una 
--  lista de bloques cada uno con su material indicado (mat). El primer elemento es el 
--  bloque de mas arriba, el ultimo es el de mas abajo. Represente mat segun su conveniencia.
--  La funcion debe verificar si el pilar soporta su propio peso (True) o no (False). 
--  Un pilar se rompe (deja de soportar su propio peso) si existe un bloque que debe soportar 
--  un peso mayor al de 1 m^3 de su material.
--
--
--  b) alturaPilar [mat, (x,y,z), mat, (x,y,z), ..., mat, (x,y,z)]
--  La funcion debe calcular la altura del pilar.
alturaPilar :: [(String, (Float, Float, Float)] -> Float
alturaPilar [] = 0
alturaPilar ((mat, (x,y,z)):xs) = y + (alturaPilar xs)
--
--
--  c) cantidadMaterial mymat [mat, (x,y,z), mat, (x,y,z), ..., mat, (x,y,z)]
--  La funcion debe calcular la cantidad de volumen de material de tipo M en un pilar.
cantidadMaterial :: [(String, (Float, Float, Float)] -> Float
cantidadMaterial _ [] = 0
cantidadMaterial mat ((id,(x,y,z)):xs) = if (id == mat) 
                                            then 
                                                (x*y*z) + (cantidadMaterial mat xs)
                                            else
                                                0 + (cantidadMaterial mat xs)

--
-- 
--
--
--
--
--
--
--
-- III) Crear un modulo llamado Templo, que implementa las funciones
-- a) temploTerremoto R [pilares]
-- Se debe testear si el templo resistira un terremoto de magnitud 'R'. Un templo resiste 
-- un terremoto si es que todos los pilares soportan su propio peso y ademas si todos tienen una altura <= 10*R.
temploTerremoto :: Float -> [[(String, (Float, Float, Float)]] -> Bool
temploTerremoto R (x:xs) = ((alturaPilar x) < 10*R) && (checkPilar x) && temploTerremoto R xs

-- b) temploAcustica [pilares] 
-- Se debe testear la calidad acustica del templo. Para ello, al menos el 40% del material 
-- usado en los pilares debe estar compuesto de madera.
temploAcustica :: [[(String, (Float, Float, Float)]] -> Bool
temploAcustica (x:xs) = let m = cantidadMaterial "m" x
                            c = cantidadMaterial "c" x
                            l = cantidadMaterial "l" x
                            in ((m / (m+c+l)) >= 0.4) && temploAcustica xs
--
-- 
--
--
