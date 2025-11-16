#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortestPath(int u, int n, vector<vector<int>>& graph, vector<int>& memo) {
    if (u == n - 1) return 0;
    if (memo[u] != -1) return memo[u];
    int ans = INT_MAX;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] != INT_MAX) {
            ans = min(ans, shortestPath(v, n, graph, memo) + graph[u][v]);
        }
    }
    return memo[u] = ans;
}

int main() {
    int n = 4;
    vector<vector<int>> graph = {{0, 1, 4, INT_MAX},
                                {INT_MAX, 0, 2, 6},
                                {INT_MAX, INT_MAX, 0, 1},
                                {INT_MAX, INT_MAX, INT_MAX, 0}};
    vector<int> memo(n, -1);
    cout << "Shortest path from 0 to 3: " << shortestPath(0, n, graph, memo) << endl; // Output: 4
    return 0;
}