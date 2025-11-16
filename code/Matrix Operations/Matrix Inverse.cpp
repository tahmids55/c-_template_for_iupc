#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<double>> matrixInverse(vector<vector<double>> matrix) {
    int n = matrix.size();
    vector<vector<double>> inverse(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) inverse[i][i] = 1;

    for (int i = 0; i < n; i++) {
        double pivot = matrix[i][i];
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }
        for (int k = 0; k < n; k++) {
            if (k != i && matrix[k][i] != 0) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }
    return inverse;
}

int main() {
    vector<vector<double>> matrix = {{4, 7}, {2, 6}};
    vector<vector<double>> inv = matrixInverse(matrix);
    cout << "Inverse matrix:" << endl;
    for (auto row : inv) {
        for (double val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}