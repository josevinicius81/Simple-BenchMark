#include <iostream>
#include <chrono>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>
#include "algoritmo1.h"
#include "algoritmo2.h"
#include "algoritmo3.h"
#include "algoritmo4.h"
#include "algoritmo5.h"
#include "algoritmo6.h"

int main() {

    //MARCA O TEMPO EXATO
    auto inicio_total = std::chrono::high_resolution_clock::now();

    int temp_algoritmo1 = algoritmo1();
    std :: cout << "O tempo para encontrar 7 números primos de Mersenne foi: " << temp_algoritmo1 << " ms" << std :: endl;

    int temp_algoritmo2 = algoritmo2();
    std :: cout << "O tempo para criar e multiplicar duas matrizes 2048x2048 foi: " << temp_algoritmo2 << " ms" << std :: endl;

    int temp_algoritmo3 = algoritmo3();
    std :: cout << "O tempo para encontrar a quantidade de caminhos em uma matriz 7x6 foi: " << temp_algoritmo3<< " ms" << std :: endl;

    int temp_algoritmo4 = algoritmo4();
    std :: cout << "O tempo para encontrar 50 números da sequência de fibonacci foi de: " << temp_algoritmo4 << " ms" << std :: endl;

    int temp_algoritmo5 = algoritmo5();
    std :: cout << "O tempo para realizar uma quantidade enorme de operações matemáticas foi: " << temp_algoritmo5 << " ms" << std :: endl;

    int temp_algoritmo6 = algoritmo6();
    std :: cout << "O tempo para encontrar a quantidade de combinações entre 32 e 16 elementos foi: " << temp_algoritmo6 << " ms" << std :: endl;

    auto fim_total = std::chrono::high_resolution_clock::now();
    auto duracao_total = std::chrono::duration_cast<std::chrono::milliseconds>(fim_total - inicio_total);
    std :: cout << "O tempo total de execução foi: " << duracao_total.count() << " ms" << std :: endl;

}