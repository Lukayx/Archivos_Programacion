def Mostrar(lista):
    for i in range(len(lista)):
        for j in range (2):
            print(lista[i][j],end=" ")
        print()

def mayorEntrena(lista):
    May = lista[0][1]
    luMay = lista[0][0]
    for i in range(1,len(lista)):
        if lista[i][1] > May:
            May = lista[i][1]
            luMay = lista[i][0]
    return luMay

def BuscarPalabra(lista):
    nueva = []
    for i in range(len(lista)):
        lugar = lista[i][0]
        for a in range(len(lista[i][0])-3):# * SE LE RESTA LA CANTIDAD DE LETRAS DE LA PABRA QUE BUSCAS + 1 YA QUE PYTHON QUITA 1 SIEMPRE EN CICLOS * #
            if(lugar[a]=="I" and lugar[a+1]=="s" and lugar[a+2]=="l" and lugar[a+3]=="a"): 
                nueva.append(lugar)
    return nueva

print("--------LISTA--------")
entrenamientos=[['Fortaleza de Drago',      10],
                ['Isla de los marginados',  21],
                ['Isla de Berk',            35],
                ['Pantano Rompecuellos',    15],
                ['Isla Dragon',              5]]

Mostrar(entrenamientos)
print()

mayor = mayorEntrena(entrenamientos)
print("El lugar con mas participantes es", mayor)
print()

listaNueva = BuscarPalabra(entrenamientos)
print("---------------Lugares con palabra 'Isla'----------------")
print(listaNueva)