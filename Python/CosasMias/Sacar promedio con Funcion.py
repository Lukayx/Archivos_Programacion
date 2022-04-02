#----------------------------------------------------------------------------------------------------------------#

def funcion_promedio(n):
    return sum(n) / len(n)

#----------------------------------------------------------------------------------------------------------------#

num_notas = int(input("Cuantas notas desea ingresar? "))
notas = []

for i in range (0,num_notas):
    
    nota = float(input('Ingrese nota N°'+str(i+1)+': '))
    
    while(nota <1 or nota>7):
        print("ERROR!, Las notas deben ser entre 1 y 7")
        nota = float(input('Ingrese nota numero '+str(i+1)+': '))
        
    notas.append(float(nota))

for j in range(0,num_notas):
    print('Nota N°'+str(j+1)+': '+ str(notas[j]))
    
promedio = round(funcion_promedio(notas),1)


print("El promedio es ",promedio)