def squareSimbol(a,b):
    for i in range(1,b+1):
        if(i%2==0):
            for j in range(1,a+1):
                if(j%2==0):
                    print("+",end="")
                else:
                    print("-",end="")
            print()
        else:
            for j in range(1,a+1):
                if(j%2==0):
                    print("-",end="")
                else:
                    print("+",end="")
            print()

x = int(input("Ingrese el largo: "))
y = int(input("Ingrese el alto: "))

squareSimbol(x,y)

