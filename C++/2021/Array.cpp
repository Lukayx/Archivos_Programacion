#include <iostream>
#include <climits>
using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

void intercambia(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

int main(int argc, char *argv[]){
    cout << "El fibonacci de 5 es: " << fibonacci(5) << endl;
    cout << "------------------------" << endl;
    int a=5;
    int b=11;
    cout << a << ' ' << b << endl;
    intercambia(a,b);
    cout << a << ' ' << b << endl;
    return 0;
}