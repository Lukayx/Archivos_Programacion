frase = input("Ingrese una frase cualquiera: ")
while(frase==""):
    print("mmmm debe repetir el ingreso..")
    frase = input("Ingrese una frase cualquiera: ")

x=frase.count(" ")+1
print(x)
