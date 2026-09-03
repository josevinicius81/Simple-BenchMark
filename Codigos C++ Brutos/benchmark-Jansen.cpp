#include <iostream>
#include <cmath>
#include <chrono>

long double fat(int num){
    if (num <= 1){
        return 1.0;
    } else {
        return num * fat(num - 1);
    }
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    long double result1, result2, result3, result4, result5, result6, result7, result8, result9;
    int i, j, k;

    for (i = 0; i <= 2008; ++i){
        
        for (j = 0; j <= 1754; ++j){    //máximo j no qual seu fatorial cabe no long double
            result1 = fat(j);

            result2 = std::sqrt(j);

            result3 = std::sin(j);

            result4 = std::cos(j);

            result5 = result3 * result4;

            for (k = 0; k <= 100; ++k){
                result6 = std::pow(j, k);
                result7 = std::pow(result2, k);
                result8 = std::pow(result3, k);
                result9 = std::pow(result4, k);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tempo de execução: " << duration.count() << " ms" << std::endl;

    return 0;
}