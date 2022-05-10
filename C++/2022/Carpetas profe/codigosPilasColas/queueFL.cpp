#include <iostream>
#include <cstdlib>
using namespace std;

// este bloque define nuestra clase Queue
class Queue {
private:
	struct nodeQueue {
		int val;
		nodeQueue* next;
	};
	typedef struct nodeQueue nodoQ;

	int nItems;	// contador de elementos
	nodoQ *F;	// puntero al FRENTE de la cola, por donde hacemos la eliminación (dequeue)
	nodoQ *L;	// puntero al FINAL de la cola, por donde entran los elementos (enqueue)

public:
    Queue();
    Queue(int num);
    ~Queue();

    void enqueue(int);
    void dequeue();
    int front();
    int last();
    int size();
    bool empty();
    void display();
};

// constructor de la clase.. crea la cola vacia
Queue::Queue(){
	cout << "creando Cola vacia..." << endl;
	F = L = NULL;
	nItems = 0;
}

// constructor de la clase.. crea la cola con un elemento
Queue::Queue(int num){
	F = L = new nodoQ;
	F->val = num;
	F->next = NULL;
	nItems = 1;
}

// destructor de la clase, libera la memoria de todos los nodoQ
Queue::~Queue() {
	nodoQ *p;

	while(F != nullptr){
 		p = F;
 		F = F->next;
		delete p;
	}
}

// inserta un elemento al final(back) de la cola en tiempo O(n): la recorre desde el front al rear y lo pone al final --> O(1)
void Queue::enqueue(int elem) {
			
}
// Elimina el elemento que esta al frente de la cola y retorna su valo, en tiempo O(1)

void Queue::dequeue(){
		
}

// retorna el elemento que esta al frente de la cola, toma O(1)
int Queue::front(){
	
	return 0;
}

// retorna el elemento que esta al frente de la cola, toma O(1)
int Queue::last(){
	
	return 0;
}

// retorna la cantidad de elementos que hay en la cola, en O(1) time
int Queue::size(){
	return nItems;
}

// lista la cola
void Queue::display(){
	if (F==nullptr){
		cout<<"Cola vacia!" << endl;
		return;
	}

	cout << " Cola:" << endl;
	nodoQ *p = F;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char **argv){
	Queue q1;

	q1.display();
	q1.enqueue(1);
	q1.display();
	q1.enqueue(2);
	q1.display();
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.display();
	cout << "Tamaño de la cola = " << q1.size() << endl;
	cout << "front = " << q1.front() << endl;
	cout << "last = " << q1.last() << endl;

	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.enqueue(77);
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	cout << "Tamaño de la cola = " << q1.size() << endl;
	cout << "front = " << q1.front() << endl;
	cout << "last = " << q1.last() << endl;
	
	
	cout << endl << "Hacemos 2 dequeues más... " << endl;
	q1.dequeue();
	q1.dequeue();
	q1.display();
	cout << "Tamaño de la cola = " << q1.size() << endl;
	cout << "front = " << q1.front() << endl;
	cout << "last = " << q1.last() << endl;
	
	cout << "###### Fin programa ######" << endl;

	return EXIT_SUCCESS;
}
