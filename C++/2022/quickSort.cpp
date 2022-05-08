#include <iostream>
#include <time.h>
#include <random>
#include <vector>
using namespace std;

int particion(vector<int> &v, int l, int r){
	int pv = v[l],p=l;
	for (int i = l+1; i <= r; i++){
		if(v[i]<=pv){
			p++;
			swap(v[p],v[i]);
		}
	}
	swap(v[l],v[p]);
	return p;
}

void quickSort(vector<int> &v, int l, int r){
	if(l<r){
		int m = particion(v,l,r);
		quickSort(v,l,m-1);
		quickSort(v,m+1,r);
	}
}

int main(){
    srand(time(NULL));
    int n;
    cout << "Ingrese la cantidad de elementos que quiere en su arreglo: ";
    cin >> n;
    vector<int> arreglo(n,0); 
    for (int i = 0; i < n; i++){
        arreglo[i] = rand()%100;
		cout << arreglo[i] << " ";
    }
	cout <<endl;	
    quickSort(arreglo,0,n-1);
    for (int i = 0; i < n; i++){
        cout << arreglo[i] << " ";
    }   
}