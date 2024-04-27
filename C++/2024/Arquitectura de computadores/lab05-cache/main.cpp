#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <string>
#include <ctime>
void gap_sum(int array[], int n , int gap);
void imprime_array (int *array, int n);

int main(int argc, char **argv){
  if (argc < 3){
    std::cout << "solo hay 1 argumento, por favor ingrese 2" << std::endl;
    exit(EXIT_FAILURE);
  }
  double t1 = omp_get_wtime();
  srand(time(0));
  int n = stoi(std::string(argv[1]));
  int gap = stoi(std::string(argv[2]));
  n = n + (n-1)*gap;
  int *array = new int[n];
  int i = 0;
  int rango_min = 1;
  int rango_max = 100;
  while(i < n){
    int numero_aleatorio = rand() % (rango_max - rango_min + 1) + rango_min +1;
    array[i] = numero_aleatorio;
    i++;
    int j = 0;
    while(j < gap && (i+j) < n){
      array[i+j] = 0;
      j++;
    }
    i += gap;
  }
  imprime_array(array, n);
  gap_sum(array, n, gap);
  double t2 = omp_get_wtime();
  double tiempo = t2 - t1;
  std::cout << "El tiempo es: " << tiempo << std::endl;
}

void gap_sum(int *array, int n , int gap){
  int sum = 0;
  int i = 0;
  while(i < n){
    sum += array[i];
    i += gap + 1;
  }
  std::cout << "La suma de los valores del arreglo es: " << sum << std::endl;
}

void imprime_array (int *array, int n){
    for (int i = 0; i < n; i++){
    std::cout << array[i] << ",";
  }
  std::cout << std::endl;
}