#include <iostream>

using namespace std;

int **creaMatriz(int n, int m);
void listarDigitos(int **M, int m, int n);

int main(){
    int n, m;
    // SE ASUME QUE EL ENTERO ES VALIDO
    cout << "Ingrese entero n: ";
    cin >> n;
    cout << "Ingrese entero m: ";
    cin >> m;
    cout << endl;

    int **A = creaMatriz(n, m);
    listarDigitos(A, n, m);

    return EXIT_SUCCESS;
}



int **creaMatriz(int n, int m){
    int **M = new int *[n]; // puntero a puntero a entero que apunta hacia un arreglo de punteros a enteros
    for(int i = 0; i < n; i++){
        M[i] = new int [m]; // cada puntero del arreglo apunta hacia un arreglo de enteros, así generamos una matriz
        for(int j = 0; j < m; j++)
            M[i][j] = 100+rand()%900;
    }
    return M;
}


void listarDigitos(int **M, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}