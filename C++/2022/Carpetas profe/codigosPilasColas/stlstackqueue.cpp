/* 
Realizaremos lo siguiente:
==========================
 1- Leeremos palabras almacenadolas en un vector 'vs' de tipo string, 
    finalizando el ingreso al ingresar el string "0". 
    Listamos también las palabras leidas
 2- Ordenaremos 'vs' crecientemente, usanto sort() con la función compare()
 3- Almacenaremos las primereas n/2 parabras (que son las menores) en un stack sMenor
    y las restantes n/2 parabras (que son las mayores) en un queue qMayor 
 4- Listaremos todos los strings eliminandolos desde sMenor y qMayor

TAREA: 
=====
Repetir el ejercicio con la siguientes modificaciones:
    1- Ordenando 'vs' ascendentemente por el largo de la palabra, y si son del mismo largo, aplicar desempate lexicográfico
    2- No parcicionar en n/2, ahora usted pedirá al usuario que ingrese un entero 'partidor',
      con este guardará en sMenor los strings <=partidor y los restantes en qMayor
*/ 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm> 	// para que podamos usar el argoritmo de ordenamiento sort()
using namespace std;

// Si devuelve true cada vez que s1>s2, entonces al usar con sort() se ordena descendentemente
bool miCompare(string s1, string s2){
	return s1>s2; // retorna true si s1>s2 y false en otro caso. 
	// Compara de izquierda a derecha simbolo a simbolo, en el primer par de 
	// simbolos distitos termina la comparacion
	// Ejemplo, si:
	//    s1= alabardasasa		
	//    s2= alabarte
	// Entonces s1 es lexicográficamente menor que s2 (en el septimo símbolo: 'd' < 't'), y por tanto retorna false
}


int main(int argc, char **argv){
	unsigned int i;
	string palabra;
	vector<string> vs;
	stack<string> sMenor;
	queue<string> qMayor;

	// 1- Llenar un vector vs con strings. Parar al ingresar un "0"
	cout << "Ingrese palabras ('0' para terminar)" << endl;
	cin >> palabra;
	while (palabra.compare("0")!=0) {
		vs.push_back(palabra);
		cin >> palabra;
	}
	cout << vs.size() << " palabras leidas:" <<  endl;
	for(i=0; i<vs.size(); i++)
		cout << vs[i] << " ";
	cout << endl;

	// 2 Ordenar
	//sort(vs.begin(), vs.end());	// ascendentemente (por defecto)
	sort(vs.begin(), vs.end(), miCompare);	// el orden lo da la función de comparación: miCompare

	cout << " Vector ordenado... " <<  endl;
	for(i=0; i<vs.size(); i++)
		cout << vs[i] << " ";
	cout << endl;

	// 3 llenar stack y queue
	for(i=0; i<vs.size()/2; i++)
		sMenor.push(vs[i]);

	for(; i<vs.size(); i++)
		qMayor.push(vs[i]);

	// 4 imprimir
	cout << "Stack sMenor:" << endl;
	while (not sMenor.empty()){
		cout << sMenor.top() << " - ";
		sMenor.pop();
	}
	cout << endl;

	cout << "Queue qMayor:" << endl;
	while (not qMayor.empty()){
		cout << qMayor.front() << " - ";
		qMayor.pop();
	}
	cout << endl;

}

