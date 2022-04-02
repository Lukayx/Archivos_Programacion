def corbata():
    a = int(input("Ingrese el ancho del tringulo: "))
    while(a%2==0):
        a = int(input("ERROR!, Ingrese el ancho del tringulo:"))
    
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

corbata()
