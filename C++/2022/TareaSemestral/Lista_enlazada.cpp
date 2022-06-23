#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

struct DoubleList {
    int IN;
    DoubleList *prev;
    DoubleList *next;
};
vector<int> BusquedaListaEnlazada(vector<char> T,vector<char> P,vector<int> I,int n,int m);
typedef struct DoubleList nodo;
using namespace std;

vector<int> leeArchivo(vector<char> &T, string path);
void QuickSortLexicograficamente(vector<char> T, vector<int> &inSuf, int l, int r);
int particion(vector<char> T, vector<int> &inSuf, int l, int r);
bool menorLexOrdenamiento(int v_i, int pv, vector<char> T);

int main(){
    //--------------------------CREACION ARREGLO CHAR Y DE SUFIJOS--------------------------------
    string path = __FILE__; //gets source code path, include file name
    path = path.substr(0,1+path.find_last_of('\\')); //removes file name
    path += "DNA4LINEAS"; //adds input file to path
    vector<char> T(0);
    vector<int> suf = leeArchivo(T, path); //EN ESTA FUNCION ESTA EL ORDENAMIENTO QUE SE DEMORA MUCHO
    //--------------------------------------BUSQUEDA--------------------------------------
    string patron;
    int n = suf.size();
    cout << "Ingrese su patron: ";
    cin >> patron;
    unsigned t1,t0;
    int p_n = patron.size();
    vector<char> P(p_n);
    for(int i = 0; i < p_n; i++) P[i] = patron.at(i); 
    vector<int> indices (0); 
    t0 = clock();
    indices=BusquedaListaEnlazada(T,P,suf,n,p_n);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Se encontraron " << indices.size() << " coincidencias" << endl;
    cout << "El tiempo que demoró fue: " << time << endl;
    //cout << "Se encontraron coincidencias en: " << endl;
    //for(int i : indices) cout << "Indice: " << i << endl;
    return EXIT_SUCCESS;
}
vector<int> BusquedaListaEnlazada(vector<char> T,vector<char> P,vector<int> I, int n,int m){
    vector<int> Indices;
    bool b_existe=false,b_lugar;
    //b_existe : variable que demuestra que existe el patron en el texto, b_lugar: variable que indica si se encontro el patron al principio o al final
    int i_patron,mini,i_lista;
    // i_patron : indice del patron(para compara con i_lista) , mini : al numero minimo de caracteres que debe de tener el texto para ser revisado
    // i_lista : indice del texto
    nodo *p = new nodo();
    nodo *L,*q;
    L=p;
    p->IN = I[0];
    for(int i=1;i<n; i++){     // creamos la lista enlazada
        nodo *q = new nodo();
        q->IN = I[i];
        p->next= q;
        q->prev= p;
        p=q;
    }
    mini=n-m;
    q=L;        // el puntero q queda al principio de la lista y el puntero p queda al final

    while ((p->IN != q->IN) && (b_existe==false)){   // recorremos hasta que encontremos el patron o ya no queden mas nodos por recorrer
        i_patron=0;
        i_lista=q->IN;
        while ((q->IN <= mini) && (i_patron < m) && (P[i_patron] == T[i_lista])){   //comparamos caracter a caracter
            i_lista++;
            i_patron++;
        }
        if (m == i_patron){     //  si i_patron = m, entonces encontramos el patron (en este caso lo encontramos primero al principio)
            b_existe=true;
            b_lugar=true;
        }

        else{                       // si el patron no se encuentra usando q, repetimos lo mismo pero con p
            i_patron=0;
            i_lista=p->IN;
            while ( p->IN <= mini && i_patron<m && T[i_lista]==P[i_patron]){
                i_patron++;
                i_lista++;
            }
            if (m==i_patron){
                b_existe=true;
                b_lugar=false;
            }
            else{            // si no se encontro con p y q, avanzamos y repitimos denuevo
                p=p->prev;
                q=q->next;
            }
        }
    }
    if (b_existe==true){    // entramos si encontramos el patron
                           // el algoritmo tiene 2 caminos desde aqui, el primero es seguir recorriendo la lista enlazada desde p hacia atras
                           // y el segundo es recorrer la lista desde q hacia adelante, dependiendo de donde encontro primero el patron
                           // en cualquiera de los dos casos al final a�ade los indices al vector Indices, pues los indices de la lista contienen el orden lexicografico del texto
                           // y este siempre va a tener los indices de nuestro patron juntos uno al lado del otro
        if (b_lugar==true){
            Indices.push_back(q->IN);
            while (b_existe==true){
                i_patron=0;
                i_lista=p->IN;
                while (p->IN<= mini && i_patron<m && T[i_lista] == P[i_patron]){
                    i_patron++;
                    i_lista++;
                }
                if (m==i_patron){
                    b_existe=false;
                    }
                else
                    p=p->prev;
            }
            i_patron=1;
            while (q->IN != p->IN){
                Indices.push_back(p->IN);
                i_patron++;
                p = p->prev;
            }
            return Indices;
        }
        else {
            Indices.push_back(p->IN);
            while (b_existe){
                i_patron=0;
                i_lista=q->IN;
                while(q->IN<= mini && i_patron<m && T[i_lista]== P[i_patron]){
                    i_lista++;
                    i_patron++;
                }
                if (m == i_patron)
                    b_existe=false;
                else
                    q=q->next;
            }
            i_patron=1;
            while (q->IN!=p->IN){
                Indices.push_back(q->IN);
                i_patron++;
                q = q->next;
            }
            return Indices;
        }
    }
    else{
        return Indices;}
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
                cout << "LARGO VECTOR SUFIJOS: " << suf.size() << endl;
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