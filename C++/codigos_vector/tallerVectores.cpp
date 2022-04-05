#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void limpiaVector(vector<int> &v);
vector<int> llenaVector(int n, int min, int max);
void imprimeVector(const vector<int> &v);

int moda(vector<int> &v);
vector<int> fibonacci(int n);
int sumaVector(const vector<int> &v);
float avgVector(const vector<int> &v);


int main(int argc, char **argv){
	int n, minV, maxV; 

	cout << "Ingrese largo del vector, n:";
	cin >> n;
	cout << "Ingrese valor del menor numero permitodo en v, min:";
	cin >> minV;
	cout << "Ingrese valor del mayor numero permitodo en v, min:";	
	cin >> maxV;
	
	cout << "Creamos y llenamos un vector de largo "<<n<<" y luego lo imprimimos" << endl;
	vector<int> v = llenaVector(n, minV, maxV);
	imprimeVector(v);

	cout << "La moda de v es " << moda(v) << endl;

	vector<int> fib = fibonacci(n);
	cout << "Fibonacci(n): " << fib << endl;
	/*imprimeVector(fib);*/

	cout << "Programa terminado exitosamente !!" << endl;
	return EXIT_SUCCESS;
}

// setea las celdas de v en 0
void limpiaVector(vector<int> &v){
	for(unsigned int i=0; i<v.size(); i++)
		v[i]=0;
}

// Llena v con valores aleatorios entre 0 y MAX-1
// Ejemplo int x = rand()%10; // genera un entero aleatorio entre 0 y 9 (IntroArrays.cpp)
vector<int> llenaVector(int n, int min, int max){
	vector<int> v(n);
	for(unsigned int i=0; i<n; i++){
		v[i]=min + rand()%(max-min);
	}
	return v;
}

// lista el vector
void imprimeVector(const vector<int> &v){
	for(unsigned int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int moda(vector<int> &v){
	int x[];
	for(unsigned int i=0; i<v.size(); i++)
		v[i]
	return 0;
}

// 0,1,1,2,3,5,8,13,21,43...
// TAREA--> convertir a recursivo
vector<int> fibonacci(int n){
	vector<int> v(n);
	v[0]=45;
	cout << v[0] << endl;
	
	
	return v;
}

// calculala suma de los elementos de v y la retorna
int sumaVector(const vector<int> &v){
	return 0;
}

//calcula el promedio de v y lo retorna
float avgVector(const vector<int> &v){
	return 0;
}

