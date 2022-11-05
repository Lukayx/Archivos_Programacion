#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<cstdlib>

using namespace std;

//Dimenciones de la Pantalla
const int WIDTH = 800, HEIGHT = 600;
//Dimenciones de nuestros pixeles
const int dW = 8, dH = 16;
//800/8 = 100 y 600/16 = 37.5

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void convertir(int P[2], float x, float y){
    P[0] = int(x)/dW;
    P[1] = int(y)/dH;
}

void convertir(int P[2], int x, int y){
    P[0] = x/dW;
    P[1] = y/dH;
}

// Funcion dibujar
void drawpoint(char plano[HEIGHT/dH][WIDTH/dW+1], int A, int B, char c){
    B = HEIGHT/dH -1 - B;
    if(A < 0 || B < 0 || A > WIDTH/dW || B > HEIGHT/dH) return;
    plano[B][A] = c;
}

class map{
    private:
        float n(float x){
            return 0;
        } 
    public:
        float f(float x){
            return 150*(n(x)+1.0f)/2.0f; // retorna 75 siempre
        }
        void dibujar(char plano[HEIGHT/dH][WIDTH/dW + 1]){
            for(int i = 0; i < WIDTH/dW; i++){
                int P[2];
                int j_inicio = f(i*dW)/dH; // 75 / 16 = 4.68
                for(int j = j_inicio; j >= 0; j--){
                    convertir(P,i*dW,j*dH);
                    drawpoint(plano, P[0],P[1], 'o');
                }
                convertir(P,i*dW,j_inicio*dH);
                drawpoint(plano, P[0],P[1], '#');
            }
        }
};

class personaje{

};

int main(){
    map mapa;
    char plano[HEIGHT/dH][WIDTH/dW + 1]; //Altura 37 Ancho 100 + 1 = 101
    for(int i = 0; i < HEIGHT/dH; i++){
        plano[i][WIDTH/dW] = '\n';
    }
    plano[HEIGHT/dH+1][WIDTH/dW] = '\0';
    while(true){
        gotoxy(0,0);
        for(int i = 0; i < HEIGHT/dH; i++){
            for(int j = 0; j < WIDTH/dW; j++){
                plano[i][j] = '*';
            }
        }
        puts(plano[0]);
    }

    return 0;
}