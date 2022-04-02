datos = int(input("Cuantos datos desea ingresar: "))

lista=[]

for i in range(datos):
    n = int(input(str(i+1) + "-Ingrese un numero entero: "))
    lista.append(n)
    print("--------------------->",lista[i])
    print()

print(lista)

for j in lista:
    print(j, end=" ")