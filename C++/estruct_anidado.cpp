#include <iostream>
#include <cstdlib>
using namespace std;

struct A {
    int i;
    int j;
    int k;
};

struct B {
    int x;
    struct C {
        char c;
        char d;
    } y;
    int z;
    A W;
};
A a = {10,0,0};
B b = {99, {'F','G'}, 77 , {1,2,3}};




int main(){
    //cout << "a = " << a.i << " " << a.j << " " << a.k << endl;
    //cout << "b = " << b.x << " " << b.y.c << " " << b.y.d << " " << b.z << " " << b.w.i << " " << b.w.j << " " << b.w.k endl;
    for(a.i;a.i<20;a.i++){
        if(a.i%2==0){
            a.j += 1;
        }
        cout << a.i << endl;
    }
    cout << "Pares: " << a.j << endl;
    return 0;
}