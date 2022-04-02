#include <iostream>
#include <string>
using namespace std;

string sumaFraccional(string f1, string f2){
	int num1[2];
	int posFin = f1.find('/');
	num1[0]= stoi(f1.substr(0,posFin));
	num1[1]= stoi(f1.substr(posFin+1, f1.size()));
	return num1[1];
}

int main( int argc, char *argv[] ){

	// casos de prueba
	cout << sumaFraccional("1/5","2/3") << endl; // 1/5 +2/3 = 13/15
	cout << sumaFraccional("2/3","5/2") << endl; // 2/3 +5/2 = 3 + 1/6
	cout << sumaFraccional("1/4","7/2") << endl; // 1/4 + 7/2  = 3 + 3/4
	cout << sumaFraccional("48/7","7/11") << endl; // 48/7 + 7/11  = 7 + 38/77

	return 0;
}
