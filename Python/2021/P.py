#cambia el nombre de este archivo poniendo tu nombre y apellidos
import random as rd

def leeRango():
    class nada(Exception):
        pass
    class noNumero(Exception):
        pass
    class negativo(Exception):
        pass
    class menor10(Exception):
        pass
    class mayor50(Exception):
        pass
    while True:
        try:
            num = input("Ingrese número de elementos entre 10 y 50:")
            if num.isspace() or num == "":
                raise nada
            elif num.isdigit() and num.startswith("-"):
                raise negativo
            elif not num.isdigit() :
                raise noNumero
            elif int(num)<10:
                raise menor10
            elif int(num)>50:
                raise mayor50
            return int(num)
        except nada:
            print("no ingresó nada o sólo ingresó espacios")
        except noNumero:
            print("no ingresó un número")
        except negativo:
            print("ingresó un número negativo")
        except menor10:
            print("ingresó un número inferior a 10")
        except mayor50:
            print("ingresó un número superior a 50")

def creaClaves(N):
    c=set()
    while len(c)<N:
        c.add(rd.randint(10,80))
    return list(c)

def sumaRecursiva(C):
    if len(list(C))==1:
        return C[0]
    else:
        A = C[0]
        return A+sumaRecursiva(C[1:])

def imprimeResultados(N,C,S):
    print("El conjunto de ",N," numeros es {",end="")
    for i in range(N):
        if i != N-1:
            print(C[i],end=",")
        else:
            print(C[i],"}")
    print(f"La suma de esos numeros es {S}")

def main():
    N = leeRango() # 40% del puntaje
    C = creaClaves(N) # 20% del puntaje
    S = sumaRecursiva(C) # 20% del puntaje
    imprimeResultados(N,C,S) # 20% del puntaje

main()
