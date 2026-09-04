#include <iostream>
#include <chrono>
#include <list>
#include <cmath>

//FUNÇÃO QUE ENCONTRA SE É PRIMO
int primo(int n_analisado, int n_divisor = 2, bool nao_primo = false) {

    //VERIFICA SE HÁ ALGUM DIVISOR ENTRE 1 E O NÚMERO
    for (n_divisor = 2; n_divisor < n_analisado; n_divisor++){

        if (n_analisado % n_divisor == 0) {
            nao_primo = true;
            break;
        }

    }

    //PULA PARA O PRÓXIMO NÚMERO CASO O ATUAL SEJA PRIMO
    if (nao_primo == true) {
        return 0;
    } 
    
    else {
        return 1;
    }

}

//FUNÇÃO QUE VERIFICA SE É PRIMO DE MERSENNE
int primo_mersenne(int n_analisado, std :: list <int> n_primos) {

    for (int n : n_primos) {

        if (std :: pow(2, n) - 1 == n_analisado) {

            return 1;

        }
    }

    return 0;
}

int main() {

    //MARCA O TEMPO EXATO
    auto inicio = std :: chrono :: steady_clock :: now();

    int num_analisado;

    //DEFINE UMA LISTA ONDE SERÃO ARMAZENADOS OS PRIMOS
    std :: list <int> primos = {2};

    //VERIFICAR SE UM NÚMERO É PRIMO:
    for (num_analisado = 2; num_analisado <= 524287; num_analisado++){

        //FUNÇÃO QUE VERIFICA SE O NÚMERO É PRIMO
        int resp = primo(num_analisado);

        if (resp == 0) {
            continue;
        } 

        else {

            //ADICIONA O PRIMO EM UMA LISTA
            primos.push_back(num_analisado);

            //VERIFICA SE O PRIMO É PRIMO DE MERSENNE
            int resp2 = primo_mersenne(num_analisado, primos);

            if (resp2 == 1) {
                std :: cout << num_analisado << " é um primo de mersenne!" << std :: endl;
            }

        }
    }

    //MARCA O TEMPO EXATO
    auto fim = std :: chrono :: steady_clock :: now();

    //CONTA E PRINTA O TEMPO
    auto duracao = std :: chrono :: duration_cast < std :: chrono :: milliseconds > (fim - inicio);
    std :: cout << "O tempo de execução em milisegundos foi: " << duracao.count() << " ms" << std :: endl;


}