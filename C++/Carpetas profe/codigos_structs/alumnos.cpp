/*
Nota. Algunas funciones en string que son muy útiles:
	strcpy(a, b);
se copia el contenido del string 'b' a la variable string 'a'
También se puede usar como:
	strcpy(a, "Nuevo valor");

Además con:
	strcat(a, b);, o con: strcat(a, "se aniade al final");
el contenido del segundo argumento se aniade al final de la variable string 'a'
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;	// uso del espacio de nombre std

#define N_CAR 3
#define N_NOM 5
#define N_APEL 10
#define MIN_EDAD 17
#define MAX_EDAD 49

const char ellos[N_NOM][10] = {"Pedro", "Juan", "Manuel", "Diego", "Agustin"};
const char ellas[N_NOM][10] = {"Maria", "Claudia", "Josefina", "Paola", "Linda"};
const char apel[N_APEL][10] = {"Torres", "Flores", "Campos", "Acosta", "Aguirre", "Molina", "Silva", "Rojas", "Rios", "Castillo"};

struct {
    char id;
    char nombre[20];
} const Carrera[N_CAR] = {{'B', "Bachillerato"},{'I', "Ingenieria"},{'M', "Magister"}};

struct Alum{
	int id;		// cree un entero alearotio positivo
	char nombres[21];	// 2 nombres (separados por un espacio en blanco), 
	char apellidos[21];	// 2 apellidos provenientes de apel (separados por un espacio en blanco)
	bool masc;		// true: masculino, false: femenino
	char idCarrera; 	// 'B', 'I' o 'M'
	int edad;		// IN [MIN_EDAD..MAX_EDAD]
};

void genAlumnos(Alum *Alumno, int n);
void avgGeneros(Alum *Alumno, int n, float *men, float * women);
void countFamily(Alum *Alumno, int n, char lastname[10]);
void misAlumnos(Alum *Alumno, int n, Alum *Al_Carr, int &len);

// A esta definición del main(), se le pueden pasar argumentos
int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutarse como ./alum n" << endl;
		exit(EXIT_FAILURE);
	}

	int i, n=atoi(argv[1]);
	Alum *Alumno = new Alum[n];	// ESTO ES MEMORIA DINAMICA --> no sabe el compilador cuantos bytes son

	genAlumnos(Alumno, n);

	cout << n << " Listado de Alumnos:" << endl;
	for (i=0; i<n; i++){
		cout << "Id        : " << Alumno[i].id << endl;

		if (Alumno[i].masc)
			cout << "Sexo      : Masculino " << endl;
		else
			cout << "Sexo      : Femenino " << endl;

		cout << "Nombres   : " << Alumno[i].nombres << endl;
		cout << "Apellidos : " << Alumno[i].apellidos << endl;
		cout << "Carreara  : ";
		switch (Alumno[i].idCarrera) {
			case 'B':
				cout << Carrera[0].nombre << endl;
				break;
			case 'I':
				cout << Carrera[1].nombre << endl;
				break;
			case 'M':
				cout << Carrera[2].nombre << endl;
				break;
			default:
				cout << " NO DEFINIDA !! " << endl;
				break;
		}
		cout << "Edad      : " << Alumno[i].edad << endl;

		cout << endl;
	}

	return EXIT_SUCCESS;
}

// generar n alumnos con dos nombres y 2 apellidos aleatorios desde los arreglos globales
void genAlumnos(Alum *Alumno, int n){

}

void avgGeneros(Alum *Alumno, int n, float *men, float * women){

}

void countFamily(Alum *Alumno, int n, char lastname[10]){

}

void misAlumnos(Alum *Alumno, int n, Alum *Al_Carr, int &len){

}