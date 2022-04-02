def nPrimos(n):
    if(n==1):
        return False
    for i in range(2,n):
        if(n%i==0):
            return False
    return True

print(nPrimos(109))

def triangulo(x,y):

##COLINAS
    for i in range(1,x+1):
        for j in range(1,i):
            print(" ",end="")
        for h in range(y):
            for k in range((x+1)-i):
                print("**",end="")
            for f in range(1,i):
                print("  ",end="")
        print()
    for i in range(1,x+1):
        for j in range(x-i):
            print(" ",end="")
        for h in range(y):
            for k in range(i):
                print("**",end="")
            for f in range(x-i):
                print("  ",end="")
        print()


##DIAMANTES
    for i in range(1,x+1):
        for j in range(x-i):
            print(" ",end="")
        for h in range(y):
            for k in range(i):
                print("**",end="")
            for f in range(x-i):
                print("  ",end="")
        print()
    for i in range(1,x+1):
        for j in range(1,i):
            print(" ",end="")
        for h in range(y):
            for k in range((x+1)-i):
                print("**",end="")
            for f in range(1,i):
                print("  ",end="")
        print()

triangulo(5,3)

a=5

#----------------------------CORBATA--------------------------------
for i in range(1,a+1):#SE REPITE "N" VECES
    if(i<a):
        for j in range(i):#SE EJECUTA 1,2,3...N VECES
            print("+",end="")
        for k in range(1,(a*2)-(i*2)):#si a=5 entonces irá de 1 hasta 8 (7 veces)luego 6(5),4(3),2(1)
            print(" ",end="")
        for h in range(i):#SE EJECUTA 1,2,3...N VECES
            print("+",end="")
        print()
    else:
        if(i==a):#PARTE DE EL MEDIO DE CORBATA
            for n in range(1,a*2):
                print("+",end="")
            print()
                
    #PARTE BAJA DE CORBATA
for i in range(0,a-1):
    for j in range((a-1)-i,0,-1):
        print("+",end="")
    for k in range(0,(i*2)+1):
        print(" ",end="")
    for h in range((a-1)-i,0,-1):
        print("+",end="")
    print()
