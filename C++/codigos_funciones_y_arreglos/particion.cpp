#include <iostream>
#include <cstdlib>
using namespace std;

int posicionFinal(int p, int *A, int n);

int main(){
    int n,p,x,aux;
    int *A;
    cout << "ingrese un numero entero n: ";
    cin >> n;
    while(n<10 or n>99){
        cout << "Error, debe ser entre 10 y 99 (se incluyen ambos) : ";
        cin >> n;
    }
    A = new int[n];
    for(int i=0;i<n;i++){
        A[i] = 10 + rand()%90;
    }
    cout << "ingrese un numero entero p: ";
    cin >> p;
    while(p>=n){
        cout << "Error, debe ser menor que n (p<n): ";
        cin >> p;
    }
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    x = A[p];
    int k = posicionFinal(x,A,n);
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n-i; j++){
            if(A[j]>A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    cout << x << " " << k << " " << A[k];
    return 0;
}

int posicionFinal(int p, int *A, int n){
    int k=0;
    for(int i=0;i<n;i++){
        if(A[i]<p){
            k+=1;
        }
    }
    return k;
}