def verifica_ganador_horizontal_vertical(M):
    base = len(M[0])
    altura = len(M)
    for i in range(altura):
        for j in range(base-3): # * Verifica Horizontales * #
            if M[i][j] == M[i][j+1] == M[i][j+2] == M[i][j+3] == 'O':
                return 'O'
            if M[i][j] == M[i][j+1] == M[i][j+2] == M[i][j+3] == 'X':
                return 'X'
    for i in range(altura-3): # * Verifica Verticales * #
        for j in range (base):
            if M[i][j] == M[i+1][j] == M[i+2][j] == M[i+3][j] == 'O':
                return 'O'
            if M[i][j] == M[i+1][j] == M[i+2][j] == M[i+3][j] == 'X':
                return 'X'
    for i in range(altura-3): # * Verifica Diagonal -> * #
        for j in range(base-3):
            if M[i][j] == M[i+1][j+1] == M[i+2][j+2] == M[i+3][j+3] == 'O':
                return 'O'
            if M[i][j] == M[i+1][j+1] == M[i+2][j+2] == M[i+3][j+3] == 'X':
                return 'X'
    for i in range(altura-3): # * Verifica Diagonal <- * #
        for j in range(-1,-base+3): 
            if M[i][j] == M[i+1][j-1] == M[i+2][j-2] == M[i+3][j-3] == 'O':
                return 'O'
            if M[i][j] == M[i+1][j-1] == M[i+2][j-2] == M[i+3][j-3] == 'X':
                return 'X'
    return '.'
	# revisa M para retornar 'X', 'O' o '.'

def generaTablero():
    matriz = []
    for i in range(10):
        matriz.append([])   
        for j in range(8):
            matriz[i].append(".")
    return matriz

def imprimeTablero(M):
    filas = len(M)
    for i in range(filas):
        for j in M[i]:
            print(j," ",end="")
        print()
    print("0  1  2  3  4  5  6  7")

def validaEntrada():
    numColumna = int(input("Ingrese num columna: "))
    while(numColumna<0 or numColumna>7):
        numColumna = int(input("Ingrese una columna correcta: "))
    return numColumna

def colocaFicha(M, posicion, cont):
    for i in range(10):
        if M[i][posicion] == ".":
            if(cont%2==0):
                M[i][posicion] = "X"
                return M
            else:
                M[i][posicion] = "O"
                return M
    print("No hay mas espacio en esa columna")
    return M

def main():
    M = generaTablero() 
    cont = 0 
    while (verifica_ganador_horizontal_vertical(M) == '.'): 
        imprimeTablero(M) 
        posicion = validaEntrada() 
        M = colocaFicha(M, posicion, cont) 
        cont += 1 
    imprimeTablero(M) 
    print(f"El ganador es {verifica_ganador_horizontal_vertical(M)}!")

if __name__ == "__main__":
    main()