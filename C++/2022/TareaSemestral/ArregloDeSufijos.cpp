#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> buscaPatron(vector<vector<char>> V, vector<char> P);
void QuickSortLexicograficamente(vector<vector<char>> &v, int l, int r);
int particion(vector<vector<char>> &v, int l, int r);
bool menorLex(vector<char> v_i, vector<char> pv);
bool esPatron(vector<char> I, vector<char> P);

int main(){
    ifstream archivo("dna.50MB");
    if(archivo.is_open()){
        string line,patron;
        vector<char> aux(0);
        while(getline(archivo,line)){
            for(char c : line) aux.push_back(c);
        }
        archivo.close();
        int aux_n = aux.size();
        vector<vector<char>> V(aux_n);
        for(int i = 0; i < aux_n; i++){
            V[i] = aux;
            aux.erase(aux.begin());
        }
        QuickSortLexicograficamente(V, 0, V.size()-1);
        cout << "Ingrese su patron: ";
        getline(cin,patron);
        vector<char> P(0);
        for(char c : patron) P.push_back(c);
        vector<int> indices = buscaPatron(V,P);
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

bool menorLex(vector<char> v_i, vector<char> pv){
    int n_i = v_i.size(), n_pv = pv.size(), i = 0;
    while(i != n_i || i != n_pv){
        if(v_i[i] < pv[i]){
            return true;
        }
        if(v_i[i] > pv[i]){
            return false;
        }
        i++;
    }
    if(n_i < n_pv){
        return true;
    }
    return false;
}

int particion(vector<vector<char>> &v, int l, int r){
    int p = l;
    vector<char> pv = v[l];
    for (int i = l+1; i <= r; i++){
        if(menorLex(v[i],pv)){
            p++;
            swap(v[p],v[i]);
        }
    }
    swap(v[l],v[p]);
    return p;
}

void QuickSortLexicograficamente(vector<vector<char>> &v, int l, int r){
    if(l<r){
        int m = particion(v, l, r);
        QuickSortLexicograficamente(v, l, m-1);
        QuickSortLexicograficamente(v, m+1, r);
    }
}

bool esPatron(vector<char> I, vector<char> P){
    if(I.size() >= P.size()){
        int i = 0;
        while(i < P.size() && P[i] == I[i]) i++;
        if(i == P.size()) return true;
    }
    return false;
}

vector<int> buscaPatron(vector<vector<char>> v, vector<char> P){
    int l = 0, r = v.size()-1, m = r/2;
    vector<int> indices(0);
    while(l<=r){
		if(esPatron(v[m], P)){
			if(m == 0 || !esPatron(v[m-1], P)){
                l = m;
                break;  
            }
        }		
        if(menorLex(P, v[m]) || esPatron(v[m], P))
            r=m-1;
        else
            l=m+1;
		m=(l+r)/2;
	}
    // if(!esPatron(v[l], P)) return indices;  10 30
    r = v.size()-1;
    m = (l+r)/2;
    int l_aux = l;
    while(l_aux<=r){
		if(esPatron(v[m], P)){
			if(m == v.size()-1 || !esPatron(v[m+1], P)){
                r = m;
                break;  
            }
        }		
        if(menorLex(v[m],P) || esPatron(v[m], P))
            l_aux=m+1;
        else
            r=m-1;
		m=(l_aux+r)/2;
	}
    for(int j = r; j >= l; j--){
        indices.push_back(v.size() - v[j].size());
    }
    return indices;
}