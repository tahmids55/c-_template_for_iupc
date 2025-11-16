#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int n = 10, m = 20;
    cout << n << " " << m << "\n";
    set<pair<int,int>> edges;
    while ((int)edges.size() < m) {
        int u = rand() % n + 1, v = rand() % n + 1;
        if (u != v) edges.insert(minmax(u,v));
    }
    for (auto [u, v] : edges)
        cout << u << " " << v << " " << (rand() % 100 + 1) << "\n";
}
