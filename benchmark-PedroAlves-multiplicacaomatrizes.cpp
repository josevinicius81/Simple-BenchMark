#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int main() {
    
    int N=2048;
    vector <vector<long long>> MatrizA(N,vector<long long>(N));
    vector <vector<long long>> MatrizB(N,vector<long long>(N));
    vector <vector<long long>> MatrizC(N,vector<long long>(N,0));
    long long k=1;
    long long f=k*2;
    
    auto inicio = chrono::high_resolution_clock::now();
    
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

    auto fim = chrono::high_resolution_clock::now();

    auto tempo = chrono::duration_cast<chrono::milliseconds>(fim - inicio);

    cout<<MatrizC[0][0]<<endl;
    cout << "Tempo: " << tempo.count() << " ms" << endl;

    return 0;
}