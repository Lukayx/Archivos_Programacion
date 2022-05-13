/*
Generar n enteros aleatorios entre 0 y 100 en una cola y, una vez generados todos,
recorrer la cola, sacarlos uno a uno y almacenarlos en dos pilas: menores (numeros 
menores que 50) y mayores (numeros mayores o iguales a 50). Además, imprimir las 
tres pilas.
*/

/*
Generar n enteros aleatorios entre 0 y 100 en una pila y, una vez generados todos,
sacarlos de a uno de la pila y almacenarlos en dos colas: menores (numeros menores
que 50) y mayores (numeros mayores o iguales a 50). Además, imprimir las tres colas.
*/

#include <iostream>
#include <random>
#include <time.h>
#include "queueFL.cpp"
#include "stack.cpp"

using namespace std;

void generarNumeros(int n, Queue &Q);
void distribuirNumeros(Queue &Q, Stack &menores, Stack &mayores);

void generarNumeros2(int n, Stack &Q);
void distribuirNumeros2(Stack &Q, Queue &menores, Queue &mayores);

int main(int argc, char **argv){
    if(argc != 2){
        cout << "Error. Debe ejecutarse como ./problema n" << endl;
        return EXIT_FAILURE;
    }
    // ### PROGRAMAR AQUI ### 
    cout << "\n###################################################" << endl;
    srand(time(NULL));
    int n = atoi(argv[1]);
    Queue Q;
    generarNumeros(n,Q);
    Stack menores;
    Stack mayores;
    Q.display();
    distribuirNumeros(Q,menores,mayores);
    menores.display();
    mayores.display();
    cout << "###################################################" << endl;
    Stack _Q;
    generarNumeros2(n,_Q);
    Queue _menores;
    Queue _mayores;
    _Q.display();
    distribuirNumeros2(_Q,_menores,_mayores);
    _menores.display();
    _mayores.display();
    cout << "###################################################" << endl;
    // ### FIN DEL PROBLEMA ###
    return EXIT_SUCCESS;
}

void generarNumeros(int n, Queue &Q){
    for (int i = 0; i < n; i++){
        Q.enqueue(rand()%101);
    }
}

void generarNumeros2(int n, Stack &Q){
    for (int i = 0; i < n; i++){
        Q.push(rand()%101);
    }
}

void distribuirNumeros(Queue &Q, Stack &menores, Stack &mayores){
    int x;
    while(Q.size()!=0){
        x = Q.front();
        Q.dequeue();
        if(x<50) menores.push(x);
        else mayores.push(x);
    }
}

void distribuirNumeros2(Stack &Q, Queue &menores, Queue &mayores){
    int x;
    while(Q.size()!=0){
        x = Q.top();
        Q.pop();
        if(x<50) menores.enqueue(x);
        else mayores.enqueue(x);
    }
}