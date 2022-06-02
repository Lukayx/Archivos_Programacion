#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void Busqueda_ArregloSufijos(vector<char> v, vector<int> inSuf, vector<char> P, vector<int> &indices);
void QuickSortLexicograficamente(vector<char> v, vector<int> &inSuf, int l, int r);
int particion(vector<char> v, vector<int> &inSuf, int l, int r);
bool menorLexOrdenamiento(int v_i, int pv, vector<char> v);
bool menorLex(vector<char> V1, vector<char> V2, int i_v1, int i_v2);
bool esPatron(int v_i, vector<char> v, vector<char> P);

int main(){
    string path = __FILE__; //gets source code path, include file name
    path = path.substr(0,1+path.find_last_of('\\')); //removes file name
    path+= "test.txt"; //adds input file to path
    ifstream archivo(path);
    if(archivo.is_open()){
        string line,text,patron;
        vector<char> V(0);
        while(getline(archivo,line)) {
            for(char c : line){
                V.push_back(c);
            }
        }
        archivo.close();
        int n = V.size();
        vector<int> suf(n);
        for(int i = 0; i < n; i++) {
            suf[i] = i;
        }
            
        //QUICKSORT
        QuickSortLexicograficamente(V,suf, 0, n-1);
        cout << "Ingrese su patron: ";
        getline(cin,patron);
        int p_n = patron.size();
        vector<char> P(p_n);
        for(int i = 0; i < p_n; i++) P[i] = patron.at(i); 
        vector<int> indices (0); 
        Busqueda_ArregloSufijos(V,suf,P,indices);
        cout << "Se encontraron coincidencias en: " << endl;
        for(int i : indices){
            cout << "Indice: " << i << endl;
        }
        return EXIT_SUCCESS;
    } else {
        cout << "No se puede abrir el archivo" << endl;
        return EXIT_FAILURE;
    }
}

bool menorLexOrdenamiento(int v_i, int pv, vector<char> v){
    int n = v.size(), i = 0;
    while(i+v_i != n || i+pv != n){
        if(v[i+v_i] < v[i+pv]){
            return true;
        }
        if(v[i+v_i] > v[i+pv]){
            return false;
        }
        i++;
    }
    if(i+v_i == n){
        return true;
    }
    return false;
}

bool menorLex(vector<char> V1, vector<char> V2, int i_v1, int i_v2){
    int n_i = V1.size(), n_V2 = V2.size(), i = 0;
    while(i != n_i || i != n_V2){
        if(V1[i] < V2[i]){
            return true;
        }
        if(V1[i] > V2[i]){
            return false;
        }
        i++;
    }
    if(n_i < n_V2){
        return true;
    }
    return false;
}

int particion(vector<char> v, vector<int> &inSuf, int l, int r){
    int p = l , pv = inSuf[l];
    for (int i = l+1; i <= r; i++){
        if(menorLexOrdenamiento(inSuf[i],pv, v)){
            p++;
            swap(inSuf[p],inSuf[i]);
        }
    }
    swap(inSuf[l],inSuf[p]);
    return p;
}

void QuickSortLexicograficamente(vector<char> v, vector<int> &inSuf, int l, int r){
    if(l<r){
        int m = particion(v, inSuf, l, r);
        QuickSortLexicograficamente(v,inSuf, l, m-1);
        QuickSortLexicograficamente(v,inSuf, m+1, r);
    }
}

bool esPatron(int v_i, vector<char> v, vector<char> P){
    if(v.size()-v_i >= P.size()){
        int i = 0;
        while(i < P.size() && P[i] == v[v_i+i]) i++;
        if(i == P.size()) return true;
    }
    return false;
}

void Busqueda_ArregloSufijos(vector<char> v, vector<int> inSuf, vector<char> P, vector<int> &indices){
    int l = 0, n = v.size(), r = n-1, m = r/2;
    while(l<=r){
		if(esPatron(inSuf[m], v, P)){
			if(m == 0 || !esPatron(inSuf[m-1], v, P)){
                l = m;
                break;  
            }
        }		
        if(menorLex(P,v,0,inSuf[m]) || esPatron(inSuf[m], v, P))
            r=m-1;
        else
            l=m+1;
		m=(l+r)/2;
	}
    r = n-1;
    int l_aux = l;
    while(l_aux<=r){
		if(esPatron(inSuf[m], v, P)){
			if(m == n-1 || !esPatron(inSuf[m+1], v, P)){
                r = m;
                break;  
            }
        }		
        if(menorLex(v,P,inSuf[m],0) || esPatron(inSuf[m], v, P))
            l_aux=m+1;
        else
            r=m-1;
		m=(l_aux+r)/2;
	}
    for(int j = r; j >= l; j--){
        indices.push_back(inSuf[j]);
    }
}