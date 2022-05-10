#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// este bloque define nuestra clase Stack
class Stack {
private:
	struct nodeStack {
		int val;
		nodeStack* next;
	};
	typedef struct nodeStack nodoS;
	
	int nItems;	// contador de elementos
	nodoS *S;	// puntero al tope de la pila
public:
	Stack();	// Constructor por defecto
	Stack(int num);	// Constructor sobrecargado que crea la pila con un dato
	~Stack();

	void push(int);
	void pop();
	int top();
	int size();
	bool empty();
	void display();
};

// constructor de la clase.. crea la pila vacia
Stack::Stack(){
	cout << "creando stack vacio..." << endl;
	S = NULL;
	nItems = 0;
}

// constructor de la clase.. crea la pila con un elemento
Stack::Stack(int num){
	cout << "creando stack con un nodo..." << endl;
	S = new nodoS;
	S->val = num;
	S->next = NULL;
	nItems = 1;
}

// destructor de la clase, libera la memoria de todos los nodos
Stack::~Stack() {
	nodoS *p;
	cout << "Destruyendo stack..." << endl;
	while(S != nullptr){
		p = S;
		//cout << "eliminando nodo con valor " << p->val << endl;
		S = S->next;
		delete p;
	}
}

// inserta un elemento al frente de la pila
void Stack::push(int elem) {
	nodoS *nuevo_Nodo = new nodoS;
	nuevo_Nodo->val = elem;
	nuevo_Nodo->next = S;
	S=nuevo_Nodo;
	nItems++;
}

// Elimina el elemento que esta al frente de la pila y retorna su valor
void Stack::pop(){
	if(S == nullptr){
		cout << "La pila esta vacia, no es posible eliminar !!" << endl;
		return;
	}
	nodoS *P = S;
	S = S->next;
	delete P;
	nItems--;
}

// retorna el valor que esta al tope de la pila
int Stack::top(){
	if(S == nullptr) return -1;
	return S->val;
}

// retorna la cantidad de elementos que hay en la pila, en O(1) time
int Stack::size(){
	return nItems;
}

bool Stack::empty(){
	return true;
}

// lista la pila como si fuera un lista enlazada simple
void Stack::display(){
	if (S==nullptr){
		cout<<"Stack vacio!"<<endl;
		return;
	}

	cout << " Pila: " << endl;
	nodoS *p = S;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char **argv){
	srand(time(NULL));
	Stack s1;	// se invoca el constructor por defecto (sin parámetros)
	int val; 
	for (int i = 0; i < 10; i++){
		val = rand()%100000;
		s1.push(val);
	}
	s1.display();
	Stack pares;
	Stack impares;
	while(s1.top()!=-1){
		val = s1.top();
		if(val%2==0){
			pares.push(val);
		} else {
			impares.push(val);
		}
		s1.pop();
	}
	pares.display();
	impares.display();
	/*
	s1.display();
	cout << "Tamaño de la pila = " << s1.size() << endl;
	
	cout << "Tope de la pila = " << s1.top() << endl;

	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.pop();
	cout << "Tamaño de la pila = " << s1.size() << endl;
	s1.push(6);
	s1.display();
	cout << "Tope de la pila = " << s1.top() << endl;

	cout << "Tamaño de la pila = " << s1.size() << endl;
	cout << "###### Fin programa ######" << endl;
	*/
	return EXIT_SUCCESS;
}
