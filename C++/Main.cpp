#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

const int width = 20, height = 20;
int headPos[2], foodPos[2];
int score;

enum directionEnum {STOP = 0,LEFT, RIGHT, UP, DOWN };
directionEnum snakeDirection;

bool gameOver;

void init(){
    system("cls");

    headPos[0] = width/2;
    headPos[1] = height/2;

    foodPos[0] = rand()%width;
    foodPos[1] = rand()%height;

    score = 0;

    snakeDirection = STOP;

    gameOver = false;
}

void render(){
    for(int i = 0; i < width + 2; i++){
        cout <<"#";
    }

    cout <<endl;

    for(int i = 0; i < width + 2; i++){
        for(int j = 0; j < height + 2; j++){
            if(j == 0)
                cout << "#";

            if(j == headPos[0] && i == headPos[1])
                cout << "0";
            else if(j == foodPos[0] && i == foodPos[1])
                cout << "*";
            else 
                cout << " ";

            if(j == width-1) 
                cout << "#";
        }
        cout << endl;
    }
    
    for(int i = 0; i < height + 2; i++){
        cout << "#";
    }
    cout <<endl<<endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a': 
                break;
            case 'd': 
                break;
            case 'w': 
                break;
            case 's': 
                break;
        }
    }
}

void gameLogic(){

}

int main(){
    srand(time(NULL));
    init();
    while(!gameOver){
        render();
        input();
        gameLogic();
        Sleep(50);
        gameOver=true;
    }
}