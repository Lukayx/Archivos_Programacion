def esta_contenida(lista_1,lista_2): # ? VERIFICA SI LISTA2 ESTA CONTENIDA EN LISTA 1 ? #
    for i in range(len(lista_1)-len(lista_2)+1):
        c = 0
        for j in range(len(lista_2)):
            if(lista_2[j] == lista_1[i+j]):
                c += 1
            if(c == len(lista_2)):
                return True
    return False

#_DECLARACIÓN DE VARIABLES_
Lista1 = []
Lista2 = []

#INGRESO NUMEROS LISTA 1
M = int(input("Ingrese un numero M: "))
for i in range(M):
    num = int(input('Ingrese el valor N°'+str(i+1)+': '))
    Lista1.append(num)

#INGRESO NUMEROS LISTA 2
N = int(input("Ingrese un numero M menor o igual que N: "))

while(N>M): #LISTA1 > LISTA2 ?
    N = int(input("ERROR, Ingrese un numero M menor o igual que N:"))

for j in range(N):
    num = int(input('Ingrese el valor N°'+str(j+1)+': '))
    Lista2.append(num)

#IMPRIME SI ESTA CONTENIDA O NO LO ESTÁ
if(esta_contenida(Lista1,Lista2)):
    print('La lista',Lista2,'está contenida en',Lista1)
else:
    print('La lista',Lista2,'no está contenida en',Lista1)