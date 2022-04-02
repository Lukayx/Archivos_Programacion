#CuentaPalabrasSol.py
def main():
	frase = leeFrase()# lee frase hasta que no sea vacía
	palabras = contadorPal(frase)# Cuenta el n° de palabras de la frase 
	salidaResultante(frase,palabras)# muestra los resultados
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
def contadorPal(f):
	Largo = len(f)
	c = 0
	for i in range(Largo):
		if(f[i] == " "):
			c += 1
	c += 1
	return c
#
def salidaResultante(f,c):
	print(f"La frase:  {f} ",end="")
	print(f"contiene {c} palabras")
#
main()
