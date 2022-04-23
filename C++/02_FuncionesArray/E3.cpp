#include <iostream>

using namespace std;

int **creaMatriz(int rows, int cols, bool fill);
void multiplicar(int **A, int **B, int **C, int n, int c, int m);
void muestraMatriz(int **M, int rows, int cols);

int main(int argc, char **argv){
    if(argc != 4){
        cout << "Debe ejecutarse como ./E3 n c m" << endl;
        return EXIT_FAILURE;
    }
    int n, c, m;
    n = atoi(argv[1]);
    c = atoi(argv[2]);
    m = atoi(argv[3]);
    int **A = creaMatriz(n, c, true);
    int **B = creaMatriz(c, m, true);
    int **C = creaMatriz(n, m, false);
    multiplicar(A, B, C, n, c, m);
    muestraMatriz(A, n, c);
    muestraMatriz(B, c, m);
    muestraMatriz(C, n, m);
    return EXIT_SUCCESS;
}

int **creaMatriz(int rows, int cols, bool fill){
    /* fill -> Parametro que indica si la matriz será llenada 
                Si es false, solo se asignará el espacio en memoria que utilizará
    */
    int **M = new int *[rows];
    for(int i = 0; i < rows; i++){
        M[i] = new int[cols];
        if(fill)
            for(int j = 0; j < cols; j++)
                M[i][j] = -99 + rand()%(199);
    }
    return M;
}

void multiplicar(int **A, int **B, int **C, int n, int c, int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            C[i][j] = 0;
            for(int k = 0; k < c; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void muestraMatriz(int **M, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}