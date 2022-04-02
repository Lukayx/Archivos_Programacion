from math import *
numDecimal=input("Ingrese un numero decimal: ")
x=(numDecimal)

entero = ""
decimal=""
numDec=0
cont=0
for i in x:
    if(i=="."):
        decimal=float(numDecimal)-int(entero)
        cont=1
    else:
        if(cont==1):
            numDec+=1

decimal=trunc(decimal,numDec)
entero=int(entero)

print("Entero es:",entero)
print("Decimal es:",decimal)

binario=""

while(True):
    binario+=str(entero%2)
    entero=entero//2
    if(entero == entero//2):
        break
    
binario=binario[::-1]

binDecimal=""
print(binario)
for i in range(4):
    decimal=decimal*2
    if(decimal//2==1):
        binDecimal+=str("1")
        decimal-=1
    else:
        binDecimal+=str("0")

binarioCompleto=binario+"."+binDecimal

print(binarioCompleto)
