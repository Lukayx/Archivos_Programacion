from random import randint

def ordenaLista(lista):
    if len(lista) != 1:
        n=min(lista)
        lista.remove(n)
        lista = ordenaLista(lista)
        lista.insert(0,n)
    return lista

n=randint(1,30)
lista= []   
for i in range(n):
    num = randint(1,50)
    while lista.count(num)!=0 and i!=0:
        num = randint(1,50)
    lista.append(num)
print(lista)
print(ordenaLista(lista))