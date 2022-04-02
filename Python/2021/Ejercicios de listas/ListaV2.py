lista=[]

n = int(input("Ingrese un numero entero: "))
if(n!=0):
    lista.append(n)
    while(n!=0):
        n = int(input("Ingrese un numero entero: "))
        if(n!=0):
            lista.append(n)
    print(lista)
    for i in lista:
        print(i, end=" ")
    print("\n")
else:
    print("Al ingresar 0 no se añadio ningun valor a la lista")
    print()

