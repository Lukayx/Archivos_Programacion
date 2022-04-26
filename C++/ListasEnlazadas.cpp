#include <iostream>
#include <string>
using namespace std;

struct Nodo{
    int dato;
    Nodo *p;
};

void insertarListaPrincipio(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while(aux1!=NULL && aux1->dato < n){
        aux2 = aux1;
        aux1 = aux1->p;
    }
    if(lista == aux1){
        lista = nuevo_nodo;
    } else {
        aux2->p = nuevo_nodo;
    }
    nuevo_nodo->p = aux1;

    cout << "\tElemento insertado a la lista correctamente" << endl;
} 

int main(int argc, char** argv){
    Nodo *lista = NULL;

    int dato;
    cout << "Ingrese un dato: ";
    cin >> dato;
    insertarListaPrincipio(lista,dato);

    cout << "Ingrese un dato: ";
    cin >> dato;
    insertarListaPrincipio(lista,dato);

    cout << "Ingrese un dato: ";
    cin >> dato;
    insertarListaPrincipio(lista,dato);
    return 0;
}