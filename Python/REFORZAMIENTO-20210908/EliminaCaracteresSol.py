#EliminaCaracteres.py
def main():
	frase = leeFrase()# lee frase hasta que no sea vacía
	caracter = leeCaracter()# lee carácter hasta que sea uno. 
	nuevaF = omiteCaracter(frase,caracter)# elimina de la frase el carácter ingresado
	resultadosObtenidos(frase,caracter,nuevaF)# muestra los resultados
#
def leeFrase():
	f = input("Ingrese frase no vacía, ni con puros espacios: ")
	while(len(f) == 0 or soloEspacios(f)):
		if(len(f) == 0):
			print(" Nada ingresó!!")
		else:
			print("Ingresó sólo espacios!!")
		f = input("Ingrese frase no vacía, ni con puros espacios: ")
	return f
#
def soloEspacios(f):
	Largo = len(f)
	noVale = True
	i = 0
	while(i < Largo and noVale):
		if(f[i] != " "):
			noVale = False
		i += 1
	return noVale
#
def leeCaracter():
	c = input("Ingrese el carácter a eliminar de la frase: ")
	largo = len(c)
	while(largo == 0 or largo > 1):
		if(largo == 0):
			print("Nada ingresó!!")
		else:
			print("Ingresó más de 1 carácter!!")
		c = input("Ingrese el carácter a eliminar de la frase: ")
		largo = len(c)
	return c
#
def omiteCaracter(f,c):
	Largo = len(f)
	nf = ""
	for i in range(Largo):
		if(f[i] != c):
			nf = nf + f[i]
	return nf
#
def resultadosObtenidos(f,c,nf):
	print(f"A la frase:  {f} ",end="")
	print(f"se le eliminó el carácter {c}. El resultado fue:")
	print(f"{nf}")
#
main()
