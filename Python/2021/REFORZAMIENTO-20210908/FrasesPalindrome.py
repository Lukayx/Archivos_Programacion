#FrasesPalindrome.py
def main():
	frase = leeFrase()# lee frase hasta que no sea vacía
	frase_li = limpiaFrase(frase)# elimina espacios entre medio
	frase_in = invierteFrase(frase_li)# invierte la frase
	compara = comparaFrases(frase_li,frase_in)# compara ambas frases
	escribeResultados(frase,compara)# Indica si frase original es palíndrome
#

