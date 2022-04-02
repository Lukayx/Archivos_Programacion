#----------------------------------FUNCION----------------------------------#
from math import sqrt,pi

def perro(a,b):
    return a*b,a+b

#---------------------------------------------------------------------------#

x,d = perro(5,6)#llamo a la funcion y le asigno los valores a las variables X y D

perrox = 10.123456789 #VARIABLE FLOAT
lista = [50,2,'perro',10,7,'gato'] 

print('funcion perro:',x,d)

print(pow(2,9))#(NUMERO,EXPONENTE)
print(abs(-4-6))#MODULO O VALOR ABSOLUTO
print(sqrt(144))#RAIZ CUADRADA
print(pi)#VALOR DE PI
print(float(5))#MUESTRA DECIMALES
print(round(perrox,6))#REDONDEA DECIMALES HASTA EL NUMERO EN EL SEGUNDO ARGUMENTO
print(len(lista))#LONGITUD DE LA LISTA
listaaa = divmod(50,11)#CREA UNA TUPLA DE FORMA(POR CUANTO ES DIVISIBLE,RESTO[SOBRA])
print(listaaa)

#ESTAS DOS COSAS FUNCIONAN DE LA MANO
#AL ORD() LE COLOCAS UN CARACTER Y TE DICE CON CUAL NUMERO EN EL CHR() TE DA SUELTA ESE CARACTER
print(ord('$'))

print(chr(36))

print(hex(20))#TE DA... COSAS XD


