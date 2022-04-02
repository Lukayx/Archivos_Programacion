lista = [100000,2,3,-10,1,6,7,-5]
men = lista[0]

for i in lista:
    if i < men :
        men = i

print("El numero menor es el",men)