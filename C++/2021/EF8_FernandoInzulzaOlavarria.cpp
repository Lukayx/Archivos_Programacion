#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

double hipotenusa(double ca, double co){
    double a = ca*ca;
    double o = co*co;
    double hipo = sqrt(a+o);
    return hipo; 
}

int main(int argc, char *argv[]){
    double array[6][6];
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            array[i-1][j-1] = hipotenusa(i,j);
            cout << j << ". " << array[i-1][j-1] << '\t' ;
        }
        cout << endl;
    }
}