#include <iostream>
#include <cstdlib>
using namespace std;

void mostrarLista(int **A, int a, int b);
void multiplicar(int **A,int **B, int **C, int n, int c, int m);
int **crearMatriz(int **M, int filas, int columnas);
int n,c,m;

int main(){
    cout << "Ingrese un valor entero n: ";
    cin >> n;
    cout << "Ingrese un valor entero c: ";
    cin >> c;
    cout << "Ingrese un valor entero m: ";
    cin >> m;
    cout <<endl;
    
    //MATRIZ A
    int **A = crearMatriz(A,n,c);
    cout << "MATRIZ A (" << n << "x" << c << "): " <<endl;
    mostrarLista(A,n,c);
    //MATRIZ B
    int **B = crearMatriz(B,c,m);
    cout << "MATRIZ B (" << c << "x" << m << "): " <<endl;
    mostrarLista(B,c,m);
    //MATRIZ C
    int **C = crearMatriz(C,n,m);
    multiplicar(A,B,C,n,c,m);
    cout << "MATRIZ C (" << n << "x" << m << "): " <<endl;
    mostrarLista(C,n,m);
    return 0;
}

int **crearMatriz(int **M,int filas,int columnas){
    M = new int*[filas];
    for(int i=0;i<filas;i++){
        M[i] = new int[columnas];
        for(int j=0; j<columnas;j++){
            M[i][j] = 100 - rand()%200;
        }
    }
    return M;
}
void mostrarLista(int **M, int a, int b){
    for(int i=0;i<a;i++){
        for(int j=0; j<b;j++){
            cout  << " " << M[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void multiplicar(int **A,int **B, int **C, int n, int c, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<c;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
