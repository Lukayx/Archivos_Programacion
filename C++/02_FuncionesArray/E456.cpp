#include <iostream>

using namespace std;

int **crearMatriz(int rows, int cols, bool fill);
void listar_espiral(int **M, int rows, int cols);
void traspuesta(int **A, int m, int n, int **T);
bool esTraspuestaTdeA(int **A, int m_a, int n_a, int **T, int m_t, int n_t);
void mostrar_matriz(int **M, int rows, int cols);

int main(){
    int n = 7, m = 4;
    int **A = crearMatriz(n, m, true);
    int **T = crearMatriz(m, n, false);
    int **TT = crearMatriz(n, m, false);
    // Muestra la matriz generada
    mostrar_matriz(A, n, m);
    // Imprime la matriz en espiral (E4)
    listar_espiral(A, n, m);
    // Matriz traspuesta (E5)
    traspuesta(A, m, n, T);
    mostrar_matriz(T, m, n);
    // Traspuesta de la traspuesta (E6)
    traspuesta(A, m, n, T);
    traspuesta(T, n, m, TT);
    if(esTraspuestaTdeA(A, m, n, TT, m, n))
        cout << "La traspuesta de la traspuesta de A sigue siendo A." << endl;
    else 
        cout << "La traspuesta de la traspuesta es diferente de A. Ha ocurrido un error" << endl;
    return EXIT_SUCCESS;
}

int **crearMatriz(int rows, int cols, bool fill){
    /* fill -> Parametro que indica si la matriz será llenada 
                Si es false, solo se asignará el espacio en memoria que utilizará
    */
    int **M = new int *[rows];
    for(int i = 0; i < rows; i++){
        M[i] = new int [cols];
        if(fill)
            for(int j = 0; j < cols; j++)
                M[i][j] = rand()%100;
    }
    return M;
}

void listar_espiral(int **M, int rows, int cols){
    int v = 0; // ciclos (vueltas) completados
    while(min(rows, cols) > 2*v){ // regla general
        for(int j = v; j < cols-v; j++){ // Adelante
            cout << M[v][j] << " ";
        }
        for(int i = v+1; i < rows-v; i++){ // Abajo
            cout << M[i][cols-v-1] << " ";
        }
        /* para los dos bucles finales, la segunda condicion verifica que 
           no se prosiga la impresion de numeros en matrices rectangulares */
        for(int j = cols-v-2; j >= v && rows-2*v != 1; j--){ // Atras
            cout << M[rows-v-1][j] << " ";
        }
        for(int i = rows-v-2; i >= v+1 && cols-2*v != 1; i--){ // Arriba
            cout << M[i][v] << " ";
        }
        v++;
    }
    cout << endl;
}

void traspuesta(int **A, int m, int n, int **T){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            T[j][i] = A[i][j];
}

bool esTraspuestaTdeA(int **A, int m_a, int n_a, int **T, int m_t, int n_t){
    if(m_a != m_t || n_a != n_t) // verificacion rapida de dimension matching
        return false;
    // recorrido elemento a elemento verificando igualdad
    for(int i = 0; i < n_a; i++)
        for(int j = 0; j < m_a; j++)
            if(A[i][j] != T[i][j])
                return false;
    return true;
}

void mostrar_matriz(int **M, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}