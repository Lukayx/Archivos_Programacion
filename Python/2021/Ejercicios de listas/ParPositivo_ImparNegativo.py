from random import *

def OrdenaMayorMenor(lista):
    for i in range(1,len(lista)):
        for j in range(len(lista)-i):
            if(lista[j]<lista[j+1]):# ? ---------Condicional--------- ? #
                temp = lista[j]
                lista[j]=lista[j+1]
                lista[j+1]=temp
    return lista

print()
N = int(input("Ingrese la cantidad de numero aleatorios que quiere: "))
Par_pos=[]
Imp_neg=[]
Rest=[]
for i in range(N):
    n = randint(-10,10)
    if(n%2==0 and n>0):
        Par_pos.append(n)
    else:
        if(n%2!=0 and n<0):
            Imp_neg.append(n)
        else:
            Rest.append(n)

print()
print("Par Positivo:",Par_pos )
print("Impar Negativo:",Imp_neg)
print("Restantes:",Rest)
print("---------------------Mayor_Menor---------------------")
print("Par Positivo:",OrdenaMayorMenor(Par_pos))
print("Impar Negativo:",OrdenaMayorMenor(Imp_neg))
print("Restantes:",OrdenaMayorMenor(Rest))
print()