#ifndef ALGORITMO_1
#define ALGORITMO_1

//ESTE CÓDIGO ESCONTRA 7 NÚMEROS PRIMOS DE MERSENNE

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
void primo_mersenne(int n_analisado, std :: list <int> n_primos) {

    for (int n : n_primos) {

        if (std :: pow(2, n) - 1 == n_analisado) {

            return;

        }
    }

    return;
}

//FUNÇÃO PRINCIPAL
int algoritmo1() {

    //MARCA O TEMPO EXATO
    auto inicio = std::chrono::high_resolution_clock::now();

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
            primo_mersenne(num_analisado, primos);

        }
    }

    //MARCA O TEMPO EXATO
    auto fim = std::chrono::high_resolution_clock::now();

    //CONTA E PRINTA O TEMPO
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    return tempo.count();

}

#endif