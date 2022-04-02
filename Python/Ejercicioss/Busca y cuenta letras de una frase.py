def main():
    palabra = input("Ingrese palabra: ")
    while(True):
        if validarCaracteres(palabra):
            break
        print("ERROR: sólo se permiten textos con caracteres alfabéticos y espacion, y que no se repitan sus letras")
        palabra = input("Ingrese palabra: ")
    frase = input("Ingrese frase: ")
    cuentaLetras(palabra,frase)

def validarCaracteres(palabra):
    palabra = palabra.replace(" ", "")
    palabra = palabra.lower()
    for i in palabra:
        x = palabra.count(i)
        if x!=1:
            return False
    if palabra.isalpha():
        return True
    return False

def cuentaLetras(palabra,frase):
    for i in palabra:
        x = frase.count(i)
        print(f"{i} está {x} veces en la frase")

main()