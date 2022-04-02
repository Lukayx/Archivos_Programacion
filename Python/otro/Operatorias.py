suma=0
multiplicacion=0
divicion=0
divicion_ent=0
n = int(input("Ingrese un primer entero: "))
while(n==0):
    print("Ingreso un cero!!")
    n = int(input("Ingrese un primer entero: "))
suma+=n
multiplicacion+=n
divicion+=n
divicion_ent+=n
m = int(input("Ingrese un segundo entero: "))
while(m==0):
    print("Ingreso un cero!!")
    n = int(input("Ingrese un segundo entero: "))
suma+=m
multiplicacion*=m
divicion/=m
divicion_ent//=m
print("La suma de",n,"y",m,"usando += es:",suma) 
print("La multiplicacion de",n,"y",m,"usando *= es:",multiplicacion)
print("La divicion de",n,"y",m,"usando /= es:",divicion)
print("La divicion entera de",n,"y",m,"usando //= es:",divicion_ent)
