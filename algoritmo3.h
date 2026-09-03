#ifndef ALGORITMO_3
#define ALGORITMO_3

//Recursão para calcular Fibonacci
long long fibonacciRecursivo(int n);

int algoritmo3() { 
    

    //Marca o tempo exato
    auto inicio = std::chrono::high_resolution_clock::now();

    //Calcular as 50 primeiras posições de fibonacci
    for (int i = 0; i <= 49; i++) {
        // O 'volatile' obriga a CPU a executar a conta em todos os ciclos
        volatile long long resultado = fibonacciRecursivo(i);
        resultado += 0;
    }

    auto fim = std::chrono::high_resolution_clock::now();

    //Calcula a duração total e converte para milissegundos
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    return tempo.count();
}


long long fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    //chama para calcular os dois anteriores 
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

#endif