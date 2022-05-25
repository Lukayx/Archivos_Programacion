#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<vector<char>> v(10);
    string palabra = "0123456789";
    for(int i = 0; i < palabra.size(); i++){
        cout << "largo vector " << v[i].size(); 
        for(int j = i; j < palabra.size(); j++){
            v[i].push_back(palabra.at(j));
        }
    }

    for(int i = 0; i < palabra.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
        }
        cout << endl;
    }
}