#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int recursaocaminhos(int i, int j, int linhas, int colunas, const vector<vector<int>>& matriz, vector<vector<int>> matrizcheck, 
                        vector<pair<int, int>>& caminho_atual, vector<vector<pair<int, int>>>& todos_caminhos) {
    
    caminho_atual.push_back({i, j});
    matrizcheck[i][j] = true;
    int total_caminhos = 0;

    if ((i == linhas - 1) && (j == colunas - 1)) {
        todos_caminhos.push_back(caminho_atual);
        
        if (todos_caminhos.size() >= 500000) {
            todos_caminhos.clear();
            todos_caminhos.shrink_to_fit();
        }
        total_caminhos = 1;
    } else {
        if ((j >= 1) && (!matrizcheck[i][j - 1])) {
            total_caminhos += recursaocaminhos(i, j - 1, linhas, colunas, matriz, matrizcheck, caminho_atual, todos_caminhos);
        }
        if ((j < colunas - 1) && (!matrizcheck[i][j + 1])) {
            total_caminhos += recursaocaminhos(i, j + 1, linhas, colunas, matriz, matrizcheck, caminho_atual, todos_caminhos);
        }
        if ((i >= 1) && (!matrizcheck[i - 1][j])) {
            total_caminhos += recursaocaminhos(i - 1, j, linhas, colunas, matriz, matrizcheck, caminho_atual, todos_caminhos);
        }
        if ((i < linhas - 1) && (!matrizcheck[i + 1][j])) {
            total_caminhos += recursaocaminhos(i + 1, j, linhas, colunas, matriz, matrizcheck, caminho_atual, todos_caminhos);
        }
    }

    caminho_atual.pop_back();

    return total_caminhos;
}

int main() {
    int linhas = 7;
    int colunas = 6;
    int numero_exec = 7;

    for (int i = 1; i <= numero_exec; ++i){
        vector<vector<int>> matriz(linhas, vector<int>(colunas, 0));
        vector<vector<int>> matrizcheck(linhas, vector<int>(colunas, false));

        vector<pair<int, int>> caminho_atual;
        vector<vector<pair<int, int>>> todos_caminhos;

        auto inicio = chrono::high_resolution_clock::now();

        int caminhos = recursaocaminhos(0, 0, linhas, colunas, matriz, matrizcheck, caminho_atual, todos_caminhos);

        auto fim = chrono::high_resolution_clock::now();

        auto duracao_ms = chrono::duration_cast<chrono::milliseconds>(fim - inicio).count();
        chrono::duration<double> duracao_s = fim - inicio;

        cout << "===Resultado do Benchmark===" << endl;
        cout << "A quantidade de caminhos encontrados foi: " << caminhos << endl;
        cout << "Tempo de execucao: " << duracao_ms << " ms (" << duracao_s.count() << " segundos)" << endl;
        
    }

    return 0;
}