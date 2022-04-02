#include <iostream>
#include <string>
using namespace std;

// ESTE CODIGO LO QUE HACE ES BUSCAR UNA PALABRA EN UN STRING Y REEMPLAZARLA POR OTRA CADA VEZ QUE LA VEA //

string reemplazar(string texto, string buscar, string cambiar){
    int pos = 0; // posiciona un puntero al principio
    while(pos != texto.npos){ // mientras que se logre identificar una posición en el string donde coincida la busqueda
        pos = texto.find(buscar,pos); // busca el indice de la palabra especificada en el texto dado
        if(pos != texto.npos){ // si se logro encontrar un indice para la busqueda de la palabra entonces
            texto.replace(pos,buscar.size(),cambiar); // reemplaza la palabra buscada con la palabra almacenada en |"cambiar"|
            pos += cambiar.size(); // al puntero se le suma el tamaño de la palabra para que cuando vuelva a buscar empieze despues de ese cambio que hizo 
        }
    }
    return texto; // retorna el texto ya modificado
}

int main(){
    cout << reemplazar("si cres que eres capaz, eres capaz","capaz","incapaz") << endl;
    return 0;
}