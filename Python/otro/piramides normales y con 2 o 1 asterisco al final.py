    #PARTE ABAJO DE RELOJ DE ARENA
x=5

for i in range(x):
    for j in range(i):
        print(" ",end="")
    for g in range(1,(x*2)-i*2):#SI LE SUMAS UN 1 DENTRO DE LA X SIEMPRE TERMINARA EN 2 ASTERISCOS
        print("*",end="")
    for j in range(i):
        print(" ",end="")
    print()

    #PARTE ABAJO DE RELOJ DE ARENA 
for i in range(1,x+1):
    for j in range(x-i):
        print(" ",end="")
    for h in range(1,i*2):
        print("*",end="")
    for j in range(x-i):
        print(" ",end="")
    print()

print("\n\n")#-------------------------DIAMANTE-------------------------#

for i in range(1,x):#si quieres que el diamante tenga 1 fila en la mitad entonces le quitas el +1 al ()
    for j in range(x-i):
        print(" ",end="")
    for h in range(1,i*2):#SI LE SUMAS UN 1 en la i*2 SIEMPRE TERMINARA EN 2 ASTERISCOS
        print("*",end="")
    for j in range(x-i):
        print(" ",end="")
    print()

for i in range(x):
    for j in range(i):
        print(" ",end="")
    for g in range(1,(x*2)-i*2):#SI LE SUMAS UN 1 DENTRO DE LA X SIEMPRE TERMINARA EN 2 ASTERISCOS
        print("*",end="")
    for j in range(i):
        print(" ",end="")
    print()
