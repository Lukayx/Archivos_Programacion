/*
 * ******** Pregunta Q2 GPU CUDA (3.0 pts) ********
 * El siguiente programa es un 'molde' para un automata celular simulado en GPU. Un automata celular es un sistema dinamico 
 * donde cada celda obedece a una regla fija que involucra una operacion con el valor de las celdas vecinas. En este caso, 
 * el molde esta hecho para un automata celular en 2-dimensiones, donde cada celda tiene un estado de 0 o 1. Para conocer 
 * el estado siguiente (en el tiempo t+1) de una celda, se debe leer los estados de ella misma y los de la vencidad, y 
 * realizar una operacion. Esto debe hacerse en cada celda simultaneamente, por esa razon es que se trabaja con dos 
 * punteros para evitar problemas de concurrencia.
 * Puede probar ejecutando el programa con ./q2 32 8 32 17 1000 0.137
 *    
 * a) (1.5 pts) Implemente el automata celular del juego de la vida en GPU. Este automata celular tiene las siguientes reglas:
 *      - Cada celda puede tener un estado muerto (0) o vivo (1).
 *      - Para cada celda:
            - Si esta viva y tiene dos o tres vecinos vivos --> VIVE AL PASO SIGUIENTE
            - Si esta muerta y tiene 3 vecinos vivos --> VIVE AL PASO SIGUIENTE
            - Cualquier otro caso --> MUERE AL PASO SIGUIENTE

            A B C
            D E F  procesar E --> vecinos son A B C D F G H I
            G H I
        - Las condiciones de borde son periodicas, es decir el vecino del extremo derecho es el del extremo izquierdo y 
          vice-versa. Lo mismo de forma vertical.

 * b) (1.5 pts) Mida el tiempo promedio de un paso de simulacion con n=8192 y prob=0.13 usando los tamanos de bloque: {1, 2, 4, 8, 16, 32}. 
        - Haga un grafico con tiempo (Y) vs tamano-bloque (X). ¿Que puede concluir del efecto del tamano del bloque en el rendimiento de la GPU?
 */

#include <cuda.h>
#include <cstdlib>
#include <cstdio>
#include <omp.h>
#include "tools.h"


// TRABAJAR AQUI
__global__ void kernel_CA(int n, int *in, int *out){
    // **********************************
    // a) ESCRIBA SU SOLUCION AQUI
    // **********************************


    // HELP1: para acceder a la posicion (x,y) debe usar la forma [y*n + x]
    // HELP2: almacene las posiciones de derecha x+1, izq x-1, abajo y+1 y arriba y-1, antes de combinarlas. Asi las esquinas se construyen mas facil.
    // HELP3: recuerde que son condiciones periodicas. La operaciones modulo puede servirle para tratar bien x+1, y+1, pero para x-1, y-1 
    //        hagalo con  condicional.
}



// IGNORAR 
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess)
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}


int main(int argc, char **argv){
    if(argc != 7){
        fprintf(stderr, "ejecutar como ./q2 n nt B seed steps prob\n\n");
        exit(EXIT_FAILURE);
    }
    // args
    int n       = atoi(argv[1]);
    int nt      = atoi(argv[2]);
    int B       = atoi(argv[3]);
    int seed    = atoi(argv[4]);
    int steps   = atoi(argv[5]);
    float prob  = atof(argv[6]);
    omp_set_num_threads(nt);
    printf("n=%i  B=%i  steps=%i\n", n, B, steps);
    
    // creando datos
    int *d1, *d2;
    int *A = new int[n*n];
    float timems;
    init_prob(n, A, 13, prob);
    gpuErrchk(cudaMalloc(&d1, sizeof(int)*n*n));
    gpuErrchk(cudaMalloc(&d2, sizeof(int)*n*n));
    gpuErrchk(cudaMemcpy(d1, A, sizeof(int)*n*n, cudaMemcpyHostToDevice));

    // ejecucion
    print_mat(n, A, "INPUT");
    printf("Press Enter...\n"); fflush(stdout); getchar();
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    dim3 block(B,B,1);
    dim3 grid((n+B-1)/B, (n+B-1)/B, 1);
    for(int i=0; i<steps; ++i){
        printf("Simulacion step=%i........", i);
        cudaEventRecord(start);

        // llamada al kernel
        kernel_CA<<<grid, block>>>(n, d1, d2);
        gpuErrchk( cudaPeekAtLastError() );
        gpuErrchk( cudaDeviceSynchronize() );

        // tiempo 
        cudaEventRecord(stop);
        cudaEventSynchronize(stop);
        cudaEventElapsedTime(&timems, start, stop);
        printf("done: %f\n", timems/1000.0);

        // copiar y mostrar
        gpuErrchk(cudaMemcpy(A, d2, sizeof(int)*n*n, cudaMemcpyDeviceToHost));
        print_mat(n, A, "Estado del automata celular");
        printf("Press Enter...\n"); fflush(stdout); getchar();
        std::swap(d1, d2);
    }
}
