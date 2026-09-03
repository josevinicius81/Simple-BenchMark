#ifndef ALGORTIMO_2
#define ALGORITMO_2

int algoritmo2() {
    
    int N=2048;
    std::vector <std::vector<long long>> MatrizA(N,std::vector<long long>(N));
    std::vector <std::vector<long long>> MatrizB(N,std::vector<long long>(N));
    std::vector <std::vector<long long>> MatrizC(N,std::vector<long long>(N,0));
    long long k=1;
    long long f=k*2;
    
    auto inicio = std::chrono::high_resolution_clock::now();
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            MatrizA[i][j]=k;
            MatrizB[i][j]=f;
            k++;
            f=k*2;
        }
    }

    

    for(int l=0;l<N;l++){
        for(int m=0;m<N;m++){
            for(int n=0;n<N;n++){
                MatrizC[l][m]+=MatrizA[l][n]*MatrizB[n][m];
            }
        }
    }

    auto fim = std::chrono::high_resolution_clock::now();

    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    return tempo.count();
}

#endif