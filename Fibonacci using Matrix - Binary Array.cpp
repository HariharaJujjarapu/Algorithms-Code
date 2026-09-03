// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>> A, vector<vector<int>> B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<int>> C(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int findFibonacci(vector<int> N){
    vector<vector<int>> A = {{1, 1}, {1, 0}};
    vector<vector<int>> Y =  {{1, 0}, {0, 1}};
    int i = 0; 
    
    while(i < N.size()){
        if(N[i])
            Y = multiplyMatrices(Y, A);
        A =  multiplyMatrices(A, A);
        i++;
    }
    
    return Y[1][0];
}

int main() {
    vector<int> N = {0, 1, 0, 1};
    cout << "Nth Fibonacci Number is : " << findFibonacci(N);
    return 0;
}