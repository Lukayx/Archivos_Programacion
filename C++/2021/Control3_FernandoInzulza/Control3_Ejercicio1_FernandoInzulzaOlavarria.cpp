#include <iostream>
#include <string>
#include <vector>
using namespace std;

// modifica S para incluir la letras ingresadas en el texto
void procesa(vector<vector<char>> &S, string texto){
	int posInicio = 0;
	int posFin;
	int i = 1;
	do{
		posFin = texto.find(',');
		string palabra = texto.substr(posInicio,posFin);
		S.resize(i);
		for(int j=0;j<palabra.size();j++)
			S[i-1].push_back(palabra[j]);
		texto = texto.substr(posFin+1,texto.size());
		i++;
	}while(texto.find(',') != texto.npos);
	
}

// imprime por pantalla la sopa de letras
void imprimeMatriz(vector<vector<char>> S){
	for(int i=0; i<S.size();i++){
		for(int j=0;j<S[i].size();j++)
			cout << S[i][j];
		cout << endl;
	}
}

// busca palabra, informa posición de inicio y orientación
void buscaYreporta(vector<vector<char>> S, string palabra){
	
}

int main( int argc, char *argv[] ){
	
	vector<vector<char>> sopa;
	
	string texto, palabra;
	
	// Descomente lo que corresponda a continuación para probar su programa:
	// CASO 1
	texto = "AKTEF,IHOLA,HGMBC,LDAMJ,"; // "HOLA" en (1,1)horiz, "TOMA" en (0,2)vertic
	palabra = "HOLA";
	//palabra = "TOMA";
	//palabra = "CAMELLO"; // no está
		
	// CASO 2
	//texto = "POBMUMI,STMERAR,UZAVAOZ,TRIZOMA,NOZCISE,EUSORIT,"; // "MAIZ" en (1,2)vert, "RIZOMA" en (3,1)horiz
	//palabra = "MAIZ";
	//palabra = "RIZOMA";
	//palabra = "AJO"; // no está
	
	procesa(sopa,texto); // 12 décimas
	
	imprimeMatriz(sopa); // 4 décimas
	
	buscaYreporta(sopa,palabra); // 24 décimas
	
	return 0;
}
