from random import *

def OrdenaDescendente(lista):
    for i in range(1,len(lista)):
        for j in range(len(lista)-i):
            if(lista[j]<lista[j+1]):
                temp = lista[j]
                lista[j]=lista[j+1]
                lista[j+1]=temp
    return lista

def generaBinario():
    bits=randint(3,6)
    binario=""
    for j in range(bits):
        b=str(randint(0,1))
        binario=binario+b
    return binario

def imprimeBinarios(lista):
    for i in range(len(lista)):
        if i==len(lista)-1:
            print(lista[i])
        else:
            print(lista[i],end=" ")

def convierteDecimal(binario):
    decimal=0
    for i in range(len(binario)):
        decimal+=int(binario[i])*2**(len(binario)-i-1)
    return decimal

a = randint(2,9)
lista=[]
for i in range(a):
    lista.append(generaBinario())

print("Lista de binarios generada:")
imprimeBinarios(lista)

print("Lista de binarios ordenada:")