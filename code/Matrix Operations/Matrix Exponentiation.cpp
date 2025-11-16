#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
    int size;
    vector<vector<long long>> mat;

    Matrix(int n) : size(n), mat(n, vector<long long>(n)) {}

    static Matrix identity(int n) {
        Matrix I(n);
        for (int i = 0; i < n; i++) I.mat[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    Matrix pow(long long exp) const {
        Matrix result = identity(size);
        Matrix base = *this;
        while (exp) {
            if (exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};

int main() {
    Matrix fib(2);
    fib.mat = {{1, 1}, {1, 0}};
    Matrix res = fib.pow(10);
    cout << "Fibonacci(10): " << res.mat[0][1] << endl; // Output: 55
    return 0;
}