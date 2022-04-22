#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool palindrome(char *S, int l, int r);
void reverso(char *S, int l);
void reemplazar(char *S, int n, char a, char b, int k);
int sumaDigitos(long int num, int i, int k);
int factorial(long int n);
int fibonacci(int n);

int main(int argc, char **argv){
	char S[] = "palabra";
	int l=7, n;
	long int num = 3984592137;
	char frase[256];

	cout << "Ingrese n: ";
	cin >> n;
	cout << "factorial(n) = " << factorial(n) << endl;
	cout << "Finonacci(n) = " << fibonacci(n) << endl;
	
	/*cout << "Ingrese una frase:" << endl;
	cin.getline (frase,256);
	int len = strlen(frase);
	cout << "strlen(frase) = " << len << endl;
	cout << "Frase palindrome: " << palindrome(frase, 0, len-1);

	cout << "S = " << S << endl;
	reemplazar(S, l, 'a', 'r', 0);
	cout << "reempazar(S) = " << S << endl;
	cout << "sumaDigitos(num, 10, 5): " << sumaDigitos(num, 10, 5) << endl;*/
	return EXIT_SUCCESS;
}

bool palindrome(char *S, int l, int r){
	return false;
}
void reverso(char* S, int l){

}

void reemplazar(char *S, int n, char a, char b, int k){

}

int sumaDigitos(long int num, int i, int k){

	return 0;
}

int factorial(long int n){
	return 0;
}

// f(1) = f(2) = 1
// f(n) = f(n−2) + f(n−1); n>2
// 1,1,2,3,5,8,13,21
int fibonacci(int n){
	return 0;
}







