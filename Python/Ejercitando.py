from random import *

def creaVuelos():
    NumVuelo = creaNumerosVuelo()
    Fechas = creaFechas()
    capacidad = creaCapacidadVuelo()
    Lista = creaLista(NumVuelo, Fechas, capacidad)
    return(Lista)

def main():
    fechaVuelos = creaVuelos()
    Dia,Vuelos = leeDiaOctubre(fechaVuelos)
    numeroVuelo,pasajeros = calculaVueloMayor(fechaVuelos)
    ImprimeVuelos(Dia,Vuelos,fechaVuelos,numeroVuelo, pasajeros)

def creaNumerosVuelo():
    num = randint(10,20)
    Lista = [num]
    for i in range(1,5):
        Lista.append(num+i)
    return Lista

def creaFechas():
    lista = []
    for i in range (5):
        lista.append((2020,10,randint(10,15)))
    for i in range(1,len(lista)):
        for j in range(len(lista)-i):
            if(lista[j][2]>lista[j+1][2]):# ? ---------Condicional--------- ? #
                temp = lista[j]
                lista[j]=lista[j+1]
                lista[j+1]=temp
    return lista

def creaCapacidadVuelo():
    Lista = []
    for i in range(5):
        Lista.append(randint(1,313))
    return Lista

def creaLista(numVuelos,fecha,capacidad):
    Lista = []
    for i in range (5):
        Lista.append((numVuelos[i],fecha[i],capacidad[i]))
    return Lista

print(creaVuelos())