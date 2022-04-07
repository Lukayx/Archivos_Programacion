#include <iostream>

using namespace std;


int *creaArregloAleatorio(int n);
int posicionFinal(int *A, int n, int x);
void particionar(int *A, int n, int p, int k, int x);
void particionar2(int *A, int n, int p, int k, int x);
void muestraArreglo(int *A, int n);


int main(){
    int n, p, x, k;

    cout << "Ingrese entero n: ";
    cin >> n; 

    do{
        cout << "Ingrese entero p < n: ";
        cin >> p;
    } while(p >= n);

    int *A = creaArregloAleatorio(n); // [26, 33, 35, 37, 83]

    x = A[p];
    k = posicionFinal(A, n, x);

    cout << "\nArreglo: "; muestraArreglo(A, n);
    cout << "El numero " << x << " se encontraria en la posicion " << k << "." << endl << endl;

    particionar2(A, n, p, k, x);
    cout << "El arreglo particionado es: \n"; muestraArreglo(A, n); cout << endl;



    return EXIT_SUCCESS;
}



int *creaArregloAleatorio(int n){
    int *arr = new int [n];
    for(int i = 0; i < n; i++)
        arr[i] = 10 + rand()%90;
    return arr;
}



int posicionFinal(int *A, int n, int x){
    int k = -1;
    for(int i = 0; i < n; i++)
        if(A[i] <= x)
            k++;
    return k;
}



void particionar(int *A, int n, int p, int k, int x){ 
    int izq = 0, der = k+1;

    swap(A[k], A[p]); // dejamos a x en su posicion correcta
    while(izq < k && der < n){
        while((A[izq] <= x && izq++ < k) || (A[der] > x && der++ < n)); // busca hasta encontrar numeros mal posicionados o salir de los limites
        if(izq != k && der != n) 
            swap(A[izq], A[der]);
    }
}

void particionar2(int *A, int n, int p, int k, int x){
	int pos = 0;
	swap(A[p], A[0]);

	for(int i = 1; i < n; i++)
		if (A[i] <= x)
			swap(A[i], A[++pos]);

	swap(A[0], A[pos]);
}



void muestraArreglo(int *A, int n){
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}