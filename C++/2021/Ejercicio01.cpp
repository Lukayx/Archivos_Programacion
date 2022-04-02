//Ejercicio01.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string leeSecuencia(string r);
bool soloSeparadores(string fr, string r);
vector<string> traduceSecuencia(string noentiendo);
void imprimeTraduccion(vector<string> palabras);
string sacaUnos(string fr);
void convSecuencia(string responde);

int main(){
	string nada,responde;
	int largo;
	vector<string> palabras;
	nada = leeSecuencia("0");
	palabras = traduceSecuencia(nada);
	imprimeTraduccion(palabras);
	responde = leeSecuencia(" ");
	convSecuencia(responde);

	return 0;
}
string leeSecuencia(string r){ // 20 ptos
	if(r == "0"){
		cout << "Ingrese frase de ET" << endl;
    }else if(r == " "){
		cout << "Ingrese frase del Humano" << endl;
	}
// Función que lee  y valida una frase, y sirve tanto para una
// frase del ET, como para una frase del humano. Note que la
// función usa el parámetro r. Si r = "0", significa que es un 
// mensaje del ET. Si r = " ", significa que es un mensaje del
// humano. Esta función hará uso de la función "soloSeparadores()"

	return "";
}

bool soloSeparadores(string fr,string r){ // 10 ptos
// Función que recibe como parámetro una frase y un separador 
// (puede ser un "0" o un " "). Esta función retorna true si lo
// ingresado son sólo 0's o sólo espacios (depende del parámetro r)
// y false si lo ingresado es una frase válida

	return false;
}

vector<string> traduceSecuencia(string fr){ // 15 ptos
// Función que recibe una frase (mensaje del ET), la separa en palabras
// (detecta el 0 como separador de palabras), le quita los 1's a cada
// palabra (para ello hace uso de la función "sacaUnos()") y cada palabra
// la ingresa a una lista (estructura vector). Retorna el vector de palabras  
	vector<string> lista;

	return lista;
}

string sacaUnos(string fr){ // 10 ptos
// Función que extrae los 1's de cada una de las palabras del
// mensaje del ET. Retorna una palabra comprensible por el humano

	return "";
}

void imprimeTraduccion(vector<string> palabras){ // 5 ptos
// Función que recibe el vector de palabras y lo imprime en
// pantalla. Separa, al imprimir, cada palabra por un espacio 

}

void convSecuencia(string responde){ // 10 ptos
// Función que convierte una frase del humano en otra válida para el ET
// Esto es, agrega a cada letra un "1" a su derecha y un "0" para separar
// una palabra de otra. Además, imprime el resultado (código ET)

}

