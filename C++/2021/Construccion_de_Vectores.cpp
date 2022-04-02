#include <iostream>
#include <vector>
using namespace std;
// T debe soportar "<<"
template <typename T>

void imprime(vector<T> v, string nombre) {
    cout << nombre << ": \t";
    for (long unsigned int i=0; i<v.size() ; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    vector<float> v1(7); // tamaño 7
    imprime(v1, "v1");

    vector<int> v2(4,-1); //4 veces -1
    imprime(v2, "v2");

    vector<int> v3 = {2,4,6, 8, 10};// elementos explicitos
    imprime(v3, "v3");

    int arr [] = {1,3,5,7,9}; // array desde el cual...
    vector<int> v4 (arr, arr+3); // ...toma 1os 3 primeros
    imprime(v4, "v4");
    
    return 0;
}