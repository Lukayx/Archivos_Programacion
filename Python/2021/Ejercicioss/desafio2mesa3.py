def generaAleatorio(palabra):
    lista = []
    for i in range(5):
        if(i==0):
            n=palabra[0]+palabra[2]+palabra[1]
        else:
            if(i==1):
                n=palabra[1]+palabra[2]+palabra[0]
            else:
                if(i==2):
                    n=palabra[1]+palabra[0]+palabra[2]
                else:
                    if(i==3):
                        n=palabra[2]+palabra[1]+palabra[0]
                    else:
                        if(i==4):
                            n=palabra[2]+palabra[0]+palabra[1]
        lista.append(n)
    return lista
def main():
    k=True
    palabra = input("Ingrese una palabra de 3 caracteres: ")
    lista=[palabra]
    lista = generaAleatorio(palabra)
    while(k):
        z = input("")
        


main()
