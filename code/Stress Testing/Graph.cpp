#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int n = 10 + rand() % 10;  // 10–19 nodes
    int m = n - 1 + rand() % (n * (n - 1) / 2 - n + 1);
    
    cout << n << " " << m << "\n";
    set<pair<int,int>> edges;
    while ((int)edges.size() < m) {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        if (u != v) edges.insert(minmax(u, v));
    }
    for (auto [u, v] : edges)
        cout << u << " " << v << "\n";
}
