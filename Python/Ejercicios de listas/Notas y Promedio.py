cant = int(input("Cuantos notas desea ingresar: "))
suma = 0

lista = []
for i in range (cant):
    n = float(input(str(i+1)+")-Nota: "))
    lista.append(n)
    suma += lista[i]

print("Las notas son:",lista)
print(suma/cant)