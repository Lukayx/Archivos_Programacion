55// Huffman Coding in C++
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <queue>
#include <unistd.h>

using namespace std;
#ifndef uchar // 1 byte
#define uchar unsigned char
#endif
#ifndef ulong // 1 byte
#define ulong unsigned long int
#endif
//Estructuras y clases
struct chars
{
	uchar id;
	//binario
	bool *code;
	long int largo;
	//decimal
	ulong code_dec;

	ulong freq;
};
typedef struct chars caracter;
struct bins
{
	bool *code;
	ulong code_dec;
};
typedef struct bins bin_c;
class nodo
{
public:
	uchar id;
	ulong freq;

	nodo *left;
	nodo *right;
	nodo(uchar caracter,
		ulong frecuencia)
	{
		id = caracter;
		freq = frecuencia;
		left = right = NULL;
	}
};

// Comparador para comparar min
struct greaters
{
	bool operator()(nodo *a, nodo *b)
	{
		return a->freq > b->freq;
	}
};

//Funciones a usar

//heaps
int isLeaf(nodo *root);
void obtener_largos_huffman(nodo *root, ulong arr[], ulong top, vector<caracter> &caracteres_huffman);

//Huffman
void HuffmanCodes(vector<nodo> &caracteres, ulong size, uchar *S, char file[400]);
nodo *buildHfTree(priority_queue<nodo *, vector<nodo *>, greaters> Q);
string printArray(ulong arr[], ulong n);

//Huffman canónico
void canonic_Huffman(vector<caracter> &caracteres_huffman);

//Codificacion
bool *codificar_S(uchar *S, ulong Ssize, vector<caracter> &caracteres_huffman, ulong m);

//Decodificación
ulong *obtencion_F(vector<caracter> &Sigma, ulong h);
bin_c *obtencion_C(vector<caracter> &Sigma, ulong *F, ulong h);
void decodificacion_huffman(vector<caracter> &Sigma, bool *H, ulong m, ulong *F, bin_c *C, ulong u, ulong largo_arreglo);
ulong binarySearch(vector<caracter> &Sigma, ulong N, ulong *F, bin_c *C, ulong h);

//Funciones para la experimentacion
void experimento1(vector<caracter> &Sigma, bool *H, ulong m, ulong *F, bin_c *C, ulong u, ulong largo_arreglo);
void experimento2(vector<caracter> &Sigma, bool *H, ulong m, ulong *F, bin_c *C, ulong u, ulong largo_arreglo);

//Quicksort para caracteres
void quickSort(vector<caracter> &A, long int l, long int r);
long int partition(vector<caracter> &A, long int l, long int r);

//Files
uchar *readText(char file[400], vector<nodo> &caracteres);
void buscar_agregar_vector(uchar n, vector<nodo> &caracteres);
uint file_size(string filename);
void read_from_file(uchar *dest, uint n, FILE *f);

//Convertores
void to_bin(ulong num, ulong base_ini, ulong base_fin, caracter &a, ulong min);
ulong to_dec(bool *A, ulong l, ulong r);
void process_mem_usage(double &vm_usage, double &resident_set);

int main(int argc, char *argv[])
{
	//struct chars caracteres[]= {{'A',1}, {'B',3}, {'C',5}, {'D',7}};
	char archivo[400];
	if (argc != 2)
	{
		cout << "¡ERROR CON PARAMETROS! " << endl;
		cout << "… debe de dar el nombre (con ruta incluida) del archivo de puntos " << endl;
		exit(1);
	}
	strcpy(archivo, argv[1]);
	vector<nodo> caracteres;
	uchar *S;
	//cout << "Obtener S" << endl;
	S = readText(archivo, caracteres);
	cout << "Largo de caracteres : " << caracteres.size() << endl;
	//quickSort(caracteres, 0, caracteres.size() - 1);
	cout << endl;
	//cout << "    | Huffman code \n";
	cout << "\n----------------------\n";
	HuffmanCodes(caracteres, caracteres.size(), S, archivo);
	//cout << "Terminando huffman" << endl;
}

// Wrapper function
void HuffmanCodes(vector<nodo> &caracteres, ulong size, uchar *S, char file[400])
{
	double t,t1,t2;
	priority_queue<nodo *, vector<nodo *>, greaters> Q;
	for (uint i = 0; i < size; i++)
	{
		nodo *nuevo = new nodo(caracteres[i].id, caracteres[i].freq);
		Q.push(nuevo);
	}
	//cout << "entrando a buildHfTree" << endl;
	nodo *root = buildHfTree(Q);
	//cout << endl;

	//cout << "despues de buildHfTree" << endl;
	//cout << endl;

	ulong arr[size], top = 0;

	vector<caracter> caracteres_huffman;

	//cout << "obteniendo Largos Huffman" << endl;

	obtener_largos_huffman(root, arr, top, caracteres_huffman);

	//cout << "quickSort" << endl;

	quickSort(caracteres_huffman, 0, (uint)(caracteres_huffman.size() - 1));

	//cout << "canonic_Huffman" << endl;
	cout << "Largo de caracteres_huffman : " << caracteres_huffman.size() << endl;
	canonic_Huffman(caracteres_huffman);
	ulong m = 0;
	ulong S_size = 0;
	ulong largo_arreglo = 1;
	for (uint i = 0; i < caracteres_huffman.size(); ++i)
	{
		//cout << caracteres_huffman[i].id << ":" << (caracteres_huffman[i].largo) << " ";
		m += caracteres_huffman[i].largo * caracteres_huffman[i].freq;
		S_size += caracteres_huffman[i].freq;
		if (i > 0 && caracteres_huffman[i].largo != caracteres_huffman[i - 1].largo)
		{
			largo_arreglo++;
		}
	}
	cout << "Largo de H : " << m << endl;
	//double t1, t2, t;
	//cout << "Codificacion" << endl;
	cout << "Largo arreglo : " << largo_arreglo << endl;
	bool *H = codificar_S(S, S_size, caracteres_huffman, m);
	/*for (uint i = 0; i < m; ++i)
	{
		cout << H[i];
	}*/
	//cout << endl;
	//cout << "Decodificacion" << endl;
	//ulong largo_arreglo = caracteres_huffman.back().largo - caracteres_huffman.front().largo + 1;
	ulong *F = obtencion_F(caracteres_huffman, largo_arreglo);
	bin_c *C = obtencion_C(caracteres_huffman, F, largo_arreglo);

	t1 = clock();
	decodificacion_huffman(caracteres_huffman, H, m, F, C, S_size, largo_arreglo);
	t2 = clock();
	t = ((double)(t2 - t1) / CLOCKS_PER_SEC);
	cout << "Tiempo en decodificacion: " << t * 1000.0 << " ms " << endl;
	//Experimentacion
	experimento1(caracteres_huffman, H, m, F, C, S_size, largo_arreglo);
	experimento2(caracteres_huffman, H, m, F, C, S_size, largo_arreglo);
}
//Constructor de Huffman tree
nodo *buildHfTree(priority_queue<nodo *, vector<nodo *>, greaters> Q)
{
	while (Q.size() != 1)
	{
		nodo *left = Q.top();
		Q.pop();
		nodo *right = Q.top();
		Q.pop();
		nodo *node = new nodo('$', left->freq + right->freq);
		node->left = left;
		node->right = right;
		Q.push(node);
	}

	return Q.top();
}
//Obtener códigos canónicos de huffman
void canonic_Huffman(vector<caracter> &caracteres_huffman)
{
	//Se obtiene el primer código canónico
	bool *code_canonic = new bool[64];
	ulong diferencia_de_largos;
	uint min = caracteres_huffman[0].largo;
	for (uint i = 0; i < min; i++)
	{
		code_canonic[i] = 0;
	}
	caracteres_huffman[0].code = code_canonic;
	caracteres_huffman[0].code_dec = 0;
	caracteres_huffman[0].largo = min;
	uint i = 1;
	ulong code;
	//Obtiene los códigos del resto
	while (i < caracteres_huffman.size())
	{

		if (caracteres_huffman[i].largo == caracteres_huffman[i - 1].largo)
		{
			code = caracteres_huffman[i - 1].code_dec + 1;
		}
		else
		{
			diferencia_de_largos = caracteres_huffman[i].largo - caracteres_huffman[i - 1].largo;
			if (diferencia_de_largos == 1)
			{
				code = 2 * (caracteres_huffman[i - 1].code_dec + 1);
			}
			else
			{
				//cout << "difrencia de largos: " << diferencia_de_largos << "codigo decimal" << caracteres_huffman[i - 1].code_dec << endl;
				code = pow(2, diferencia_de_largos) * (caracteres_huffman[i - 1].code_dec + 1) + pow(2, diferencia_de_largos - 1);
			}
		}
		(to_bin(code, 10, 2, caracteres_huffman[i], caracteres_huffman[i].largo));
		i++;
	}
	//Imprime códigos canonicos
	/*for (caracter a : caracteres_huffman)
	{
		cout << a.id << " : " << a.largo << " : " << a.largo << " :: ";
		for (int j = 0; j < a.largo; j++)
		{
			cout << a.code[j];
		}
		cout << endl;
	}*/
}
//Codificar S con códigos canónicos
bool *codificar_S(uchar *S, ulong Ssize, vector<caracter> &caracteres_huffman, ulong m)
{
	bool *H = new bool[m];
	ulong iterador_h = 0;
	bool find;
	ulong j;
	for (uint i = 0; i < Ssize; ++i)
	{
		find = false;
		j = 0;
		while (!find && j < caracteres_huffman.size())
		{
			if (caracteres_huffman[j].id == S[i])
			{
				for (uint k = 0; k < caracteres_huffman[j].largo; ++k)
				{
					H[iterador_h] = (caracteres_huffman[j].code)[k];
					iterador_h++;
				}
				find = true;
			}
			j++;
		}
	}
	cout << endl;
	return H;
}
ulong *obtencion_F(vector<caracter> &Sigma, ulong h)
{
	ulong *F = new ulong[h];
	F[0] = 0;
	ulong l = 1;
	for (uint i = 1; i < Sigma.size(); i++)
	{
		if (Sigma[i].largo != Sigma[i - 1].largo)
		{
			F[l] = i;
			l++;
		}
	}
	cout << endl;
	return F;
}
bin_c *obtencion_C(vector<caracter> &Sigma, ulong *F, ulong h)
{

	bin_c *C = new bin_c[h];
	for (uint i = 0; i < h; i++)
	{
		C[i].code = new bool[Sigma[F[i]].largo];
		C[i].code = (Sigma[F[i]].code);
		C[i].code_dec = Sigma[F[i]].code_dec;
	}
	return C;
}
//Decodificación para los códigos canónicos
void decodificacion_huffman(vector<caracter> &Sigma, bool *H, ulong m, ulong *F, bin_c *C, ulong u, ulong largo_arreglo)
{
	ulong h, N, N_prima, i, posicion, l, char_listas;
	h = Sigma.back().largo;
	//Decodificacion
	N = to_dec(H, 0, h);
	i = l = N_prima = char_listas = 0;
	string S;
	while (i < m && char_listas < u)
	{
		l = binarySearch(Sigma, N, F, C, largo_arreglo);
		N_prima = to_dec(H, i, i + Sigma[F[l]].largo);
		posicion = F[l] + N_prima - C[l].code_dec;
		i += Sigma[F[l]].largo;
		S += Sigma[posicion].id;
		N = to_dec(H, i, i + h);
		char_listas += 1;
	}
	cout << S << endl;
}
ulong binarySearch(vector<caracter> &Sigma, ulong N, ulong *F, bin_c *C, ulong largoMax)
{
	//Como el arreglo empieza de 0 y no necesariamente en la posicion 0 Sigma tiene codificacion largo 0
	//Se usa Sigma[F[m]].largo, para obtener el largo real
	ulong A, B, h, r, l, m;
	h = Sigma.back().largo;
	r = largoMax - 1;
	l = 0;
	while (l <= r)
	{
		m = (ulong)((l + r) / 2);
		A = (C[m].code_dec) * pow(2, h - Sigma[F[m]].largo);
		if (A <= N)
		{
			if (m == largoMax - 1)
			{
				return m;
			}
			else
			{
				B = C[m + 1].code_dec * pow(2, h - (Sigma[F[m]].largo + 1));
				if (N < B)
				{
					return m;
				}
				else
				{
					l = m + 1;
				}
			}
		}
		else
		{
			r = m - 1;
		}
	}
	return -1;
}

void experimento1(vector<caracter> &Sigma, bool *H, ulong m, ulong *F, bin_c *C, ulong u, ulong largo_arreglo)
{
	cout << "Experimento 1" << endl;
	ulong k;
	int r = 20;
	double t1, t2, t, vm, rss;

	for (int i = 0; i < r; i++)
	{
		t1 = clock();
		//cout << "Repeticion : " << i + 1 << endl << endl;
		k = rand() % (u + 1);
		decodificacion_huffman(Sigma, H, m, F, C, k, largo_arreglo);
		t2 = clock();
		t = ((double)(t2 - t1) / CLOCKS_PER_SEC);
		process_mem_usage(vm, rss);
		cout << "REP : " << k << " se demoro : " << t << " s "
			 << " Ram virutal : " << vm << " Redidente : " << rss << endl;
	}
}
void experimento2(vector<caracter> &Sigma, bool *H, ulong m, ulong *F, bin_c *C, ulong u, ulong largo_arreglo)
{
	cout << "Experimento 2" << endl;
	int r = 20;
	double t1, t2, t, vm, rss;
	ulong i, j;

	ulong h, N, N_prima, inicio, posicion, l, char_listas, char_previos;
	h = Sigma.back().largo;
	for (int k = 0; k < r; k++)
	{
		t1 = clock();
		//cout << "Repeticion : " << k + 1 << endl << endl;
		i = rand() % (u + 1) + 1;
		j = rand() % (u + 1 - i) + i;

		//bool completo = false;

		//Decodificacion
		inicio = l = N_prima = char_listas = char_previos = 0;

		//Decodificacion
		N = to_dec(H, 0, h);
		string S_prima;
		while (inicio < m && char_listas < (j - i))
		{

			l = binarySearch(Sigma, N, F, C, largo_arreglo);
			N_prima = to_dec(H, inicio, inicio + Sigma[F[l]].largo);
			posicion = F[l] + N_prima - C[l].code_dec;
			inicio += Sigma[F[l]].largo;
			N = to_dec(H, inicio, inicio + h);
			if (char_previos < i)
				char_previos += 1;
			else
			{
				S_prima += Sigma[posicion].id;
				char_listas += 1;
			}
		}
		t2 = clock();
		t = ((double)(t2 - t1) / CLOCKS_PER_SEC);
		process_mem_usage(vm, rss);
		cout << "REP : " << k << " se demoro : " << t << " s "
			 << " Ram virutal : " << vm << " Redidente : " << rss << endl;
	}
}
//Ver si es hoja
int isLeaf(nodo *root)
{
	return !(root->left) && !(root->right);
}
//Obtiene e imprime los códigos del árbol de huffman
void obtener_largos_huffman(nodo *root, ulong arr[], ulong top, vector<caracter> &caracteres_huffman)
{

	if (root->left)
	{
		arr[top] = 0;
		obtener_largos_huffman(root->left, arr, top + 1, caracteres_huffman);
	}

	if (root->right)
	{
		arr[top] = 1;
		obtener_largos_huffman(root->right, arr, top + 1, caracteres_huffman);
	}
	if (isLeaf(root))
	{
		caracter let;
		let.id = root->id;
		//cout << root->id << "  | ";
		string letra_code = printArray(arr, top);
		let.largo = letra_code.size();
		let.freq = root->freq;
		caracteres_huffman.push_back(let);
	}
}

// Print the array
string printArray(ulong arr[], ulong n)
{
	string letra_code;
	for (uint i = 0; i < n; ++i)
	{
		//cout << arr[i];
		letra_code += to_string(arr[i]);
	}
	//cout << "\n";
	return letra_code;
}

// Quicksort para ordenar las caracteres por largo de la codificacion de huffman (Árbol)
long int partition(vector<caracter> &A, long int l, long int r)
{
	long int p = l;
	long int pv = A[p].largo;
	for (uint i = l + 1; i <= r; ++i)
	{
		if (A[i].largo < pv)
		{
			swap(A[i], A[p + 1]);
			++p;
		}
	}
	swap(A[l], A[p]);
	return p;
}
void quickSort(vector<caracter> &A, long int l, long int r)
{
	if (l < r)
	{
		long int p = partition(A, l, r);
		quickSort(A, l, p - 1);
		quickSort(A, p + 1, r);
	}
}

//Obtencion de la secuencia S del archivo
uchar *readText(char file[400], vector<nodo> &caracteres)
{
	uchar *seq; // secuencia (1 byte por caracter)
	uint n;		// largo de la secuencia
	n = file_size(file);
	cout << "Largo de S es : " << n << endl;
	seq = new uchar[n];
	FILE *f = fopen(file, "r");
	read_from_file(seq, n, f);
	for (uint i = 0; i < n; ++i)
	{
		buscar_agregar_vector(seq[i], caracteres);
		//cout << seq[i];
	}
	fclose(f);
	return seq;
}

void buscar_agregar_vector(uchar n, vector<nodo> &caracteres)
{
	bool esta = false;
	ulong j = 0;
	while (!(esta) && j < caracteres.size())
	{
		if (n == caracteres[j].id)
		{
			++caracteres[j].freq;
			esta = true;
		}
		else
			++j;
	}
	if (esta == false)
	{
		nodo *caracter = new nodo(n, 1);
		caracteres.push_back((*caracter));
	}
}

//Files
FILE *file_open(string filename, string mode)
{
	FILE *f = fopen(filename.c_str(), mode.c_str());
	if (f == NULL)
	{
		cout << filename.c_str() << " NULL !!" << endl;
		exit(EXIT_FAILURE);
	}
	return f;
}

uint file_size(string filename)
{
	FILE *f = file_open(filename, "r");
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	if (size < 0)
	{
		cout << filename.c_str() << " no size !!" << endl;
		exit(EXIT_FAILURE);
	}
	fclose(f);
	return (uint64_t)size;
}

void read_from_file(uchar *dest, uint n, FILE *f)
{
	uint fread_ret = fread(dest, sizeof(uchar), n, f);
	if (fread_ret != n)
	{
		cout << "Error: fread failed" << endl;
		exit(EXIT_FAILURE);
	}
}

//Convertores
void to_bin(ulong num, ulong base_ini, ulong base_fin, caracter &a, ulong min)
{
	a.code_dec = num;
	bool *canonic_code = new bool[64];
	ulong digito;
	ulong i = 0;
	while ((ulong)(num != 0))
	{
		digito = (ulong)(num % base_fin);
		canonic_code[i] = digito;
		num = (ulong)(num / base_fin);
		++i;
	}
	while (i < min)
	{
		canonic_code[i] = 0;
		i++;
	}
	
	ulong j = 0;
	ulong r = i - 1;

	while (j <= r)
	{
		swap(canonic_code[j], canonic_code[r]);
		--r;
		++j;
	}
	a.code = canonic_code;
	a.largo = i;
}
ulong to_dec(bool *A, ulong l, ulong r)
{
	ulong dec = 0;
	ulong j = r - l - 1;
	//cout << "J es: " << j << " ";
	for (uint i = l; i < r; i++)
	{
		dec += A[i] * pow(2, (j));
		j--;
	}
	return dec;
}
void process_mem_usage(double &vm_usage, double &resident_set)
{
	vm_usage = 0.0;
	resident_set = 0.0;

	// the two fields we want
	unsigned long vsize;
	long rss;
	{
		std::string ignore;
		std::ifstream ifs("/proc/self/stat", std::ios_base::in);
		ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> vsize >> rss;
	}

	long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
	vm_usage = vsize / 1024.0;
	resident_set = rss * page_size_kb;
}