def llenaLista(n):
    L = []
    for i in range(n):
        num = int(input('Ingrese el elemento '+ str(i+1)+": "))
        L.append(num)
    print('La lista ingresada es:',L)
    return L

def abaco(L):
    print('ABACO INVERTIDO')
    for i in range(len(L)):
        for j in range(L[i]):
            print("*", end="")
        print()

n = int(input('¿Cuantos datos desea ingresar? '))
while(n<2):
    n = int(input('ERROR, Ingrese nuevamente: '))

L = llenaLista(n)
abaco(L)