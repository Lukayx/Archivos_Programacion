#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

vector<int> leeArchivo(vector<char> &T, string path);
void Busqueda_ArregloSufijos(vector<char> T, vector<int> inSuf, vector<char> P, vector<int> &indices);
void QuickSortLexicograficamente(vector<char> T, vector<int> &inSuf, int l, int r);
int particion(vector<char> T, vector<int> &inSuf, int l, int r);
bool menorLexOrdenamiento(int v_i, int pv, vector<char> T);
bool menorLex(vector<char> P, vector<char> T, int t_i);
bool esPatron(int v_i, vector<char> T, vector<char> P);

int main(){
    if(argc != 2){
		cout << "Error. Debe ejecutarse como ./ArregloDeSufijos " << endl;
		exit(EXIT_FAILURE);
	}
    //--------------------------CREACION ARREGLO CHAR Y DE SUFIJOS--------------------------------
    string path = __FILE__; //gets source code path, include file name
    path = path.substr(0,1+path.find_last_of('\\')); //removes file name
    path += atos(argv[1]); //adds input file to path
    vector<char> T(0);
    vector<int> suf = leeArchivo(T, path); //EN ESTA FUNCION ESTA EL ORDENAMIENTO QUE SE DEMORA MUCHO
    //--------------------------------------BUSQUEDA--------------------------------------
    string patron;
    cout << "Ingrese su patron: ";
    cin >> patron;
    //unsigned t1,t0;
    int p_n = patron.size();
    vector<char> P(p_n);
    for(int i = 0; i < p_n; i++) P[i] = patron.at(i); 
    vector<int> indices (0); 
    //t0 = clock();
    Busqueda_ArregloSufijos(T,suf,P,indices);
    //t1 = clock();
    //double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Se encontraron " << indices.size() << " coincidencias" << endl;
    //cout << "El tiempo que demoró fue: " << time << endl;
    //cout << "Se encontraron coincidencias en: " << endl;
    //for(int i : indices) cout << "Indice: " << i << endl;
    return EXIT_SUCCESS;
}

vector<int> leeArchivo(vector<char> &T, string path){
    ifstream archivo(path);
    if(archivo.is_open()){
        string line;
        while(getline(archivo,line)) {
            for(char c : line) T.push_back(c); //CREACION DE VECTOR CON CARACTERES DEL TEXTO
        }
        archivo.close();
        int n = T.size(), i = 0; //N ES EL LARGO DEL VECTOR(PARA NO LLAMAR T.SIZE() MUCHAS VECES) - i sera un iterador
        vector<int> suf(n); // AQUI SE ALMACENARAN LOS INDICES DE LOS SUFIJOS DEL TEXTO (LUEGO ORDENAREMOS EL VECTOR EN BASE A SUS POSICIONES RESPECTO AL VECTOR T) 
        string c; // UTILIZARE ESTA VARIABLE VARIAS VECES PARA RECIBIR LAS RESPUESTAS ESCRITAS A MANO DEL USUARIO
        do{
            cout << "Tienes el archivo con los sufijos ordenados? ('si' o 'no'): ";
            cin >> c;
        }while(c.compare("no")!= 0 && c.compare("si") != 0 ); // MIENTRAS QUE LA RESPUESTA SEA DIFERENTE DE UN 'NO' Y  DIFERENTE UN 'SI' ENTONCES LE SEGUIRA PREGUNTANDO
        if(c.compare("si")==0){ // SI LA RESPUESTA ES 'SI'
            cout << "Ingrese el nombre del archivo: ";
            cin >> c;
            path = path.substr(0,1+path.find_last_of('/')) + c; // RECORTA HASTA EL ULTIMO '/' Y PEGA EL NOMBRE DEL ARCHIVO AHI
            ifstream archivo(path);
            if(archivo.is_open()){
                while(getline(archivo,line)) {
                    suf[i++] = stoi(line);//LEE EL ARCHIVO DE LOS SUFIJOS ORDENADOS, LOS TRANSFORMA A 'INT' Y LOS ALMACENA EN SU RESPECTIVA POSICION
                }
                archivo.close();
                //cout << "LARGO VECTOR SUFIJOS: " << suf.size() << endl;
                return suf; // RETORNA EL ARREGLO DE SUFIJOS ORDENADOS
            } else {
                cout << "No se ha podido encontrado el archivo" << endl;
            }
        }   
        for(i = 0; i < n; i++) suf[i] = i; // AGREGA TODOS LOS INDICES EN SUS RESPECTIVAS POSICIONES PARA SER DESPUES ORDENADO Y MODIFICADO ESTE VECTOR
        cout << "Se procedera con el ordenamiento del los sufijos" << endl;
        QuickSortLexicograficamente(T,suf, 0, n-1); //FUNCION QUICKSORT MODIFICADA PARA PODER ORDENAR SUFIJOS MEDIANTE UN VECTOR CON LAS POSICIONES DEL TEXTO Y EL VECTOR QUE ALMACENA EL TEXTO
        do{      
            cout << "Desea crear un archivo con los sufijos? ('si' o 'no'): ";
            cin >> c;
        }while(c.compare("no") != 0 && c.compare("si") != 0 ); // MIENTRAS QUE LA RESPUESTA SEA DIFERENTE DE UN 'NO' Y  DIFERENTE UN 'SI' ENTONCES LE SEGUIRA PREGUNTANDO
        if(c.compare("si") == 0){
            cout << "Ingrese el nombre del archivo que quiere crear: ";
            cin >> c;
            ofstream escritura;
            escritura.open(c,ios::out);
            if(escritura.fail()){
                cout << "no se pudo crear el archivo" << endl;
            } else {
                for(i = 0; i < n-1; i++) escritura << suf[i] << endl; // ESCRIBE EL INDICE EN UNA LINEA DEL TEXTO Y LUEGO SALTA DE LINEA PARA ESCRIBIR EN LA SIGUIENTE
                escritura << suf[i]; // ULTIMA ITERACION SE ESCRIBE APARTE PARA NO DEJAR UN SALTO DE LINEA EXTRA
            }
        }
        return suf; // RETORNA EL ARREGLO DE SUFIJOS ORDENADOS
    } else {
        cout << "No se puede abrir el archivo" << endl;
        vector <int> suf(0);
        return suf; // RETORNA EL ARREGLO DE SUFIJOS VACIO
    }
}

bool menorLex(vector<char> P, vector<char> T, int t_i){ //UNA SIMPLE COMPRABACION DE PATRON AL INICIO DEL VECTOR ('t_i' es el sufijo del vector con el texto)
    int p_n = P.size(), t_n = T.size(), i = 0;
    while(i != p_n && (i+t_i) != t_n){
        if(P[i] < T[i+t_i]) return true; //SI ES MENOR ENTONCES TRUE
        if(P[i] > T[i+t_i]) return false; //SI ES MAYOR ENTONCES FALSE  
        i++;
    }
    if(i==p_n) return true;
    return false;
}

bool menorLexOrdenamiento(int v_i, int pv, vector<char> T){ // 'v_i' ES EL INDICE DEL SUFIJO QUE SE QUIERE VER SI ES MENOR QUE EL INDICE DE 'pv' (AMBOS EN T)
    int n = T.size(), i = 0;
    while(i+v_i != n && i+pv != n){
        if(T[i+v_i] < T[i+pv])// TRUE SI ES MENOR EL SUFIJO DE v_i
            return true;
        
        if(T[i+v_i] > T[i+pv])// FALSE SI ES MAYOR EL SUFIJO DE v_i
            return false;
        
        i++;
    }
    if(i+v_i == n) //SI 'SUFIJO DE v_i' LLEGÓ AL MAXIMO DEL VECTOR Y ES IGUAL AL SUFIJO DE 'pv' ENTONCES TRUE ('v_i' es menor) 
        return true;
    return false; // SI NO ENTONCES FALSE
}

int particion(vector<char> T, vector<int> &inSuf, int l, int r){ //
    int p = l , pv = inSuf[l];
    for (int i = l+1; i <= r; i++){
        if(menorLexOrdenamiento(inSuf[i],pv, T)){ // COMPRUEBA MENOR CON INDICE DE SUFIJO 'inSuf[i]' y 'pv' en T
            p++;
            swap(inSuf[p],inSuf[i]); // HACE EL CAMBIO EN EL VECTOR DE ENTEROS (INDICES DE SUFIJOS)
        }
    }
    swap(inSuf[l],inSuf[p]);
    return p;
}

void QuickSortLexicograficamente(vector<char> T, vector<int> &inSuf, int l, int r){
    if(l<r){
        int m = particion(T, inSuf, l, r);
        QuickSortLexicograficamente(T,inSuf, l, m-1);
        QuickSortLexicograficamente(T,inSuf, m+1, r);
    }
}

bool esPatron(int v_i, vector<char> T, vector<char> P){
    int v_n = T.size(), p_n = P.size();
    if(v_n-v_i >= p_n){ // VERIFICA SI ALMENOS EL SUFIJO TIENE UN LARGO SUFICIENTE PARA LA COMPARACIÓN
        int i = 0;
        while(i < p_n && P[i] == T[v_i+i]) i++;// I AUMENTARA MIENTRAS COINCIDA CON EL PATRON Y NO SE SALGA DEL LARGO DEL PATRON
        if(i == p_n) return true;// SI LLEGÓ AL FINAL ENTONCES RETORMA TRUE
    }
    return false; //SI NO RETORNA FALSE
}

void Busqueda_ArregloSufijos(vector<char> T, vector<int> inSuf, vector<char> P, vector<int> &indices){
    int l = 0, n = inSuf.size(), r = n-1, m = r/2;
    while(l<=r){
		if(esPatron(inSuf[m], T, P)){ // SI ENCUENTRA UNA COINCIDENCIA EN T[inSuf[M]]
			if(m == 0 || !esPatron(inSuf[m-1], T, P)){ //EN CASO DE QUE SEA EL PRINCIPIO DEL VECTOR (PRIMERA COINCIDENCIA DEL PATRON) O QUE EL ANTERIOR A T[inSuf[M]] NO TENGA EL PATRON
                l = m; //SE ENCONTRO EL EXTREMO INFERIOR DONDE SE ENCUENTRAN LAS COINCIDENCIAS
                break;  
            }
            r=m-1;
        }else if(menorLex(P,T,inSuf[m])){// SI NO HAY COINCIDENCIA EN T[inSuf[M]] ENTONCES VERÁ SI EL PATRON SE ENCUENTRA MAS A LA DERECHA O A LA IZQUIERDA DEL VECTOR
            r=m-1;//SI EL PATRON ES MENOR QUE T[inSuf[M]]
        }
        else{
            l=m+1;//SI EL PATRON ES MAYOR A T[inSuf[M]]
        }
		m=(l+r)/2;// SE LE ASIGNA A 'M' LA MITAD DEL INTERVALO L HASTA R COMO PIVOTE
	}
    if(r<l) return; // SI SE DIVIDIÓ VARIAS VECES Y NO ENCONTRO COINCIDENCIA ENTONCES PARARA LA BUSQUEDA
    r = n-1; // EL R VUELVE A SER EL LARGO COMPLETO DEL VECTOR
    m=(l+r)/2;
    int l_aux = l;// EXTREMO INFERIOR AUXILIAR PARA NO MODIFICAR EL YA LISTO
    while(l_aux<=r){
		if(esPatron(inSuf[m], T, P)){ // SI ENCUENTRA UNA COINCIDENCIA EN T[inSuf[M]]
			if(m >= n-1 || !esPatron(inSuf[m+1], T, P)){// SI ES INDICE MAXIMO O SI EL QUE VIENE DESPUÉS NO TIENE EL PATRON 
                r = m; //SE ENCONTRO EL EXTREMO SUPERIOR DONDE SE ENCUENTRAN LAS COINCIDENCIAS
                break;  
            }
            l_aux=m+1; // SI SE ENCUENTRA EN MEDIO DEL PATRON ENTONCES EL EXTREMO SUPERIOR DEBE ESTAR MAS ADELANTE
        } else{
            r=m-1; // SI NO SE ENCUENTRA EN EL PATRON ENTONCES SE CAMBIA EL R
        }
		m=(l_aux+r)/2; // SE LE ASIGNA A 'M' LA MITAD DEL INTERVALO L_aux HASTA R COMO PIVOTE
	}
    for(int j = l; j <= r; j++)
        indices.push_back(inSuf[j]); //ITERARÁ DONDE ESTAN LOS PATRONES Y AGRAGARÁ TODOS SUS INDICES
}