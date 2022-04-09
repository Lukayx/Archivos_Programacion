#include <iostream>
#include <string> 
using namespace std;
// compile string

class Player{
    private: //Atributos
        float level = 1;
        float experience = 0;
        float limit_Experience = 10;
        string name,breed,gender;
        float HP, MP, ATTACK, DEFENSE;
    public: //Metodos
        Player(string, string, string); //Constructor
        void Stats(string gender);
};

Player::Player(string _name, string _breed, string _gender){
    name = _name;
    breed = _breed;
    gender = _gender;
    if(breed == "Humano"){
        HP = 10;
        MP = 10;
        ATTACK = 4;
        DEFENSE = 5;
    }else if(breed == "Elfo"){
        HP = 7;
        MP = 16;
        ATTACK = 3;
        DEFENSE = 3;
    }else if(breed == "Enano"){
        HP = 15;
        MP = 5;
        ATTACK = 5;
        DEFENSE = 7;
    }
}

void identidad(){
    string nombre,raza,genero;
    int edad;
    cout << "Cual su nombre? " << endl;//NOMBRE
    cin>>nombre;
    do{
        cout << "Escriba cual es su raza (Humano, Elfo o Enano): " << endl;//RAZA
        cin >> raza;
    } while(raza.find("Humano") or raza!="Elfo" or raza!="Enano");
    do{
        cout << "Eres Hombre o Mujer? " << endl;//GENERO
        cin>>genero;
    }while(genero=="Hombre" or genero!="Mujer");
    Player jugador1(string nombre, string raza, string genero);
}

int main(){
    identidad();
    return 0;
}
