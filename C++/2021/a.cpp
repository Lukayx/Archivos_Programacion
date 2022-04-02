#include <iostream>
using namespace std;

int main(){
    cout << "Solo declaracion:\n" << endl;
    int lista[] = {1,2,3,4,5,6};
    for (int i=0;i < sizeof(lista)/sizeof(*lista) ;i++)
        if(i%2==0) 
            cout << lista[i] << "-" ;
        else
            cout << lista[i] << endl;
    return 0;
}