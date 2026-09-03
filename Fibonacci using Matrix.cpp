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

int findFibonacci(int n){
    vector<vector<int>> A = {{1, 1}, {1, 0}};
    vector<vector<int>> Y =  {{1, 0}, {0, 1}};
    
    while(n > 0){
        if(n % 2 == 1)
            Y = multiplyMatrices(Y, A);
        A =  multiplyMatrices(A, A);
        n /= 2;
    }
    
    return Y[1][0];
}

int main() {
    int n ;
    cin >> n;
    cout << "Enter n value : " << n << endl;
    cout << "Nth Fibonacci Number is : " << findFibonacci(n);
    return 0;
}