#Formativa02_2021.py
def compruebaSeparadores(frase):
    x=0
    m=0
    for i in frase:
        if i == "@":
            x+=1
            m=1
        else:
            if x!=3 and m==1:
                return False
            m=0
            x=0
    return True

def leeFrase():
	frase = input("Ingrese frase no vacia, ni con puras arrobas: ")
	while(frase == "" or frase.startswith("@") or frase.endswith("@") or frase.count(" ")>=1 or compruebaSeparadores(frase)!=True):
		if frase == "":
			print("Nada ingresó!!")
		else:
			if frase.count("@")==len(frase):
				print("Ingresó sólo arrobas!!")
			else:
				print("Escriba una frase correcta!!")
				
		frase = input("Ingrese frase no vacia, ni con puras arrobas: ")
	return frase

def contadorPal(frase):
	nfrase = ""
	x=frase.split("@@@")
	for i in range(len(x)):
		nfrase += x[i]
		if i != len(x)-1:
			nfrase += "@"
	return len(x),nfrase

def main():
	frase = leeFrase()# lee frase hasta que:
										# no sea vacía o no tenga sólo arrobas (20%)
	palabras,nfrase = contadorPal(frase)# Modifica frase original a nfrase,
	print(palabras)
	print(nfrase)
																			# donde las tres arrobas (@@@) son
																			# reemplazadas por una única(@)
																			# Retorna nfrase y el número de
																			# palabras de nfrase (40%)
																# de la nfrase (40%) 
#

main()
