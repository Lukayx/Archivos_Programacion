#include <iostream>

using namespace std;


void barajar(int *A, int n);
void imprimeCiclos(int *A, int n);
void imprimeArreglo(int *A, int n);


int main(int argc, char **argv){
    if(argc != 2){
        cout << "Debe ejecutarse como ./E7 n" << endl;
        return EXIT_FAILURE;
    }

    int n;

    n = atoi(argv[1]);

    int *A = new int [n];

    // Generacion del arreglo (no se especifica metodo alguno, luego usamos el mas sencillo)
    for(int i = 0; i < n; i++)
        A[i] = i;

    // Creamos una permutacion aleatoria barajando el arreglo (E7) (metodo de complejidad O(n))
    barajar(A, n);
    imprimeArreglo(A, n);
    cout << endl;

    // E8
    imprimeCiclos(A, n);


    return EXIT_SUCCESS;
}



void barajar(int *A, int n){
    for(int i = 0; i < n; i++)
        swap(A[i], A[rand()%n]); // Intercambiamos elementos aleatoriamente
}



void imprimeCiclos(int *A, int n){
    /*
        - Si algun elemento forma un ciclo por si solo, se imprimirá dos veces (contrario al ejemplo de la guia)
        Esto para seguir la regla de imprimir el primer numero del ciclo dos veces.
    */
    int k;

    // Arreglo que indica si un elemento de A ya fue recorrido
    bool *B = new bool [n];
    for(int i = 0; i < n; i++)
        B[i] = false;

    for(int i = 0; i < n; i++){
        if(B[i]) // Saltamos si el numero ya esta en algun ciclo (tema de eficiencia)
            continue;
        k = A[i];
        cout << i << " ";
        while(k != i){ // continua hasta que el ciclo se reinicie
            cout << k << " ";
            B[k] = true;
            k = A[k];
        }
        cout << k << endl;
        B[i] = true; // trivial 
    }
}



void imprimeArreglo(int *A, int n){
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}