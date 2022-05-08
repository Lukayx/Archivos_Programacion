#include <iostream>
#include <string>
using namespace std;

struct Nodo{
    int dato;
    Nodo *p;
};

void insertarListaPrincipio(Nodo *&lista, int n);
void recorreListaNodos(Nodo *&lista);
void insertaLista(Nodo *&lista, int n);
Nodo creaLista(Nodo *&lista, int n);

int main(int argc, char** argv){
    Nodo *lista = NULL;

    int dato,n;
    do
    {
        cout << "¿Cuantos datos quiere almacenar en su lista?";
        cin >>  n;
    } while (n>0 && n<20);  

    cout << "Ingrese un dato: ";
    cin >> dato;
    insertaLista(lista,dato);

    recorreListaNodos(lista);
    return 0;
}

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

void insertaLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo *puntero = lista;
    if(puntero==NULL) {
        nuevo_nodo->p=NULL;
        lista = nuevo_nodo;
    }else{
        while(puntero->p!=NULL) puntero = puntero->p;
        nuevo_nodo->p=NULL;
        puntero->p=nuevo_nodo;
    }
    cout << "\tElemento insertado a la lista correctamente" << endl;
}

void recorreListaNodos(Nodo *&lista){
    Nodo *aux1 = lista;
    int i = 0;
    while(aux1!=NULL){
        cout << "Elemento " << ++i << ": " << aux1->dato << endl;
        aux1 = aux1->p;
    }
}

Nodo creaLista(Nodo *&lista, int n){
    Nodo *X = NULL;
    int dato;
    for (int i = 0; i < n; i++){
        cout << "Ingrese un dato: ";
        cin >> dato;
        insertaLista(X,dato);
    }
    return X;
}  