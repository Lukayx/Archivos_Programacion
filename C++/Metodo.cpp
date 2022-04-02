#include <iostream>

using namespace std;


int main(){
    int num[5];
    int aux;
    cout << "Ingrese un numero a" << endl;
    cin >> num[0];
    cout << "Ingrese un numero b" << endl;
    cin >> num[1];
    cout << "Ingrese un numero c" << endl;
    cin >> num[2];
    cout << "Ingrese un numero c" << endl;
    cin >> num[3];
    cout << "Ingrese un numero c" << endl;
    cin >> num[4];

    for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++){
                cout << j << endl;
                if(num[j] > num[j+1]){
                    aux = num[j];
                    num[j] = num[j+1];
                    num[j+1] = aux;
                }
            }
    cout << "El orden de menor a mayor es: " << num[0] << " "<<num[1] << " " <<num[2] << num[3] << num[4] << endl;
    return 0;
}