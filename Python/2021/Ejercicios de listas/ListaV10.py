def llenaLista():
    a = int(input("¿Cuantos numeros quiere ingresar? "))
    while(a<2):
        a = int(input("¿Cuantos numeros quiere ingresar? "))
    lista=[]
    for i in range(a):
        num = input(str(i+1)+")- ")
        lista.append(num)
    return lista

def OrdenaMenorMayor(lista):
    for i in range(1,len(lista)):
        for j in range(len(lista)-i):
            if(lista[j]>lista[j+1]):
                temp = lista[j]
                lista[j]=lista[j+1]
                lista[j+1]=temp
    return lista

def imprimeLista(lista):
    for i in lista:
        print("'"+i+"'",end=" ")

lista = llenaLista()

lista = OrdenaMenorMayor(lista)

imprimeLista(lista)