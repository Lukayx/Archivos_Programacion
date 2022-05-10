/*
Pila, en base al arreglo int *S, agrega y elimina items por el fina del  arreglo, 
item es el indice del ultimo elemento ingresado (el de más a la derecha)
 
                               item 
    0  1  2  3  4  5  6  7  8  9
S =[2 ,3 ,4 ,5 ,7, 4, 1, 2, 3, 6, , , , , , , , , , ]

*/


#include <iostream>
#include <cstdlib>
using namespace std;

// este bloque define nuestra clase StackArr
class StackArr {
private:
    int *S;	// arreglo que almacenara los elementos de la pila
    int item;	// indice del item que esta al frente de la pila
    int cap;	// capacidad maxima de la pila

public:
	StackArr();
    	StackArr(int largo);
    	~StackArr();

	void reSize(int newCap);
    	int top();
	int size();
    	void push(int);
    	void pop();
    
    	bool empty();
    	void display();
};

// constructor de la clase, recive el largo inicial de la pila
StackArr::StackArr(){
	item=-1;
	cap=0;
	S = NULL;
}

// constructor de la clase, recive el largo inicial de la pila
StackArr::StackArr(int largo){
	item=-1;
	cap=largo;
	if(cap <= 0)
		S = NULL;
	else
		S = new int[cap];
}

// destructor de la clase, libera la memoria del arreglo S
StackArr::~StackArr() {
	if(S != nullptr)
		delete [] S;
}

// redimensiona el arreglo S a una nueva capacidad newCap, copia los elementos actuales 
void StackArr::reSize(int newCap){
	if (cap >= newCap){
		cout << "No resize. cap = " << cap << " >= newCap = " << newCap << endl;
		return;
	}

	int *Aux = new int[newCap];
	for(int i=0; i<cap; i++)
		Aux[i] = S[i];

	cap = newCap;
	delete [] S;
	S = Aux;
}

// ===================================================================

// retorna el elemento que está al tope de la pila o -1 si la pila está vacía
int StackArr::top(){
	
	return 0;
}

//           item 
//     0 1 2 3
// S = 2,3,4,5
int StackArr::size(){
	return item+1;
}


// inserta un elemento al frente de la pila
//                           item
// S = x x x x x x x x x x x  x....................cap
void StackArr::push(int elem) {
	
}

// Retorna el valor del elemento que esta al frente de la pila y lo elimina (simulamos eliminar en el arreglo, no liberamos memoria)
//          item
// S = 1 2 3 4 x x x x x
void StackArr::pop(){
	
}

// lista la pila
void StackArr::display(){
	if (item==-1)
		cout<<"Stack vacio!";
	for(int i=0; i<=item; i++)
		cout<<S[i]<<" ";
	cout<<endl;
}

int main(int argc, char **argv){
	StackArr s1;   //la creamos solo con papacidad de dos elementos

	s1.push(22);
	s1.push(1);
	s1.push(2);
	s1.display();
	s1.push(3);
	s1.reSize(10);	// nuevo tamañov
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.display();
	cout << "Tamaño de la pila = " << s1.size() << endl;
	cout << "Top = " << s1.top() << endl;

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
	s1.display();
	cout << "Tamaño de la pila = " << s1.size() << endl;
	cout << "Top = " << s1.top() << endl;
	s1.push(6);
	s1.display();
	cout << "Tamaño de la pila = " << s1.size() << endl;
	cout << "Top = " << s1.top() << endl;
	cout << "###### Fin programa ######" << endl;

	return EXIT_SUCCESS;
}
