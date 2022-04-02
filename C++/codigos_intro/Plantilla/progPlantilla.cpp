/* INICIO BLOQUE DE COMENTARIOS
Los comentarios (que no se compilan ni ejecutan) se pueden inclir dentro de un bloque con (como aquí) o en una linea que comience con //
FIN BLOQUE DE COMENTARIOS */

// 1. Archivos de cabecera #include <archivo>, acá especificamos los archivos (.h) que incluyen la declaración de los métodos y funciones que se utilizan en el código
#include <iostream>	// Biblioteca donde se encuentran las funciones "cin" y "cout"
#include <cstring>	// usaremos la función "strcpy()" que se encuantra en string.h
using namespace std;	// uso del espacio de nombres std (es el lugar donde buscar los recursos que estemos utilizando en este programa)


// 2. Declaración de funciones. Lo más ordenado es que los procedimientos se DECLAREN al inicio del programa (en esta parte), y luego se DEFINAN (codificarlos) en algun lugar del programa (típicamente a continuación de la rutina main())
int suma_pares(int a, int b);	// funcion que recibe 2 enteros y retorna un entero

/* 3. El main() se puede invocar con argumentos que el código debe recuperar, se tiene:
<int argc> un entero que indica la cantidad de argumentos que recibe el progrma.
<char **argv> un arreglo de caracteres con los argumentos entregados, la posición argv[0] es el nombre del programa y a partir de la posición argv[1] viene los argumentos del usuario. */
int main(int argc, char **argv){
	//4. Dentro de cada método, lo ideal es comenzar con la declaración de variables. 
	int a, b, sum_par;

	//5. Validación de argmentos de entrada
	if(argc != 3){
		cout << "Error. Debe ejecutarse como ./progPlantilla n string" << endl;
		exit(EXIT_FAILURE);
	} 
	

	if(false){	// no entra jamás
			// esto es para testear el switch-case:
		int i = 2;
		switch (i) {
			case 1: std::cout << "1";
			case 2: std::cout << "2";
				break;
			case 3: std::cout << "3";
			case 4:
			case 5: std::cout << "45";
				break;
			case 6: std::cout << "6";
		}
		std::cout << endl;
	}

	cout << "Este es el valor de argv[0]: " << argv[0] << endl;

	// 6. Lectura de argumentos del programa (argv[1], argv[2], ..., etc)
	int n = atoi(argv[1]);	// lee el argumento en la posición [1]
	char s[100];				// crea un string (que es un arreglo en realidad) --> MEMORIA ESTÁTICA
	strcpy(s, argv[2]);		// lee el argumento en la posición [2]
	cout << "Entero leído desde los argumentos del pgma. argv[1]: " << n << endl;
	cout << "String leído desde los argumentos del pgma. argv[2]: " << s << endl;

	a=1; b=0;
	while(a>b){
		cout << "Ingrese el inicio del intervalo, a :";
		cin >> a;	// lectura desde el teclado
		cout << "Ingrese el fin del intervalo, b :";
		cin >> b;
	}

	// 7. Invicamos a nuestra función
	sum_par = suma_pares(a, b);
	cout << "Suma de pares en [" <<a<< ".." <<b<< "] = " << sum_par << endl;

	cout << "Programa terminado exitosamente !!" << endl;
	return EXIT_SUCCESS; // 8. código de éxito, recuerde que definimos que el main() retorna un entero
}
// 9. Una vez terminado la turina principal main(), viene la definición de todos los métodos que fueron declarados al inicio del programa (en 2.)

// 10. Decripción de lo que realiza cada método
//suma_pares(a,b) realiza la suma de los enteros pares en el intervalo [a..b] y retorna la suma
int suma_pares(int a, int b){
	int sumPares = 0;	// la variable se inicializa con el valor 0, ya que no sabemos que valor tiene al comenzar la ejecución del código

	while(a<=b){
		if(a%2==0)
			sumPares+=a;	// acumula la suma en sumPares. Al hacer sumPares+=a; 
					// es equivalente a que hagamos sumPares = sumPares + a; 

		a++; // Al hacer a++; es equivalente a que hagamos a = a + 1; 
	}

	return sumPares;
}
