#include <iostream>
#include <chrono>
#include <list>
#include <cmath>
#include <vector>
#include "algoritmo1.h"
#include "algoritmo2.h"
#include "algoritmo3.h"

int main() {

    int temp_algoritmo1 = algoritmo1();
    std :: cout << "O tempo para encontrar 7 números primos de Mersenne foi: " << temp_algoritmo1 << " ms" << std :: endl;

    int temp_algoritmo2 = algoritmo2();
    std :: cout << "O tempo para criar e multiplicar duas matrizes 2048x2048 foi: " << temp_algoritmo2 << " ms" << std :: endl;

    int temp_algoritmo3 = algoritmo3();
    std :: cout << "O tempo para encontrar 50 números da sequência de fibonacci foi de: " << temp_algoritmo3 << " ms" << std :: endl;

}