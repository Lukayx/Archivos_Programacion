#include <iostream>
using namespace std;

int aux,n;

int main(){
    cout << "Cuantos elementos desea ingresar: ";
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cout << "Numero " << i << ": ";
        cin >> a[i]; 
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n-i; j++){
            if(a[j]<a[j+1]){
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }  // 3-4-5
    }
    for(int i = 0; i<n; i++){
        cout << i+1 << "- "<< a[i] << endl;
    }
    return 0;
}