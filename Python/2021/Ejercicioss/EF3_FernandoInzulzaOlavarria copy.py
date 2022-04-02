def verifica_ganador_horizontal_vertical(M):
        base = len(M[0])
        altura = len(M)
        for i in range(altura):
                for j in range(base-3): # Verifica Horizontales
                        if M[i][j] == M[i][j+1] == M[i][j+2] == M[i][j+3] == 'O':
                                return 'O'
                        if M[i][j] == M[i][j+1] == M[i][j+2] == M[i][j+3] == 'X':
                                return 'X'
        for i in range(altura-3):
                for j in range (base):
                        if M[i][j] == M[i+1][j] == M[i+2][j] == M[i+3][j] == 'O':
                                return 'O'
                        if M[i][j] == M[i+1][j] == M[i+2][j] == M[i+3][j] == 'X':
                                return 'X'
        return '.'
	# revisa M para retornar 'X', 'O' o '.'

def main():
	# M1: base 9 y altura 8 retorna '.'
	M1 = [
        ['.','.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','X','.','.','.'],
        ['.','.','.','.','O','O','.','.','.'],
        ['.','.','.','X','O','X','O','.','.'],
        ['.','.','O','X','X','O','O','X','.']
        ]
	#print(M1)

	# M2: base 10 y altura 5: gana 'O'
	M2 = [
        ['.','.','.','.','.','.','.','.','.','.'],
        ['.','.','O','.','.','.','.','.','.','.'],
        ['.','.','O','.','X','.','.','.','.','.'],
        ['.','.','O','.','O','.','X','.','.','.'],
        ['.','.','O','X','X','X','O','.','.','.']
        ]

	# M3: base 8 y altura 6: gana 'X'
	M3 = [
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','O','.','O','.','.','.'],
        ['.','X','X','O','X','O','.','.'],
        ['.','O','O','O','X','X','X','X']
        ]

	print(f'debiera mostrar ".": {verifica_ganador_horizontal_vertical(M1)}')
	print(f'debiera mostrar "O": {verifica_ganador_horizontal_vertical(M2)}')
	print(f'debiera mostrar "X": {verifica_ganador_horizontal_vertical(M3)}')

if __name__ == "__main__":
	main()
