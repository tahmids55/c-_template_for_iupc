#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0), result;
    queue<int> q;
    
    for (int u = 0; u < V; u++)
        for (int v : adj[u]) inDegree[v]++;
    
    for (int u = 0; u < V; u++)
        if (inDegree[u] == 0) q.push(u);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u);
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) q.push(v);
        }
    }
    return result;
}

int main() {
    int V = 4;
    vector<vector<int>> adj = {{1, 2}, {3}, {3}, {}};
    vector<int> order = topologicalSort(V, adj);
    for (int u : order) cout << u << " "; // Output: 0 1 2 3
    return 0;
}