#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Cree un programa que reciba unna frase del usuario y retorne la cantidad de veces que aparece cada palabra contenida en ese mensaje

// "paco compró pocas copas, como pocas copas compró, pocas copas pagó"
// paco 1
// compró 2
// pocas 3
// copas 3
// como 1
// pagó 1

/*
vector<string> extraePalabras(string frase){
	// "paco compró pocas copas, como pocas copas compró, pocas copas pagó"
	// paco -> "compró pocas copas, como pocas copas compró, pocas copas pagó" agrega a vector
	// compró -> "compró pocas copas, como pocas copas compró, pocas copas pagó"
	// compró -> "pocas copas, como pocas copas compró, pocas copas pagó"

};*/

int retornaFrecuencia(string palabra, string frase){
	int cantidad = 0;
	int pos = 0;
	do{
		pos = frase.find(palabra,pos);
		if(pos != (int)frase.npos){
			cantidad++;
			pos++;
		}
	}while(pos != (int)frase.npos);
	return cantidad;
}

bool existeEn(string palabra, vector<string> lista){
	bool respuesta = false;
	for(int i=0;i<(int)lista.size();i++)
		if(lista[i] == palabra)
			respuesta = true;
	return respuesta;
}

void cuentaPalabras(string frase, vector<string> &palabras, vector<int> &frecuencia){
	// "paco compró pocas copas, como pocas copas compró, pocas copas pagó"
	frase += " ";
	// "paco compró pocas copas, como pocas copas compró, pocas copas pagó "
	int posInicio=0, posFin;
	cout << frase << endl;
	cout << "largo frase: " << frase.size() << endl;
	
	do{
		posFin = frase.find_first_of(" ,.¿?",posInicio); // encuentra posición del próximo espacio o coma o punto
		string palabraAux = frase.substr(posInicio,posFin-posInicio);
		cout << "encontre palabra: ." << palabraAux << ".\n";
		
		if(!existeEn(palabraAux,palabras) && palabraAux.size()!=0){
			cout << "voy a agregar palabra: ." << palabraAux << ".\n";
		
			palabras.push_back(palabraAux); // registra palabra en vector palabras
		
			// registra la cantidad de veces que esa palabra está en la frase
			frecuencia.push_back(retornaFrecuencia(palabraAux, frase));
		}
		posInicio = posFin+1;
	}while(posFin != (int)frase.npos);
};

//int cuentaEn(string palabra, string frase);

int main(){
	// leer frase dedsde el usuario
	string frase;
	//cout << "Ingrese frase: ";
	//getline(cin,frase); //(comentado solo para evitarse la lata de escribir cada vez)
	frase = "¿paco compro pocas copas, como pocas copas compro, pocas copas pago?";//"uno dos tres uno tres tres"; // uno 2, dos 1, tres 3
	
	// dos vectores distintos, una para palabras y otra para frecuencia (mismo tamaño, mismo orden)
	vector<string> palabras;
	vector<int> frecuencia;
	
	// invocar función que devuelva vector con palabras
	//palabras = extraePalabras(frase);
	cuentaPalabras(frase, palabras, frecuencia);
	
	//vector<int> frecuencia(extraePalabras.size(),0)
	
	
	/*
	// recorrer vector de palabras y contar en la frase cuántas veces aparece
	for (long unsigned int i=0; i<palabras.size();i++)
		frecuencia[i] = cuentaEn(palabras[i],frase);
	*/
	// imprimir resultados
	for (long unsigned int i=0; i<palabras.size();i++)
		cout << palabras[i] << "\t" << frecuencia[i] << endl;
	
	return 0;
}