#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <omp.h>

// **************** COMPLETAR *****************
#define BX 8
#define BY 8
#define BZ 8
// ********************************************

// Filtro Gaussiano CUDA
__global__ void kernelFG(float *input, float *output, int width, int height, int depth) {
    // **************** COMPLETAR *****************
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    int idy = threadIdx.y + blockIdx.y * blockDim.y;
    int idz = threadIdx.z + blockIdx.z * blockDim.z;

    if (idx < width && idy < height && idz < depth) {
        long index = (long)idz * width * height + idy * width + idx;
        float sum = 0.0f;
        int count = 0;

        for (int z = -1; z <= 1; ++z) {
            for (int y = -1; y <= 1; ++y) {
                for (int x = -1; x <= 1; ++x) {
                    int nx = idx + x;
                    int ny = idy + y;
                    int nz = idz + z;

                    if (nx >= 0 && ny >= 0 && nz >= 0 && nx < width && ny < height && nz < depth) {
                        long neighborIndex = (long)nz * width * height + ny * width + nx;
                        sum += input[neighborIndex];
                        count++;
                    }
                }
            }
        }
        output[index] = sum / count;
    }
    // ********************************************
}

// Filtro Gaussiano OpenMP
void openmpFG(float *input, float *output, int width, int height, int depth) {
    // **************** COMPLETAR *****************
    #pragma omp parallel for
    for (int z = 0; z < depth; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int index = z * width * height + y * width + x;
                float sum = 0.0f;
                int count = 0;

                for (int dz = -1; dz <= 1; ++dz) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        for (int dx = -1; dx <= 1; ++dx) {
                            int nx = x + dx;
                            int ny = y + dy;
                            int nz = z + dz;

                            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < width && ny < height && nz < depth) {
                                int neighborIndex = nz * width * height + ny * width + nx;
                                sum += input[neighborIndex];
                                count++;
                            }
                        }
                    }
                }
                output[index] = sum / count;
            }
        }
    }
    // ********************************************
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "Ejecutar como: "<< argv[0] << " <width> <height> <depth> <nt>" << std::endl;
        return 1;
    }

    // Recibir argumentos
    const int width = std::atoi(argv[1]);
    const int height = std::atoi(argv[2]);
    const int depth = std::atoi(argv[3]);
    const int nt    = std::atoi(argv[4]);
    const long size = (long)width * (long)height * (long)depth;

    printf("\n");
    printf("Matrix de width=%i x height=%i x depth=%i\n", width, height, depth);
    printf("Bloques CUDA de %i x %i x %i\n", BX, BY, BZ);
    printf("OpenMP Threads = %i\n\n", nt);
    printf("VRAM GPU: %f GB\n", (double)size * sizeof(float) * 2.0 / 1e9);
    printf("RAM  CPU: %f GB\n\n", (double)size * sizeof(float) * 3.0 / 1e9);

    float *input = new float[size];
    float *output_CUDA = new float[size];
    float *output_OpenMP = new float[size];

    // Inicializar datos
    printf("Inicializando matrix 3D..........."); fflush(stdout);
    for (long i = 0; i < size; ++i) {
        input[i] = static_cast<float>(rand()) / RAND_MAX;
    }
    printf("listo\n"); fflush(stdout);



    // **************** COMPLETAR *****************
    // configuracion de grid CUDA
    dim3 blockDim(BX, BY, BZ);
    dim3 gridDim((width + BX - 1)/BX, (height + BY - 1) / BY, (depth + BZ - 1)/BZ);
    // ********************************************

    // alocar memoria GPU
    float *d_input, *d_output;
    cudaMalloc((void**)&d_input, size * sizeof(float));
    cudaMalloc((void**)&d_output, size * sizeof(float));

    // Copiar datos de Host a Device
    cudaMemcpy(d_input, input, size * sizeof(float), cudaMemcpyHostToDevice);

    // Herramientas CUDA para medir tiempo
    cudaEvent_t start_CUDA, stop_CUDA;
    cudaEventCreate(&start_CUDA);
    cudaEventCreate(&stop_CUDA);

    // Ejecutar Kernel GPU
    printf("Ejecutando Kernel................."); fflush(stdout);
    cudaEventRecord(start_CUDA);
    kernelFG<<<gridDim, blockDim>>>(d_input, d_output, width, height, depth);
    printf("listo: "); fflush(stdout);

    // Terminar de medir tiempo
    cudaEventRecord(stop_CUDA);
    cudaEventSynchronize(stop_CUDA);
    float cuda_time = 0;
    cudaEventElapsedTime(&cuda_time, start_CUDA, stop_CUDA);
    std::cout << cuda_time/1000.0f << " secs" << std::endl;

    // Copiar resultado de vuelta a Host
    cudaMemcpy(output_CUDA, d_output, size * sizeof(float), cudaMemcpyDeviceToHost);




    // OPENMP
    omp_set_num_threads(nt);
    printf("Ejecutando OpenMP................."); fflush(stdout);
    double start_OpenMP = omp_get_wtime();
    // Ejecutar funcion OpenMP
    openmpFG(input, output_OpenMP, width, height, depth);
    printf("listo: "); fflush(stdout);
    double end_OpenMP = omp_get_wtime();
    double openmp_time = end_OpenMP - start_OpenMP;
    std::cout << openmp_time << " secs" << std::endl;





    // Comparar resultados entre CPU y GPU 
    printf("Comparando Resultados CPU/GPU....."); fflush(stdout);
    bool coinciden = true;
    for (long i = 0; i < size; ++i) {
        if (std::fabs(output_CUDA[i] - output_OpenMP[i]) > 1e-5) {
            std::cerr << "Error!" << std::endl;
            coinciden = false;
            break;
        }
    }
    if(coinciden){
        printf("coinciden\n"); fflush(stdout);
    }

    // Liberar memoria
    delete[] input;
    delete[] output_CUDA;
    delete[] output_OpenMP;
    cudaFree(d_input);
    cudaFree(d_output);

    return 0;
}

