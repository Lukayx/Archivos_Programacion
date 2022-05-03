#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void insertionSort(int *A, int n){
    int key,j;
    for(int i = 1; i<n; i++){
        key = A[i];
        j = i - 1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = key;
    }
}

int particion(int *A, int l, int r){
    int pv = A[l],p=l,aux;
    for(int i = l+1; i <= r; i++){
        if(A[i] <= pv){
            p++;
            aux=A[p];
            A[p] = A[i];
            A[i] = aux;
        }
    }
    aux=A[p];
    A[p] = A[l];
    A[l] = aux;
    return p;
}

void quickSort(int *A, int l, int r){
    if(l<r){
        int m = particion(A,l,r);
        quickSort(A,l,m-1);
        quickSort(A,m+1,r);
    }
}

void listaArray(int *A,int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    int n;
    cout << "Ingrese el largo de la lista: ";
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++){
        A[i] = rand()%101;
    }
    listaArray(A,n);
    quickSort(A,0,n-1); //EN ARRAYS DEBES COLOCAR EL N - 1 PARA QUE NO SE PASE DEL INDICE
    listaArray(A,n);
}