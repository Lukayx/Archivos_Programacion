# Control1_Ejercicio2_NombreApellidos.py
from random import *
def creaCarton():
    x = str(randint(10,35))
    lista = [x]
    carton = x
    for i in range(13):
        while True:
            r=0
            x = str(randint(10,35))
            for j in lista:
                if x == j:
                    r=1
                    break
            if r==0:
                break
        lista.append(x)
        carton+="-"+x
    return carton

def lanzaTombola(c1,c2):
    x = str(randint(10,35))
    lista = [x]
    print("Secuencia de numeros:",x,end=" ")
    g_c1=0
    g_c2=0
    for i in range(34):
        if c1.count(lista[0+i])==1:
            g_c1+=1
        if c2.count(lista[0+i])==1:
            g_c2+=1
        if g_c1==14 and g_c2==14:
            print()
            return "Empate"
        else:
            if g_c1==14:
                print()
                return "Carton01"
            else:
                if g_c2==14:
                    print()
                    return "Carton02"
        while True:
            r=0
            x = str(randint(10,35))
            for j in lista:
                if x == j:
                    r=1
                    break
            if r==0:
                break
        lista.append(x)
        print(x,end=" ")


def main():
    Carton01 = creaCarton() # corrección: 30%
    Carton02 = creaCarton()
    print(f"Carton01: {Carton01}")
    print(f"Carton02: {Carton02}")
    Ganador = lanzaTombola(Carton01,Carton02) # corrección: 70%
    print(f"Ganador: {Ganador}")
#
main()

