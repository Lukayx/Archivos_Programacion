def OrdenaMayorMenor(lista):
    for i in range(1,len(lista)):
        for j in range(len(lista)-i):
            if(lista[j]<lista[j+1]):# ? ---------Condicional--------- ? #
                temp = lista[j]
                lista[j]=lista[j+1]
                lista[j+1]=temp
    return lista

def OrdenaMenorMayor(lista):
    for i in range(1,len(lista)):
        for j in range(len(lista)-i):
            if(lista[j]>lista[j+1]):# ? ---------Condicional--------- ? #
                temp = lista[j]
                lista[j]=lista[j+1]
                lista[j+1]=temp
    return lista

def Mostrar(lista): # ? MUESTRA LISTA ? #
    for i in range(len(lista)):
        for j in range (2):
            print(lista[i][j],end=" ")
        print()

def Repetidos(lista): # ? RECIBE LISTA Y DEVUELVE NUMERO MAS REPETIDO ? #
    rep=[[lista[0],0]]
    for i in lista:
        a=0 # * CONTADOR * #
        x=False # * TRUE = SE AGREGO UN NUMERO ; FALSE = NO SE AGREGO NINGÚN NUMERO 
        while a!=len(rep): # * ESTO ES PARA QUE NO SE PASE DEL INDICE DE LA LISTA * #
            if(i==rep[a][0]): # ? COMPRUEBA SI ES UN NUMERO PARECIDO ? #
                rep[a][1]+=1
                a=len(rep) # * CORTARÁ EL CICLO WHILE PARA NO HACER ITERACIONES INESESARIAS * #
                x=True # * COMO SE COMPROBÓ QUE SE REPITIO EL NUMERO ENTONCES SE VUELVE TRUE * #
            else:
                a+=1 # ! CONTADOR + 1 ! #
            if x==False and a==len(rep):# ? SI LLEGO AL FINAL Y NUNCA SUMÓ UN NUMERO ENTONCES AGREGARA OTRA SUB-LISTA CON ESE NUEVO NUMERO ? #
                rep.append([i,0])
    m=-1 # * CANTIDA DE REPETICIONES DEL NUMERO MAYOR (-1 PARA SIEMPRE FUNCIONE) * #
    Num_mayor_repeticion=0
    for i in range(len(rep)):# * ENCONTRARÁ NUMERO QUE MAS SE REPITE * #
        if rep[i][1] >= m:
            m=rep[i][1]
            Num_mayor_repeticion=rep[i][0]
    print("El numero que mas se repite es el", Num_mayor_repeticion)
    print(rep)

def esta_contenida(lista_1,lista_2): # ? VERIFICA SI LISTA2 ESTA CONTENIDA EN LISTA 1 ? #
    for i in range(len(lista_1)-len(lista_2)+1):
        c = 0
        for j in range(len(lista_2)):
            if(lista_2[j] == lista_1[i+j]):
                c += 1
            if(c == len(lista_2)):
                return True
    return False

def RepeticionLetras(lista): # ? RECIBE LISTA Y DEVUELVE NUMERO MAS REPETIDO ? #
    rep=[[lista[0],0]]
    for i in lista:
        a=0 # * CONTADOR * #
        x=False # * TRUE = SE AGREGO UN NUMERO ; FALSE = NO SE AGREGO NINGÚN NUMERO 
        while a!=len(rep): # * ESTO ES PARA QUE NO SE PASE DEL INDICE DE LA LISTA * #
            if(i==rep[a][0]): # ? COMPRUEBA SI ES UN NUMERO PARECIDO ? #
                rep[a][1]+=1
                a=len(rep) # * CORTARÁ EL CICLO WHILE PARA NO HACER ITERACIONES INESESARIAS * #
                x=True # * COMO SE COMPROBÓ QUE SE REPITIO EL NUMERO ENTONCES SE VUELVE TRUE * #
            else:
                a+=1 # ! CONTADOR + 1 ! #
            if x==False and a==len(rep):# ? SI LLEGO AL FINAL Y NUNCA SUMÓ UN NUMERO ENTONCES AGREGARA OTRA SUB-LISTA CON ESE NUEVO NUMERO ? #
                rep.append([i,0])
    print(rep)

def AbacoR(L): # ? IMPRIME '*' LA CANTIDAD DE VECES DE CADA NUMERO DE LA LISTA COMENZANDO POR LA POSICION 0 ? #
    for i in range(len(L)):
        for j in range(L[i]):
            print("*", end="")
        print()

def AbacoL(L): # ? IMPRIME '*' LA CANTIDAD DE VECES DE CADA NUMERO DE LA LISTA COMENZANDO POR LA ULTIMA POSICION ? #
    for i in range(len(L)-1,-1,-1):
        for j in range(L[i]):
            print("*", end="")
        print()

def BuscarPalabra(Palabra):
    for a in range(len(Palabra)-4):# * SE LE RESTA LA CANTIDAD DE LETRAS DE LA PABRA QUE BUSCAS + 1 YA QUE PYTHON QUITA 1 SIEMPRE EN CICLOS * #
        if(Palabra[a]=="p" and Palabra[a+1]=="e" and Palabra[a+2]=="r" and Palabra[a+3]=="r" and Palabra[a+4]=="o"): 
            return True
    return False

def RemplazaCaracteres(frase): # ? REEMPLAZA LETRAS DE UNA FRASE Y DEVUELVE OTRA  ? #
    frasenueva=""
    for letra in frase:
        if letra != ' ':
            frasenueva += letra 
    print(frasenueva)

def compruebaSeparadores(frase): # ? Comprueba si los separadores de linea son los indicados ? #
    x=0
    m=0
    for i in frase:
        if i == "@":
            x+=1
            m=1
        else:
            if x!=3 and m==1:
                print("ta mala")
                return False
            m=0
            x=0
    return True



"""" DIFERENCIAS ENTRE ALGORITMO BURBUJA Y QUICKSORT: 
-->EL BURBUJA FUNCIONA COMPARANDO ELEMENTOS DE 2 EN 2 EN UN CICLO E INTERCAMBIANDOLOS ASCENDENTEMENTE O DESCENDENTEMENTE,
COMENZANDO DESDE EL PRINCIPIO O DESDE EL FINAL, SEGÚN COMO SE ESPECIFIQUE
TAMBIEN SE EJECUTA MUCHAS VECES HASTA QUE NO HAYA MAS CAMBIOS
FUNCIONA BIEN E INCLUSO MEJOR SI ESTÁ SEMI ORDENADA LA LISTA 

-->EL METODO QUICKSORT FUNCIONA MEJOR PARA ELEMENTOS DESORDENADOS COMPLETAMENTE, QUE PARA SEMI ORDENADOS
PARA COMENZAR A ORDENARLO POR LO GENERAL SE ELIJE UN PIVOTE DE LA MITAD DE LA LISTA Y ASÍ ORDENAR RESPECTO A ESE PUNTO
ESTE METODO DIVIDE EL TRABAJO DEL ORDENAMIENTO Y CREA 2 LISTAS 
"""
