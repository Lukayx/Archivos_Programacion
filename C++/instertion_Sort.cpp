#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;	// uso del espacio de nombre std

void insertionSort(int &A,int n){
    int j,key;
    for(int i = 2; i < n;i++){
        key = A[i];
        j = i - 1;
        while(j > 0 && A[j] > key){
            A[j+1] = a[j];
            j--;
            A[j+1]=key;
        }
    }
}
int main(){
    int *lista[];
    int n;
    cout << "Ingrese el tamaño de la lista: ";
    cin >> n;
    lista = new int[n];
    for(int i = 0; i<n;i++){
        lista[i] = rand()%100;
    }
    insertionSort(lista,n);
    forfor(int j = 0;j<n ;j++){
        cout << " " << lista[j];
    }
    return 0;
}