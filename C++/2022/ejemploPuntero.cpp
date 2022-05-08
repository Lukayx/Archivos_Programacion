#include<iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
    int var;
    int *p;
    *p = 20;
    cout << "Direccion de var: " << &var << " y var " << var << endl;
    if(p != nullptr){
        cout << "p apunta a " << p << " y guarda *p= " << *p << endl;
        p = NULL;
        if(p == nullptr){
            cout << "p apunta a nada !!" << endl;
        }
        return 0;
    }
}