#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;	// uso del espacio de nombre std

void mixSort(int *A, int *B, int na,int nb, int *X);
void rellena_y_ordena(int* A,int n);

int main(){
    srand(time(NULL));
    int *A,*B,na,nb;
    cout << "Ingrese el largo de la A: ";
    cin >> na;
    cout << "Ingrese el largo de la B: ";
    cin >> nb;
    A = new int[na];
    B = new int[nb];
    int *X = new int[na+nb];
    rellena_y_ordena(A,na);
    for(int j = 0;j<na ;j++){
        cout << " " << A[j];
    }
    cout << endl;
    rellena_y_ordena(B,nb);
    for(int j = 0;j<nb ;j++){
        cout << " " << B[j];
    }
    cout << endl;
    mixSort(A,B,na,nb,X);
    //insertionSortDesc(A,n);
    for(int j = 0;j<na+nb ;j++){
        cout << " " << X[j];
    }
    return 0;
}

void rellena_y_ordena(int *L, int n){
    for(int i = 0; i<n;i++){
        L[i] = rand()%101;
    }
    int j,key;
    for(int i = 1; i < n;i++){
        key = L[i];
        j = i - 1;
        while(j >= 0 && L[j] > key){
            L[j+1] = L[j];
            j = j - 1;
        }
        L[j+1]=key;
    }
}

void mixSort(int *A, int *B, int na,int nb, int *X){
    int i=0,j=0,k=0,u,v;
    for (int h = 0; h < na+nb; h++){
        u = A[i];
        v = B[j];
        if(u<v){
            X[k]=u;
            if(i != na-1) i++;
        }else{
            X[k]=v;
            if(j != nb-1) j++;
        } 
        k++;
    }
}