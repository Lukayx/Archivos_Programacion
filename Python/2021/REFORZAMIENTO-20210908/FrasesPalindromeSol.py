#FrasesPalindrome.py
def main():
	frase = leeFrase()# lee frase hasta que no sea vacía
	frase_li = limpiaFrase(frase)# elimina espacios entre medio
	frase_in = invierteFrase(frase_li)# invierte la frase
	compara = comparaFrases(frase_li,frase_in)# compara ambas frases
	escribeResultados(frase,compara)# Indica si frase original es palíndrome
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
def limpiaFrase(f):
	Largo = len(f)
	nf = ""
	for i in range(Largo):
		if(f[i] != " "):
			nf = nf + f[i]
	return nf
#
def invierteFrase(nf):
	fi = ""
	for i in range(len(nf)):
		fi = nf[i] + fi
	return fi
#
def comparaFrases(nf,fi):
	iguales = True
	i = 0
	while(iguales and i < len(nf)):
		if(nf[i] != fi[i]):
			iguales = False
		i += 1
	return iguales
#
def escribeResultados(f,iguales):
	print(f"La frase {f} ",end="")
	if(iguales):
		print(" es palíndrome!!")
	else:
		print(" no es palíndrome!!")
#
main()
