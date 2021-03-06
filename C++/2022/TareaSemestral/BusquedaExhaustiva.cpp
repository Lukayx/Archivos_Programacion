#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

void buscaPatron(vector<char> T, vector<char> P, vector<int> &indices);

int main(int argc, char **argv){
    if(argc != 2){
		cout << "Error. Debe ejecutarse como ./BusquedaExhaustiva nombreArchivo" << endl;
		exit(EXIT_FAILURE);
	}
    ifstream archivo(argv[1]);
    if(archivo.is_open()){
        string line,patron;
        vector<char> T(0);
        unsigned t0, t1;
        while(getline(archivo,line)){
            for(char c : line) T.push_back(c);
        }
        archivo.close();
        cout << "EL LARGO DEL TEXTO ES: " << T.size() << endl;
        cout << "Ingrese su patron: ";
        getline(cin,patron);
        vector<char> P(0);
        for(char c : patron) P.push_back(c);
        vector<int> indices(0);
        t0 = clock();
        buscaPatron(T,P,indices);
        t1 = clock();
        cout << "Se encontraron coincidencias en: " << indices.size()<< endl;
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "El tiempo que demoró fue: " << time << endl;
        return EXIT_SUCCESS;
    } else {
        cout << "No se puede abrir el archivo" << endl;
        return EXIT_FAILURE;
    }
}

void buscaPatron(vector<char> T, vector<char> P, vector<int> &indices){
    int j,N_T = T.size(), N_P = P.size();
    for (unsigned int i = 0; i <= N_T-N_P; i++){ // O(N)
        j = 0; // O(N)
        while(j < N_P && P[j]==T[i+j]){ //O(N^2)
            j++; // O(N^2)
        }
        if(j==N_P){ //O(N)
            indices.push_back(i);
        }
    }
}
