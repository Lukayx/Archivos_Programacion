def palindromo(texto):
    texto = texto.replace(" ","")
    texto = texto.lower()
    if len(texto)<2:
        return True
    if texto[0]!=texto[-1]:
        return False
    return palindromo(texto[1:-1])

def main():
    while True:
        texto = input('Ingrese un texto, ENTER para terminar: ')
        if texto =='':
            print('programa terminado')
            break
        if palindromo(texto):
            print('El texto es palíndromo\n')
        else:
            print('El texto NO es palíndromo\n')

main()
