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
    path = path.substr(0,1+path.find_last_of('\\'));
    initwindow(WIDTH, HEIGHT, "Juego", 100, 10);
    //setviewport(0,0,960,200,1);
    //setbkcolor(BLUE);
    //clearviewport();
    //cleardevice();
    while(true){
        for(int i=0; i<=14;i++){
            string b = "MP_i.jpg";
            b.replace(3,1,to_string(i));
            readimagefile(b.c_str(),0,0,960,800);
        }
    }
    getch();
}   