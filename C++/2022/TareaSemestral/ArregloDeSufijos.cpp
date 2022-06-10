#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<int> leeArchivo(vector<char> &v, string path);
void Busqueda_ArregloSufijos(vector<char> v, vector<int> inSuf, vector<char> P, vector<int> &indices);
void QuickSortLexicograficamente(vector<char> v, vector<int> &inSuf, int l, int r);
int particion(vector<char> v, vector<int> &inSuf, int l, int r);
bool menorLexOrdenamiento(int v_i, int pv, vector<char> v);
bool menorLex(vector<char> P, vector<char> T, int t_i);
bool esPatron(int v_i, vector<char> v, vector<char> P);

int main(){
    //--------------------------CREACION ARREGLO CHAR Y DE SUFIJOS--------------------------------
    string path = __FILE__; //gets source code path, include file name
    path = path.substr(0,1+path.find_last_of('\\')); //removes file name
    path+= "test.txt"; //adds input file to path
    cout << path << endl;
    vector<char> V(0);
    vector<int> suf = leeArchivo(V, path);
    //--------------------------------------BUSQUEDA--------------------------------------
    string patron;
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
}

vector<int> leeArchivo(vector<char> &V, string path){
    ifstream archivo(path);
    if(archivo.is_open()){
        string line;
        while(getline(archivo,line)) {
            for(char c : line) V.push_back(c);
        }
        archivo.close();
        int n = V.size(), i = 0;
        vector <int> suf(n);
        string c;
        do{
            cout << "Tienes el archivo con los sufijos ordenados? ('si' o 'no')" << endl;
            cin >> c;
        }while(c.compare("no")!= 0 && c.compare("si") != 0 );
        if(c.compare("si")==0){
            cout << "Ingrese el nombre del archivo: ";
            cin >> c;
            path = path.substr(0,1+path.find_last_of('/')) + c;
            ifstream archivo(path);
            if(archivo.is_open()){
                while(getline(archivo,line)) {
                    suf[i++] = stoi(line);
                }
                archivo.close();
                return suf;
            } else {
                cout << "No se ha podido encontrado el archivo" << endl;
            }
        }   
        cout << "Se procedera con el ordenamiento del los sufijos" << endl;
        for(i = 0; i < n; i++) suf[i] = i;
        QuickSortLexicograficamente(V,suf, 0, n-1);
        do{      
            cout << "Desea crear un archivo con los sufijos? ('si' o 'no')";
            cin >> c;
        }while(c.compare("no")!= 0 && c.compare("si") != 0 );
        if(c.compare("si")==0){
            cout << "Ingrese el nombre del archivo que quiere crear: " << endl;
            cin >> c;
            ofstream escritura;
            escritura.open(c,ios::out);
            for(i = 0; i < n-1; i++){
                escritura << suf[i] << endl;
            }
            escritura << suf[i];
            if(escritura.fail()){
                cout << "no se pudo crear el archivo" << endl;
            }
        }
        return suf;
    } else {
        cout << "No se puede abrir el archivo" << endl;
        vector <int> suf(0);
        return suf;
    }
}

bool menorLexOrdenamiento(int v_i, int pv, vector<char> v){
    int n = v.size(), i = 0;
    while(i+v_i != n && i+pv != n){
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

bool menorLex(vector<char> P, vector<char> T, int t_i){
    int p_n = P.size(), t_n = T.size(), i = 0;
    while(i != p_n && (i+t_i) != t_n){
        if(P[i] < T[i+t_i]){
            return true;
        }
        if(P[i] > T[i+t_i]){
            return false;
        }
        i++;
    }
    if(p_n < t_n){
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
    int v_n = v.size(), p_n = P.size();
    if(v_n-v_i >= p_n){
        int i = 0;
        while(i < p_n && P[i] == v[v_i+i]) i++;
        if(i == p_n) return true;
    }
    return false;
}

void Busqueda_ArregloSufijos(vector<char> v, vector<int> inSuf, vector<char> P, vector<int> &indices){
    int l = 0, n = inSuf.size(), r = n-1, m = r/2;
    while(l<=r){
		if(esPatron(inSuf[m], v, P)){
			if(m == 0 || !esPatron(inSuf[m-1], v, P)){
                l = m;
                break;  
            }
            r=m-1;
        }else if(menorLex(P,v,inSuf[m])){
            r=m-1;
        } else{
            l=m+1;
        }
		m=(l+r)/2;
	}
    if(r<l) return;
    r = n-1;
    int l_aux = l;
    while(l_aux<=r){
		if(esPatron(inSuf[m], v, P)){
			if(m >= n-1 || !esPatron(inSuf[m+1], v, P)){
                r = m;
                break;  
            }
            l_aux=m+1;
        } else
            r=m-1;
		m=(l_aux+r)/2;
	}
    for(int j = l; j <= r; j++){
        indices.push_back(inSuf[j]);
    }
}