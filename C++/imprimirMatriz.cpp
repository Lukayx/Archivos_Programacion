#include <iostream>
#include <cstdlib>
using namespace std;

void listarDigitos(int x);

int main(){
    int n,m;
    cout << "Ingrese la cantidad de filas: ";
    cin >> n;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> m;
    int matriz[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matriz[i][j] = 10 - rand()%(20+1) ;    
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matriz[i][j] << " ";    
        }
        cout << endl;
    }
    return 0;
}