#EliminaCaracteres.py
def main():
	frase = leeFrase()# lee frase hasta que no sea vacía
	caracter = leeCaracter()# lee carácter hasta que sea uno. 
	nuevaF = omiteCaracter(frase,caracter)# elimina de la frase el carácter ingresado
	resultadosObtenidos(frase,caracter,nuevaF)# muestra los resultados
#

