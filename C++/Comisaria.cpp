#include <iostream>
#include <string>
using namespace std;

struct registro{ // DATOS DE DELINCUENTE
    string delicuente;
    string delito;
    int celda;
};

struct comisaria {
    int numPlaca;
    string name;
    char grado; //INICIAL DEL GRADO
    int *fecha = new int[1];
    struct arrestosDiarios[] = new struct[];
    for(int i = 0; i<7;i++){
        arrestosDiarios[i] = registro;
    }
};

int main(){
    
}