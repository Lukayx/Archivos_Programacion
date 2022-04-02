def sufijoAntePrefijo(s, k):
    frase=""
    atras=""
    for i in range(len(s)):
        if(i>=k):
            frase+=s[i]
        else:
            atras+=s[i]
    return frase+atras

opcion="SI"
while(opcion=="SI"):
    s = input("Ingrese una frase: ")
    while(len(s)<2):
        s = input("Ingrese una frase: ")

    k = int(input("Ingresa entero k: "))
    while(k<1 and k>len(s)):
        k = int(input("Ingresa entero k: "))

    print(sufijoAntePrefijo(s, k))

    opcion = input("Desea continuar: (SI O NO) ")
    while(opcion!="SI" and opcion!="NO"):
        print("Respuesta Incorrecta")
        opcion = input("Desea continuar: (SI O NO) ")   
print("Adios!")


