/*
 * ******** Pregunta Q1 OPENMP (3.0 pts) ********
 *
 * a) (0.5 pt) Compile y ejecute el programa por ejemplo asi: ./prog 32 1 0
 *    Pruebe distintos tamaños de problema y explique:
 *      - ¿Qué es lo que hace el programa?
 *      - ¿Qué significan los argumentos? 
 *      - ¿A partir de cual "n" la ejecucion toma 1 o mas segundos en modo secuencial?
 *
 * b) (1.5 pt) Programe una version paralela en el espacio de la funcion "parallel_prefix_sum".
 *             Explique claramente su estrategia y como se logra acelerar.
 *
 * c) (1.0 pt) Calcule el tiempo de su nueva solucion usando {1, 2, 4, 8} threads y grafique 
 *             las curvas de speedup y la eficiencia vistas en clases.
 */

#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include <string>
#include "tools.h"

using namespace std;

void parallel_prefix_sum(long n, long *array, long *ps){
    // **********************************
    // ESCRIBA SU SOLUCION AQUI
    // **********************************
     
}

void prefix_sum(long n, long *array, long *ps){
    long res = 0;
    for(int i=0; i<n; ++i){
        ps[i] = res + array[i];
        res += array[i];
    }
}

int main(int argc, char **argv){
    if(argc != 4){
        fprintf(stderr, "ejecutar como ./prog n nt modo\nn: numero de elementos\nnt: numero de threads\nmodo: (0:secuencial, 1:paralelo)\n");
        exit(EXIT_FAILURE);
    } 
    // ARGUMENTOS
    double t1;
    const char* mmap[2] = {"secuencial", "paralelo"};
    long n = atoi(argv[1]);
    int nt = atoi(argv[2]);
    long mode = atoi(argv[3]);
    omp_set_num_threads(nt);
    printf("n=%lu  nt=%i  m=%i -> (%s)\n", n, nt, mode, mmap[mode]);

    // CREACION DATOS
    long *X = new long[n];
    long *PS = new long[n];
    printf("Inicializando X................."); fflush(stdout);
    t1 = omp_get_wtime(); 
    init_array_i(n, X);
    printf("done: %f secs\n", omp_get_wtime()-t1); fflush(stdout);

    // CALCULO
    printf("Prefix sum (%-10s).........", mmap[mode]); fflush(stdout);
    t1 = omp_get_wtime(); 
    if(mode==0){
        prefix_sum(n, X, PS);
    }    
    else{
        parallel_prefix_sum(n, X, PS);
    }
    
    // OUTPUT FINAL (SE IMPRIME SOLO SI N ES PEQUENO (<= 32))
    printf("done: %f secs\n", omp_get_wtime()-t1); fflush(stdout);
    print_array(n, X, "Input");
    print_array(n, PS, "Output");
}
