#include <iostream>
#include <vector>
using namespace std;

class PrefixSum2D {
    vector<vector<int>> prefix;
public:
    PrefixSum2D(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + 
                              prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - 
               prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    PrefixSum2D ps(matrix);
    cout << "Sum from (1,1) to (2,2): " << ps.sumRegion(1, 1, 2, 2) << endl; // Output: 28
    return 0;
}