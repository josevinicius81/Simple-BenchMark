#ifndef ALGORITMO_6
#define ALGORITMO_6

using namespace std;

unsigned long long calcular_total_combinacoes(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    
    unsigned long long resultado = 1;
    for (int i = 1; i <= k; ++i) {
        resultado *= (n - i + 1);
        resultado /= i;
    }
    return resultado;
}

unsigned long long rodar_benchmark_combinacoes(int n, int k) {
    if (k > n || k <= 0) return 0;

    // Criando um vetor de inteiros simples para simular os elementos
    vector<int> elementos(n);
    for(int i = 0; i < n; ++i) elementos[i] = i;

    vector<int> mascara(n, 0);
    fill(mascara.begin(), mascara.begin() + k, 1);

    unsigned long long total_processado = 0;
    
    do {
        for (int i = 0; i < n; ++i) {
            if (mascara[i] == 1) {
                int dummy = elementos[i];
                (void)dummy;
            }
        }
        total_processado++;
    } while (prev_permutation(mascara.begin(), mascara.end()));

    return total_processado;
}

int algoritmo6() {
    int n = 32; 
    int k = 16; 
    
    unsigned long long total_esperado = calcular_total_combinacoes(n, k);

    auto inicio = chrono::high_resolution_clock::now();

    unsigned long long total_calculado = rodar_benchmark_combinacoes(n, k);

    auto fim = chrono::high_resolution_clock::now();

    auto duracao = chrono::duration_cast<chrono::milliseconds>(fim - inicio).count();

    return duracao;
}

#endif