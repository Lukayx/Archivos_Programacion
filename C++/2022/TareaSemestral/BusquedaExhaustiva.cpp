#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void buscaPatron(vector<char> T, vector<char> P, vector<int> &indices);

int main(){
    ifstream archivo("test.txt");
    if(archivo.is_open()){
        string line,patron;
        vector<char> T(0);
        while(getline(archivo,line)){
            for(char c : line) T.push_back(c);
        }
        archivo.close();
        cout << "Ingrese su patron: ";
        getline(cin,patron);
        vector<char> P(0);
        for(char c : patron) P.push_back(c);
        vector<int> indices(0);
        buscaPatron(T,P,indices);
        cout << "Se encontraron coincidencias en: " << endl;
        for(int i : indices){
            cout << "Indice: " << i << endl;
        }
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
