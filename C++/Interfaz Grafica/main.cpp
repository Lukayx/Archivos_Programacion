#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<cstdlib>

using namespace std;

//Dimenciones de la Pantalla
const int WIDTH = 960, HEIGHT = 800;
string path = __FILE__; //gets source code path, include file name

int main(){
    path = path.substr(0,1+path.find_last_of('\\'))+"MP_0.png";
    initwindow(WIDTH, HEIGHT, "Juego", 100, 10);
    setviewport(0,0,800,300,1);
    setbkcolor(BLUE);
    clearviewport();
    readimagefile(,0,0,300,1);
    getch();
}   