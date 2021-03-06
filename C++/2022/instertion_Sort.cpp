#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;	// uso del espacio de nombre std

void insertionSort(int* A,int n);
void insertionSortDesc(int* A, int n);

int main(){
    srand(time(NULL));
    int n, *lista;
    cout << "Ingrese el largo de la lista: ";
    cin >> n;
    lista = new int[n];
    for(int i = 0; i<n;i++){
        lista[i] = rand()%101;
        cout << lista[i] << " ";
    }
    cout << endl;
    insertionSort(lista,n);
    //insertionSortDesc(lista,n);
    for(int j = 0;j<n ;j++){
        cout << lista[j] << " ";
    }
    return 0;
}

void insertionSort(int* A,int n){
    int j,key;
    for(int i = 1; i < n;i++){
        key = A[i];
        j = i;
        while(j > 0 && A[j-1] > key){
            A[j] = A[j-1];
            j = j - 1;
        }
        A[j]=key;
    }
}

void insertionSortDesc(int* A, int n){
    int j,key;
    for(int i = 1; i < n;i++){
        key = A[i];
        j = i - 1;
        while(j >= 0 && A[j] < key){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1]=key;
    }
}