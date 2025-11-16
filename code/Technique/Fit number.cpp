#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

bool can(int64 R, int64 C, const vector<int64>& a) {
    int64 total = 0;
    bool has3 = false;
    for (auto v : a) {
        int64 cnt = v / C;
        if (cnt >= 2) {
            total += cnt;
            if (cnt >= 3) has3 = true;
        }
    }
    if (total < R) return false;
    if ((R & 1) && !has3) return false; 
    return true;
}

void solve() {
    int64 n, m, k;
    cin >> n >> m >> k;
    vector<int64> a(k);
    for (auto &x : a) cin >> x;
    cout << (can(n, m, a) || can(m, n, a) ? "Yes\n" : "No\n");
}
