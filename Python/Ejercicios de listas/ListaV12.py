from random import *

def OrdenaMayorMenor(lista):
    for i in range(1,len(lista)):
        for j in range(len(lista)-i):
            if(lista[j]<lista[j+1]):# ? ---------Condicional--------- ? #
                temp = lista[j]
                lista[j]=lista[j+1]
                lista[j+1]=temp
    return lista

def repetidos(lista): # * RECIBE LISTA Y DEVUELVE NUMERO MAS REPETIDO
    rep=[[lista[0],0]]
    for i in lista:
        a=0 # * CONTADOR * #
        x=False # * TRUE = SE AGREGO UN NUMERO ; FALSE = NO SE AGREGO NINGÚN NUMERO 
        while a!=len(rep): # * ESTO ES PARA QUE NO SE PASE DEL INDICE DE LA LISTA * #
            if(i==rep[a][0]): # ? COMPRUEBA SI ES UN NUMERO PARECIDO ? #
                rep[a][1]+=1
                a=len(rep) # * CORTARÁ EL CICLO WHILE PARA NO HACER ITERACIONES INESESARIAS * #
                x=True # * COMO SE COMPROBÓ QUE SE REPITIO EL NUMERO ENTONCES SE VUELVE TRUE * #
            else:
                a+=1 # ! CONTADOR + 1 ! #
            if x==False and a==len(rep):# ? SI LLEGO AL FINAL Y NUNCA SUMÓ UN NUMERO ENTONCES AGREGARA OTRA SUB-LISTA CON ESE NUEVO NUMERO ? #
                rep.append([i,0])
    m=-1 # * CANTIDA DE REPETICIONES DEL NUMERO MAYOR * (-1 PARA SIEMPRE FUNCIONE)#
    Num_mayor_repeticion=0
    for i in range(len(rep)):
        if rep[i][1] >= m:
            m=rep[i][1]
            Num_mayor_repeticion=rep[i][0]
    print("El numero que mas se repite es el", Num_mayor_repeticion)
    print(rep)

lista=[]
for i in range(15):
    lista.append(randint(-5, 5))
print("La lista desordenada es:",lista)
listaOrdenada = OrdenaMayorMenor(lista) 

print("La lista ordenada es:",listaOrdenada)

repetidos(lista)