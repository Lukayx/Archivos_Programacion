def RemplazaCaracteres(frase): # ? REEMPLAZA LETRAS DE UNA FRASE Y DEVUELVE OTRA  ? #
    frasenueva=""
    for letra in frase:
        if letra != ' ':
            frasenueva += letra 
    print(frasenueva)

frase = input("Ingrese una frase: ")

RemplazaCaracteres(frase)