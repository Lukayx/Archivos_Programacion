#include <iostream>
#include <cstdlib>
using namespace std;

void listarDigitos(int x);

int main(){
    int n,m;
    cout << "Ingrese la cantidad de filas: " << endl;
    cin >> n;
    cout << "Ingrese la cantidad de columnas: " << endl;
    cin >> m;

    listarDigitos(n);
    int matriz[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matriz[i][j] = 100 + rand()%900;    
        }
    }
    return 0;
}