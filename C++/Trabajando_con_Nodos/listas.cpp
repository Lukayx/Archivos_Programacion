#include <iostream>
#include <cstdlib>

using namespace std;

struct nodeList {
    int val;
    nodeList *next;
};

typedef struct nodeList nodo;

void appendToListL(nodo **l, int num); // note que hay doble *
void printList(nodo *l); // aca solo hay un *
void appendToListR(nodo **l, int num);

int main(int argc, char **argv){
    nodo *miLista = NULL;

    for(int i = 50; i >= 10; i-=10){
        appendToListR(&miLista,i);
        printList(miLista);
    }
    return EXIT_SUCCESS;
}

void appendToListL(nodo **l, int num){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->val = num;
    nuevo_nodo->next = *l;   
    *l=nuevo_nodo;
}

void appendToListR(nodo **l, int num){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->val = num;
    nodo *puntero = *l;
    if(*l == NULL){
        *l = nuevo_nodo;
    }else{
        while(puntero->next != NULL){
            puntero = puntero->next;
        }
        puntero->next = nuevo_nodo;
    }
    nuevo_nodo->next = NULL;
}

void printList(nodo *list){
    nodo *puntero = list;
    int num;
    while(puntero != NULL){
        num = puntero->val;
        cout << num << " ";
        puntero = puntero->next;
    }
    cout <<endl;
}
