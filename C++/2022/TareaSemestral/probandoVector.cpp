#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<int> v(0);
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    v.push_back(400);
    for(int i : v){
        cout << i << endl;
    }
    cout << endl;
    v.erase(v.begin());
    for(int i : v){
        cout << i << endl;
    }
    cout << endl;
    v.erase(v.begin());
    for(int i : v){
        cout << i << endl;
    }
}