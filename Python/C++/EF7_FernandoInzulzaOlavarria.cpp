#include <iostream> //
using namespace std;

int main() {
    int num;
    do{
        cout << "Ingrese un entero positivo" << endl; 
        cin >> num;
    } while(num<0);
    if(num%2==0){
        for(int i=num;i>=0;i-=2){
            cout << i << " " ;
        }
    } else {
        int x = num*2;
        while(num<x){
            cout << num << " ";
            num+=2;
        }
    }
    return 0;
}