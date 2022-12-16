#include <iostream>
#include <vector>
#include <omp.h>
#include <time.h>
//set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")
using namespace std;
const int N { 10000 };

template <typename T>
vector<vector<T>> MatrixMultiplication(vector<vector<T>> A, vector<vector<T>> B){
    vector<vector<T>> result(N, vector<T>(N));


    int threads = 8;
    omp_set_num_threads(threads);
    int i, j, k;

#pragma omp parallel for shared(A, B, result) private(i, j, k)
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
            result[i][j] = 0;
            for (k = 0; k < N; k++)
                result[i][j] += A[i][k] * B[k][j];
        }

    return result;
}

template <typename T>
void PrintMatrix(const vector< vector<T>> & matrix) {
    for(const auto& row : matrix) {
        for (auto elem: row)
            cout<<elem<<", ";
        cout<<endl;
    }
    cout<<endl;
}

template <typename T>
vector<vector<T>> randomMatrix() {
    vector<vector<T>> result(N, vector<T>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = rand() % 15;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> A = randomMatrix<int>();
    vector<vector<int>> B = randomMatrix<int>();

    clock_t start = clock();
    vector<vector<int>> result = MatrixMultiplication<int>(A, B);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    //PrintMatrix<int>(result);


    return 0;
}
