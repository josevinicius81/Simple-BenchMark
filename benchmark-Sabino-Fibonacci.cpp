#include <iostream>
#include <chrono>

//Recursão para calcular Fibonacci
long long fibonacciRecursivo(int n) ;

int main() { 
    

    //Marca o tempo exato
    auto inicio = std::chrono::steady_clock::now();

    //Calcular as 50 primeiras posições de fibonacci
    for (int i = 0; i <= 50; i++) {
        // O 'volatile' obriga a CPU a executar a conta em todos os ciclos
        volatile long long resultado = fibonacciRecursivo(i);
        std::cout << i << "º número " << resultado << std::endl;
    }

    
    auto fim = std::chrono::steady_clock::now();

    //Calcula a duração total e converte para milissegundos
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim-inicio);
    std::cout << "Tempo total gasto: " << duracao.count() << " milissegundos.\n";

    std::cout << "Tempo total gasto em segundos: " << std::chrono::duration_cast<std::chrono::duration<double>>(duracao).count() << "s.\n";


    return 0;
}


long long fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    //chama para calcular os dois anteriores 
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}